from typing import List, Dict, Tuple

import pandas as pd
import numpy as np

class FiltradorPromediadorDatos():
    """
    Clase que filtra los datos de los genes por error estándar.
    """
    @staticmethod    
    def filtrar_df_por_error_estandar(df : pd.DataFrame, valor_filtro : float,
                                      agregar_info_adicional : bool = False ) -> Tuple[pd.DataFrame, pd.DataFrame]:
        """
        Filtra los datos de los genes por error estándar.

        :param df: DataFrame con los datos de los genes.
        :type df: pd.DataFrame
        :param valor_filtro: Valor del error estándar para filtrar los datos.
        :type valor_filtro: float
        :param agregar_info_adicional: Indica si se agregan columnas adicionales al DataFrame de los datos que no pasaron el filtro, defaults to False.
        :type agregar_info_adicional: bool, optional
        :return: DataFrame con los datos que pasaron el filtro, DataFrame con los datos que no pasaron el filtro.
        :rtype: Tuple[pd.DataFrame, pd.DataFrame]
        """
        # Excluir la columna 0 durante el procesamiento
        df_procesar = df.iloc[:, 1:]
        
        # Cálculo del error estándar para cada fila
        errores = df_procesar.apply(lambda x: np.std(x, ddof=0) / np.sqrt(len(x)), axis=1)
        
        # Cálculo del error estándar como porcentaje
        medias = df_procesar.mean(axis=1)
        errores_porcentaje = errores / medias * 100

        df_pasaron_filtro = df_procesar[errores_porcentaje <= valor_filtro].copy()    
        df_no_pasaron_filtro = df_procesar[errores_porcentaje > valor_filtro].copy()
        
        # Si agregar_info_adicional es Verdadero, agregar columnas adicionales
        if agregar_info_adicional:
            df_no_pasaron_filtro['Media'] = medias[errores_porcentaje > valor_filtro]
            df_no_pasaron_filtro['Error estándar %'] = errores_porcentaje[errores_porcentaje > valor_filtro]

        # Agregar la columna primera columna de nuevo a los dataframes resultantes
        df_pasaron_filtro = df.iloc[:, 0].to_frame().join(df_pasaron_filtro, how = 'right')
        df_no_pasaron_filtro = df.iloc[:, 0].to_frame().join(df_no_pasaron_filtro, how = 'right')
        
        return df_pasaron_filtro, df_no_pasaron_filtro
    
    @staticmethod
    def filtrar_y_juntar_dict_df(datos_por_grupo : dict, error : float,
                                 id : str) -> Tuple[pd.DataFrame, List, Dict]:
        """
        Filtra los datos de los genes por error estándar y los junta en un solo DataFrame.

        :param datos_por_grupo: Diccionario con los datos de los genes agrupados por grupo.
        :type datos_por_grupo: dict
        :param error: Valor del error estándar para filtrar los datos.
        :type error: float
        :param id: Nombre de la columna que contiene el identificador de los genes.
        :type id: str
        :return: DataFrame con los datos que pasaron el filtro, lista con los grupos, diccionario con los datos que no pasaron el filtro.
        :rtype: Tuple[pd.DataFrame, List, Dict]
        """
        #Crea un dataframe vacio para guardar los datos filtrados
        lista_grupos = []
        datos_devolver = pd.DataFrame()
        datos_filtrados = {}
        
        for grupo, lista_datos in datos_por_grupo.items():
            datos_devolver_agregar, datos_filtrados_agregar = \
            FiltradorPromediadorDatos.filtrar_df_por_error_estandar(lista_datos, error, True)

            if datos_devolver.empty:
                datos_devolver = datos_devolver_agregar
            else:
                datos_devolver = datos_devolver.merge(datos_devolver_agregar, how = 'inner', on = id)

            #Agregar una columa a los datos_filtrados_agregar con el nombre del grupo
            datos_filtrados[grupo] = datos_filtrados_agregar

            #Agregar a la lista de grupos el grupo, la cantidad de veces que se repite
            #es la cantidad de columnas excepto la primera
            for i in range(1, len(lista_datos.columns)):
                lista_grupos.append(grupo)

        return datos_devolver, lista_grupos, datos_filtrados