from abc import ABC, abstractmethod
import os
import pandas as pd

class CargadorArchivosBase(ABC):
    """
    Clase abstracta que define el comportamiento de un cargador de archivos.
    """
 
    def _validar(self, ruta_archivo: str) -> bool:
        """
        Valida que el archivo en la ruta especificada sea un archivo válido.

        :param ruta_archivo: Ruta del archivo a validar.
        :type ruta_archivo: str
        :return: True si el archivo es válido, False en caso contrario.
        :rtype: bool
        """
        return self._validar_existencia(ruta_archivo) \
            and self._validar_tsv(ruta_archivo) \
            and self._validar_datos(ruta_archivo)
    
    def _validar_existencia(self, ruta_archivo: str) -> bool:
        """
        Valida que el archivo en la ruta especificada exista.

        :param ruta_archivo: Ruta del archivo a validar.
        :type ruta_archivo: str
        :return: True si el archivo existe, False en caso contrario.
        :rtype: bool
        """
        if os.path.exists(ruta_archivo):
            return True
        else:
            raise ValueError('El archivo '+ self._obtener_nombre_archivo(ruta_archivo) +' no existe')

    def _validar_tsv(self, ruta_archivo: str) -> bool:
        """
        Valida que el archivo en la ruta especificada sea un archivo TSV.

        :param ruta_archivo: Ruta del archivo a validar.
        :type ruta_archivo: str
        :return: True si el archivo es un TSV, False en caso contrario.
        :rtype: bool
        """
        with open(ruta_archivo, 'r') as f:
            #leer todas lineas y si no hay un \t en alguna, no es un tsv
            if not all('\t' in linea for linea in f.readlines()):
                    raise ValueError('El archivo '+ self._obtener_nombre_archivo(ruta_archivo) +
                                      ' no es un TSV')
        return True

    def _obtener_nombre_archivo(self, ruta_archivo: str) -> str:
        """
        Obtiene el nombre del archivo de la ruta especificada.

        :param ruta_archivo: Ruta del archivo.
        :type ruta_archivo: str
        :return: Nombre del archivo.
        :rtype: str
        """
        os.path.normpath(ruta_archivo)
        return ruta_archivo.split('/')[-1].split('\\')[-1].split('.')[0]
 
    @abstractmethod
    def _validar_datos(self, ruta_archivo: str) -> bool:
        """
        Valida que los datos del archivo en la ruta especificada sean válidos.

        :param ruta_archivo: Ruta del archivo a validar.
        :type ruta_archivo: str
        :return: True si los datos son válidos, False en caso contrario.
        :rtype: bool
        """
        pass

    @abstractmethod
    def cargar_lista_archivos(self, ruta_archivos : list) -> pd.DataFrame:
        """
        Carga los archivos especificados en la lista.

        :param ruta_archivos: Lista de rutas de los archivos a cargar.
        :type ruta_archivos: list
        :return: DataFrame con los datos de los archivos.
        :rtype: pd.DataFrame
        """
        pass
   
class CargadorArchivosMAGETAB(CargadorArchivosBase):
    """
    Clase que permite cargar los archivos MAGETAB.
    """
    def _validar_datos(self, ruta_archivo: str) -> bool:
        """
        Valida que los datos del archivo en la ruta especificada sean válidos.

        :param ruta_archivo: Ruta del archivo a validar.
        :type ruta_archivo: str
        :return: True si los datos son válidos, False en caso contrario.
        :rtype: bool
        """
        #Para saber si un archivo es un MAGETAB, se debe verificar 
        # que la primer linea contenga la cabecera "SourceName"
        with open(ruta_archivo, 'r') as archivo:
            primera_linea = archivo.readline().split('\t')
            primera_linea = [dato.lower().replace(' ', '') for dato in primera_linea]
            if 'sourcename' in primera_linea:
                return True
            else:
                raise ValueError('El archivo '+ self._obtener_nombre_archivo(ruta_archivo) + ' no es un MAGETAB')
    
    def cargar_lista_archivos(self, ruta_archivos : list) -> pd.DataFrame:
        """
        Carga los archivos especificados en la lista.

        :param ruta_archivos: Lista de rutas de los archivos a cargar.
        :type ruta_archivos: list
        :return: DataFrame con los datos de los archivos.
        :rtype: pd.DataFrame
        """
        if self._validar(ruta_archivos[0]):
            return pd.read_csv(ruta_archivos[0], sep='\t')

class CargadorArchivosMuestras(CargadorArchivosBase):
    """
    Clase que permite cargar los archivos de las muestras.
    """
    def _validar_datos(self, ruta_archivo: str) -> bool:
        """
        Valida que los datos del archivo en la ruta especificada sean válidos.

        :param ruta_archivo: Ruta del archivo a validar.
        :type ruta_archivo: str
        :return: True si los datos son válidos, False en caso contrario.
        :rtype: bool        
        """
        #Leer la primer linea y verificar que tenga al menos dos columnas
        with open(ruta_archivo, 'r') as archivo:
            primera_linea = archivo.readline().split('\t')
            if len(primera_linea) < 2:
                raise ValueError('El archivo '+ self._obtener_nombre_archivo(ruta_archivo) + ' no es un archivo de muestras')
        return True

    def cargar_lista_archivos(self, lista_ruta_archivos: list) -> pd.DataFrame:
        """
        Carga los archivos especificados en la lista.

        :param lista_ruta_archivos: Lista de rutas de los archivos a cargar.
        :type lista_ruta_archivos: list
        :return: DataFrame con los datos de los archivos.
        :rtype: pd.DataFrame
        """
        
        datos = pd.read_csv(lista_ruta_archivos[0], sep = '\t', usecols=[0,1])
        #Convertir los valores de la primer columna en string y la segunda valores numericos
        datos.iloc[:, 0] = datos.iloc[:, 0].astype(str)
        datos.iloc[:, 1] = pd.to_numeric(datos.iloc[:, 1], errors='coerce')

        datos.columns = ["id_sonda", self._obtener_nombre_archivo(lista_ruta_archivos[0])]
        referencia = datos.iloc[:, 0]

        for ruta_archivo in lista_ruta_archivos[1:]:
            if self._validar(ruta_archivo):
                datos_a_agregar = pd.read_csv(ruta_archivo, sep='\t', usecols=[0,1])
                datos_a_agregar.iloc[:, 0] = datos_a_agregar.iloc[:, 0].astype(str)
                datos_a_agregar.iloc[:, 1] = pd.to_numeric(datos_a_agregar.iloc[:, 1], errors='coerce')

                if not datos_a_agregar.iloc[:, 0].equals(referencia):
                    raise ValueError("Los archivos tienen diferente cantidad de sondas o no están ordenados igual")
                
                datos.insert(len(datos.columns), self._obtener_nombre_archivo(ruta_archivo), datos_a_agregar.iloc[:, 1])

        return datos

