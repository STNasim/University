import pandas as pd
import os

from manejadores_archivos.cargadores_archivos import FabricaCargadoresArchivos
from manejadores_archivos.guardador_archivos import GuardadorArchivos
from manejadores_archivos.buscador_archivos import BuscadorArchivos
from procesadores_datos.filtrador_promediador_datos import FiltradorPromediadorDatos
from transformaciones.lista import agrupar_lista
from transformaciones.df import separar_df_grupo, explotar_agrupar_columna_lista, columna2columna
from visualizacion.reportes import FabricaReportes
from procesadores_datos.mapeo import MapeadorSondas, FiltradorMapeos
from scripts_R.limma_rpy2 import LimmaRPY2
from procesadores_datos.enriquecedor import Enriquecedor

class Pipeline():
    """
    Clase que se encarga de procesar los datos.

    """
    def __init__(self, ruta : str, muestras : list, grupos : list, grupo_control : str, error_sondas : float,
                  error_genes : float, quitar_multimappers : bool, espacio_numerico : str) -> None:
        """
        Constructor de la clase.

        :param ruta: Ruta de la carpeta que contiene los archiv
        :type ruta: str
        :param muestras: Lista con los nombres de las muestras.
        :type muestras: list
        :param grupos: Lista con los nombres de los grupos.
        :type grupos: list
        :param grupo_control: Nombre del grupo control.
        :type grupo_control: str
        :param error_sondas: Valor del error estándar para filtrar las sondas.
        :type error_sondas: float
        :param error_genes: Valor del error estándar para filtrar los genes.
        :type error_genes: float
        :param quitar_multimappers: Indica si se deben quitar las multimappers.
        :type quitar_multimappers: bool
        :param espacio_numerico: Espacio numérico para mapear las sondas.
        :type espacio_numerico: str
        """
        self.__ruta_carpeta_muestras = ruta
        self.__ruta_carpeta_resultados = os.path.join(ruta,"resultados")
        if not os.path.exists(self.__ruta_carpeta_resultados):
            os.makedirs(self.__ruta_carpeta_resultados)
        
        self.__muestras = muestras
        self.__grupos = grupos
        self.__grupo_control = grupo_control
        self.__error_sondas = error_sondas
        self.__error_genes = error_genes
        self.__quitar_multimappers = quitar_multimappers
        self.__datos_cada_etapa = {}
        self.__datos_por_grupo = {}
        self.__espacio_numerico = espacio_numerico

    def obtener_figuras_reporte_muestras(self) -> list:
        """
        Obtiene la lista de figuras del reporte de muestras.

        :return: Lista de figuras del reporte de muestras.
        :rtype: list
        """
        return self.__figuras_reporte_muestras
    
    def obtener_figuras_reporte_limma(self) -> list:
        """
        Obtiene la lista de figuras del reporte de limma.

        :return: Lista de figuras del reporte de limma.
        :rtype: list
        """
        return self.__figuras_reporte_limma

    def obtener_datos_cada_etapa(self) -> dict:
        """
        Obtiene los datos de cada etapa del procesamiento.

        :return: Datos de cada etapa del procesamiento.
        :rtype: dict
        """
        return self.__datos_cada_etapa

    def cargar_muestras(self) -> None:
        """
        Carga los datos de las muestras.
        """
        ruta_muestras = BuscadorArchivos.buscar_rutas(self.__ruta_carpeta_muestras, self.__muestras)

        muestras_por_grupo = agrupar_lista(ruta_muestras, self.__grupos)

        cargador_muestras = FabricaCargadoresArchivos.crear_cargador_de_archivo("muestras")
        
        for grupo, rutas in muestras_por_grupo.items():
            self.__datos_por_grupo[grupo] = \
            cargador_muestras.cargar_lista_archivos(rutas)
        
    def procesar_muestras(self) -> None:
        """
        Procesa los datos de las muestras. Filtra los datos por error estándar y los junta en un solo DataFrame.
        """
                                             
        self.__datos, self.__grupos, datos_filtrados = \
        FiltradorPromediadorDatos.filtrar_y_juntar_dict_df(self.__datos_por_grupo,
                                                           self.__error_sondas, 'id_sonda')

        for grupo, datos in datos_filtrados.items():
            self.__datos_cada_etapa[f"Sondas de error alto en {grupo}"] = len(datos)
            GuardadorArchivos.guardar_pandas(datos,os.path.join(self.__ruta_carpeta_resultados,
                                                           f"sondas_error_alto_{grupo}.tsv"))

    def generar_reporte_muestras(self) -> None:
        """
        Genera el reporte de calidad de las muestras.
        """
        reporte_muestras = FabricaReportes.crear_reporte("sondas",self.__datos,
                                                        self.__grupos)
        
        self.__figuras_reporte_muestras = reporte_muestras.obtener_lista_figuras()

    def procesar_sondas(self) -> None:
        """
        Procesa los datos de las sondas. Mapea las sondas con sus respectivos genes y filtra los resultados.
        """
        mapeos = MapeadorSondas.obtener_sondas_mapeadas(list(self.__datos["id_sonda"]),
                                                             self.__espacio_numerico)
        lista_no_mapeables = FiltradorMapeos.quitar_y_obtener_lista_no_mappers(mapeos)
        self.__datos_cada_etapa["Sondas no mapeables"] = len(lista_no_mapeables)
        
        GuardadorArchivos.guardar_lista(lista_no_mapeables, 
                                        os.path.join(self.__ruta_carpeta_resultados,"sondas_no_mapeables.tsv"))

        if self.__quitar_multimappers:
            mapeos_copia = mapeos.copy()

            multimappers = FiltradorMapeos.quitar_y_obtener_lista_multimappers(mapeos)

            self.__datos_cada_etapa["Sondas multimappers"] = len(multimappers)

            multimappers = pd.DataFrame(multimappers, columns = ["id_sonda"])
            multimappers["id_gen"] = multimappers["id_sonda"].map(mapeos_copia)
            GuardadorArchivos.guardar_pandas(multimappers,
                                              os.path.join(self.__ruta_carpeta_resultados,"sondas_multimappers.tsv"))
        
        #se mapean los datos de sondas con sus respectivos genes
        self.__datos = columna2columna(self.__datos, mapeos, "id_sonda", "id_gen")

    def procesar_genes(self) -> None:
        """
        Procesa los datos de los genes. Filtra los datos por error estándar y los junta en un solo DataFrame.
        """
        #Ya que contiene una lista con varios genes en algunos casos, hay que separar la fila
        #  en varias filas, una por cada gen
        self.__datos = explotar_agrupar_columna_lista(self.__datos, "id_gen")
        
        self.__datos_por_grupo = separar_df_grupo(self.__datos, self.__grupos)

        self.__datos, self.__grupos, datos_filtrados = \
        FiltradorPromediadorDatos.filtrar_y_juntar_dict_df(self.__datos_por_grupo, self.__error_genes, 'id_gen')

        GuardadorArchivos.guardar_pandas(self.__datos,
                                          os.path.join(self.__ruta_carpeta_resultados,"datos_limpios.tsv"))

        for grupo, datos in datos_filtrados.items():
            self.__datos_cada_etapa[f"Genes de error alto en {grupo}"] = len(datos)
            GuardadorArchivos.guardar_pandas(datos,os.path.join(self.__ruta_carpeta_resultados,
                                                           f"genes_error_alto_{grupo}.tsv"))
        
    def calcular_expresion(self) -> None:
        """
        Calcula la expresión de los genes.
        """
        self.__datos = LimmaRPY2.correr_script_rpy2(self.__datos, self.__grupos, self.__grupo_control)

    def generar_reporte_limma(self) -> None:
        """
        Genera el reporte de limma.
        """
        reporte_limma = FabricaReportes.crear_reporte("limma",self.__datos.iloc[:,1:], self.__grupos)
        
        self.__figuras_reporte_limma = reporte_limma.obtener_lista_figuras()

    def enriquecer_datos(self) -> None:
        """
        Enriquece los datos con información adicional.
        """

        datos_enriquecidos = Enriquecedor.obtener_datos_enriquecidos(self.__datos.iloc[:,0].to_list())

        self.__datos = self.__datos.merge(datos_enriquecidos, how = 'left',
                                           left_on = 'id_gen', right_on = 'query')
        self.__datos = self.__datos.drop('query', axis = 1)
        #colocar la columna symbol segunda
        cols = list(self.__datos.columns)
        cols.insert(1, cols.pop(cols.index('symbol')))
        self.__datos = self.__datos.loc[:,cols]

    def guardar_datos(self) -> None:
        """
        Guarda los datos finales.
        """
        #como ya se generó el reporte de limma, si fue necesario, 
        # se pueden quitar las columnas que comience con t_
        self.__datos = self.__datos.loc[:,~self.__datos.columns.str.startswith('t_')]
        self.__datos_cada_etapa["Datos finales"] = len(self.__datos)
        GuardadorArchivos.guardar_pandas(self.__datos,
                                         os.path.join(self.__ruta_carpeta_resultados,"resultado_final.tsv"))