import pandas as pd

class GuardadorArchivos:
    """
    Clase que permite guardar archivos en disco.
    """
    @staticmethod
    def guardar_pandas(df : pd.DataFrame, ruta : str) -> bool:
        """
        Guarda un DataFrame en un archivo de texto.
        
        :param df: DataFrame a guardar.
        :type df: pd.DataFrame
        :param ruta: Ruta del archivo de texto.
        :type ruta: str
        :return: True si se guardó correctamente, False en caso contrario.
        :rtype: bool
        """
        df.to_csv(ruta, sep = '\t', index = False)
        return True

    @staticmethod
    def guardar_lista(lista : list, ruta : str) -> bool:
        """
        Guarda una lista en un archivo de texto.

        :param lista: Lista a guardar.
        :type lista: list
        :param ruta: Ruta del archivo de texto.
        :type ruta: str
        :return: True si se guardó correctamente, False en caso contrario.
        :rtype: bool
        """
        with open(ruta, "w") as archivo:
            for elemento in lista:
                archivo.write(elemento + '\n')
        return True
        