class CargadorArchivosResultados(CargadorArchivosBase):
    """
    Clase que permite cargar los archivos de resultados.
    """
    def _validar_datos(self, ruta_archivo: str) -> bool:
        """
        Valida que los datos del archivo en la ruta especificada sean válidos.

        :param ruta_archivo: Ruta del archivo a validar.
        :type ruta_archivo: str
        :return: True si los datos son válidos, False en caso contrario.
        :rtype: bool
        """
        #Leer la primer linea y verificar que al menos alguna columna contenga "vs", "adj-p-value" y "log2FC"
        with open(ruta_archivo, 'r') as archivo:
            primera_linea = archivo.readline().split('\t')
            if any('vs' in dato for dato in primera_linea) and \
            any('adj-p-value' in dato for dato in primera_linea) and \
                any('log2FC' in dato for dato in primera_linea):
                return True
            else:
                raise ValueError('El archivo '+ self._obtener_nombre_archivo(ruta_archivo) +
                                  ' no es un archivo de resultados')
    
    def cargar_lista_archivos(self, rutas_archivos: list) -> pd.DataFrame:
        """
        Carga los archivos especificados en la lista.

        :param rutas_archivos: Lista de rutas de los archivos a cargar.
        :type rutas_archivos: list
        :return: DataFrame con los datos de los archivos.
        :rtype: pd.DataFrame
        """
        if type(rutas_archivos) is not list:
            raise ValueError("El argumento rutas_archivos debe ser una lista")
        
        if self._validar(rutas_archivos[0]):
            datos_temp = pd.read_csv(rutas_archivos[0], sep='\t', nrows=1)

            # Crear un diccionario que especifique que las columnas que
            #  contienen 'adj-p-value' o 'log2FC' en su nombre deben ser de tipo float
            columnas_float = \
            {col: float for col in datos_temp.columns if 'adj-p-value' in col or 'log2FC' in col}

            # Segunda lectura para obtener los datos con los tipos de datos correctos
            datos = pd.read_csv(rutas_archivos[0], sep='\t', dtype=columnas_float)
        
        for ruta_archivo in rutas_archivos[1:]:
            if self._validar(ruta_archivo):
                datos_temp = pd.read_csv(ruta_archivo, sep='\t', nrows=1)

                columnas_float = \
                {col: float for col in datos_temp.columns if 'adj-p-value' in col or 'log2FC' in col}

                datos_a_agregar = pd.read_csv(ruta_archivo, sep='\t')
                
                # merge the dataframes on the first column
                datos = pd.merge(datos, datos_a_agregar, on = datos.columns[0], how = 'outer')
                datos = CargadorArchivosResultados.__combinar_duplicados(datos)
        
        #reorganizar y que la columna symbol esté segunda
        columnas = list(datos.columns)
        columnas.remove('symbol')
        columnas.insert(1, 'symbol')
        datos = datos[columnas]
        
        return datos
    
    def __combinar_duplicados(df) -> pd.DataFrame:
        """
        Combina las columnas que tienen el mismo nombre.

        :param df: DataFrame a combinar.
        :type df: pd.DataFrame
        :return: DataFrame con las columnas combinadas.
        :rtype: pd.DataFrame
        """
        for column in df.columns:
            if column.endswith('_x') or column.endswith('_y'):
                original_column = column.rstrip('_x').rstrip('_y')
                if original_column + '_x' in df.columns and original_column + '_y' in df.columns:
                    df[original_column] = df[original_column + '_x'].combine_first(df[original_column + '_y'])
                    df.drop([original_column + '_x', original_column + '_y'], axis=1, inplace=True)
        return df

class FabricaCargadoresArchivos:
    """
    Clase que permite crear cargadores de archivos
    """
    @staticmethod
    def crear_cargador_de_archivo(tipo_de_archivo : str) -> CargadorArchivosBase:
        """
        Crea un cargador de archivos del tipo especificado.

        :param tipo_de_archivo: Tipo de cargador de archivo a crear.
        :type tipo_de_archivo: str
        :return: Cargador de archivos del tipo especificado.
        :rtype: CargadorArchivosBase
        """
        tipo_de_archivo = tipo_de_archivo.lower()
        if tipo_de_archivo == 'muestras':
            return CargadorArchivosMuestras()
        elif tipo_de_archivo == 'magetab':
            return CargadorArchivosMAGETAB()
        elif tipo_de_archivo == 'resultados':
            return CargadorArchivosResultados()
        else:
            raise ValueError(f"Tipo de archivo no soportado: {tipo_de_archivo}")