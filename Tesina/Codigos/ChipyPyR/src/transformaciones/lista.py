import numpy as np
import matplotlib.pyplot as plt

def agrupar_lista(datos : list, grupos : list) -> dict:
    """
    Agrupa una lista de datos según una lista de grupos.

    :param datos: Lista de datos.
    :type datos: list
    :param grupos: Lista de grupos.
    :type grupos: list
    :return: Diccionario con los datos agrupados por grupo.
    :rtype: dict
    """
    dic_lista_por_grupo = {}

    for grupo, dato in zip(grupos, datos):
        if grupo in dic_lista_por_grupo:
            dic_lista_por_grupo[grupo].append(dato)
        else:
            dic_lista_por_grupo[grupo] = [dato]
    
    return dic_lista_por_grupo

def grupos2color(grupos : list) -> list:
    """
    Asigna un color a cada grupo.

    :param grupos: Lista de grupos.
    :type grupos: list
    :return: Lista de colores.
    :rtype: list
    """
    grupos_unicos = list(set(grupos))

    mapa_color = plt.get_cmap('jet')

    colores = mapa_color(np.linspace(0, 1, len(grupos_unicos)))

    grupo_a_color = {grupos_unicos[i]: colores[i] for i in range(len(grupos_unicos))}

    colores_por_grupo = [grupo_a_color[grupo] for grupo in grupos]

    return colores_por_grupo