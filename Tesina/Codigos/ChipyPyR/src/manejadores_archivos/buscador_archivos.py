import os

class BuscadorArchivos():
    """
    Clase que permite buscar archivos en un directorio.
    """
    @staticmethod
    def buscar_rutas(ruta_directorio : str, nombres : list[str]) -> list:
        """
        Busca los archivos que contengan los nombres dados en la ruta dada.

        :param ruta_directorio: Ruta del directorio donde se buscarán los archivos.
        :type ruta_directorio: str
        :param nombres: Lista de nombres de los archivos a buscar.
        :type nombres: list
        """
        rutas = []

        #Extrar los nombres de todos los archivos en ruta
        archivos = os.listdir(ruta_directorio)

        #Verificar si hay archivos que contengan el nombre de cada muestra en su nombre
        for nombre in nombres:
            for archivo in archivos:
                if nombre.lower() in archivo.lower():
                    rutas.append(os.path.join(ruta_directorio, archivo))
                    break
            else:
                raise ValueError("No se encontró el archivo " + nombre)
        return rutas