import pandas as pd

def separar_df_grupo(df : pd.DataFrame, lista_grupos : list) -> dict:
    """
    Separa un dataframe en varios dataframes según los grupos.

    :param df: Dataframe a separar.
    :type df: pd.DataFrame
    :param lista_grupos: Lista con los nombres de los grupos.
    :type lista_grupos: list
    :return: Diccionario con los dataframes separados por grupo.
    :rtype: dict
    """
    dict_df_por_grupo = {}

    for grupo in set(lista_grupos):
        dict_df_por_grupo[grupo] = df.iloc[:, [0] + [i+1 for i, x in enumerate(lista_grupos) if x == grupo]]

    return dict_df_por_grupo

def explotar_agrupar_columna_lista(df : pd.DataFrame, columna : str) -> pd.DataFrame:
    """
    Explota una columna que contiene listas y agrupa por esa columna.

    :param df: Dataframe a explotar y agrupar.
    :type df: pd.DataFrame
    :param columna: Nombre de la columna a explotar y agrupar.
    :type columna: str
    :return: Dataframe agrupado por la columna
    :rtype: pd.DataFrame
    """
    df = df.explode(columna)

    df = df.groupby(columna).median().reset_index()

    return df

def columna2columna(df : pd.DataFrame, dic_mapeos : dict, columna_desde : str,
                     columna_hacia : str) -> pd.DataFrame:       
    """
    Mapea los valores de una columna a otra columna.
    
    :param df: Dataframe a mapear.
    :type df: pd.DataFrame
    :param dic_mapeos: Diccionario con los mapeos.
    :type dic_mapeos: dict
    :param columna_desde: Nombre de la columna desde donde se mapea.
    :type columna_desde: str
    :param columna_hacia: Nombre de la columna hacia donde se mapea.
    :type columna_hacia: str
    :return: Dataframe mapeado.
    :rtype: pd.DataFrame
    """
    df.insert(1, columna_hacia, df[columna_desde].map(dic_mapeos))

    df = df.drop(columna_desde, axis = 1)
        
    df = df.dropna()

    return df

def anular_valores_mayores_columna(df : pd.DataFrame,
                                    comienzo_columna : str, umbral : float) -> pd.DataFrame:
    """
    Anula los valores mayores a un umbral de las columnas que empiezan con un string.

    :param df: Dataframe a anular.
    :type df: pd.DataFrame
    :param comienzo_columna: String con el que empiezan las columnas a anular.
    :type comienzo_columna: str
    :param umbral: Umbral a partir del cual se anulan los valores.
    :type umbral: float
    :return: Dataframe con los valores anulados.
    :rtype: pd.DataFrame
    """
    columnas = [col for col in df.columns if col.startswith(comienzo_columna)]

    for col in columnas:
        df.loc[df[col] > umbral, col] = None

    return df

def anular_valores_menores_absoluto_columna(df : pd.DataFrame,
                                             comienzo_columna : str, umbral : float) -> pd.DataFrame: 
    """
    Anula los valores menores a un umbral de las columnas que empiezan con un string.

    :param df: Dataframe a anular.
    :type df: pd.DataFrame
    :param comienzo_columna: String con el que empiezan las columnas a anular.
    :type comienzo_columna: str
    :param umbral: Umbral a partir del cual se anulan los valores.
    :type umbral: float
    :return: Dataframe con los valores anulados.
    :rtype: pd.DataFrame
    """
    columnas = [col for col in df.columns if col.startswith(comienzo_columna)]

    for col in columnas:
        df.loc[abs(df[col]) < umbral, col] = None

    return df

def quitar_filas_menores_absoluto_columna(df : pd.DataFrame,
                                           comienzo_columna : str, umbral : float) -> pd.DataFrame:
    """
    Quita las filas que tienen todos los valores menores a un umbral de las columnas que empiezan con un string.

    :param df: Dataframe a quitar filas.
    :type df: pd.DataFrame
    :param comienzo_columna: String con el que empiezan las columnas a quitar filas.
    :type comienzo_columna: str
    :param umbral: Umbral a partir del cual se quitan las filas.
    :type umbral: float
    :return: Dataframe con las filas quitadas.
    :rtype: pd.DataFrame
    """
    indices_para_eliminar = []
    columnas = [col for col in df.columns if col.startswith(comienzo_columna)]

    for index, row in df.iterrows():
        if all(abs(row[col]) < umbral for col in columnas):
            indices_para_eliminar.append(index)

    df = df.drop(indices_para_eliminar)

    return df

def quitar_filas_mayores_columna(df : pd.DataFrame,
                                  comienzo_columna : str, umbral : float) -> pd.DataFrame:
    """
    Quita las filas que tienen todos los valores mayores a un umbral de las columnas que empiezan con un string.

    :param df: Dataframe a quitar filas.
    :type df: pd.DataFrame
    :param comienzo_columna: String con el que empiezan las columnas a quitar filas.
    :type comienzo_columna: str
    :param umbral: Umbral a partir del cual se quitan las filas.
    :type umbral: float
    :return: Dataframe con las filas quitadas.
    :rtype: pd.DataFrame
    """
    indices_para_eliminar = []
    columnas = [col for col in df.columns if col.startswith(comienzo_columna)]

    for index, row in df.iterrows():
        if all(row[col] > umbral for col in columnas):
            indices_para_eliminar.append(index)

    df = df.drop(indices_para_eliminar)

    return df