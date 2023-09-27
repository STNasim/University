from abc import ABC, abstractmethod

from PyQt5.QtWebEngineWidgets import QWebEngineView
from PyQt5.QtCore import QUrl
from reactome2py import analysis

class PaginaBase(ABC):
    """
    Clase abstracta que representa una pagina web.
    """
    def __init__(self, datos : list) -> None:
        """
        Inicializa la pagina web.

        :param datos: Datos a mostrar en la pagina
        :type datos: list
        """
        self._datos = datos
        self._vista_web = QWebEngineView()
        self._cargar_vista()

    @abstractmethod
    def _cargar_vista(self) -> None:
        """
        Carga la vista de la pagina.
        """
        pass

    def obtener_vista(self) -> QWebEngineView:
        """
        Devuelve la vista de la pagina.

        :return: Vista de la pagina.
        :rtype: QWebEngineView
        """
        return self._vista_web

class PaginaReactome(PaginaBase):
    """
    Clase que representa una pagina de Reactome.
    """
    def _cargar_vista(self) -> None:
        """
        Carga la vista de la pagina.
        """
        
        string_ids = ",".join(self._datos)
        result = analysis.identifiers(ids = string_ids)
        token = result['summary']['token']

        url = f"https://reactome.org/PathwayBrowser/#/DTAB=AN&ANALYSIS={token}"

        self._vista_web.load(QUrl(url))

class PaginaExpressionAtlas(PaginaBase):
    """
    Clase que representa una pagina de Expression Atlas.
    """
    def _cargar_vista(self) -> None:
        """
        Carga la vista de la pagina.
        """
        url = f"https://www.ebi.ac.uk/gxa/genes/{self._datos[0]}"

        self._vista_web.load(QUrl(url))

class FabricaPaginas():
    """
    Clase que se encarga de crear las paginas web.
    """
    def __init__(self) -> None:     
        """
        Inicializa la fabrica de paginas.
        """   
        self.__paginas_admitidas = ["Reactome","Expression Atlas"]

    def obtener_paginas_admitidas(self) -> list:
        """
        Devuelve las paginas admitidas.

        :return: Paginas admitidas.
        :rtype: list
        """
        return self.__paginas_admitidas
    
    def crear_pagina(self, nombre_pagina : str, datos: list)  -> PaginaBase:
        """
        Crea una pagina web.

        :param nombre_pagina: Nombre de la pagina.
        :type nombre_pagina: str
        :param datos: Datos a mostrar en la pagina.
        :type datos: list
        :return: Pagina web.
        :rtype: PaginaBase
        """
        nombre_pagina = nombre_pagina.lower()
        if nombre_pagina == "reactome":
            return PaginaReactome(datos)
        elif nombre_pagina == "expression atlas":
            return PaginaExpressionAtlas(datos)
        else:
            raise ValueError(f"Tipo de pagina no soportado: {nombre_pagina}")