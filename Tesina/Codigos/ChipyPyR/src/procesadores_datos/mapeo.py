from gprofiler import GProfiler

class MapeadorSondas:
    """
    Clase que se encarga de mapear las sondas a genes.
    """
    @staticmethod
    def obtener_sondas_mapeadas(sondas : list, espacio_numerico : str = 'AFFY_HUEX_1_0_ST_V2') -> dict:
        """
        Obtiene las sondas mapeadas a genes.

        :param sondas: Lista de sondas.
        :type sondas: list
        :param espacio_numerico: Espacio numérico de las sondas, defaults to 'AFFY_HUEX_1_0_ST_V2'
        :type espacio_numerico: str, optional
        :return: Diccionario con las sondas mapeadas a genes.
        :rtype: dict
        """
        gp = GProfiler(return_dataframe = True)
        resultado = gp.convert(query = sondas, target_namespace = 'ENSG', 
                               organism = 'hsapiens', numeric_namespace = espacio_numerico)
        
        mapeo = {}
        for sonda, genes in zip(resultado['incoming'], resultado['converted']):
            if sonda not in mapeo:
                mapeo[sonda] = []            
            mapeo[sonda].append(genes)

        return mapeo
    
class FiltradorMapeos:
    """
    Clase que se encarga de filtrar los mapeos de las sondas a genes.
    """
    @staticmethod
    def quitar_y_obtener_lista_no_mappers(mapeos : dict) -> list:
        """
        Quita los mapeos de las sondas que no se pudieron mapear a ningún gen.

        :param mapeos: Diccionario con las sondas mapeadas a genes.
        :type mapeos: dict
        :return: Lista con las sondas que no se pudieron mapear a ningún gen.
        :rtype: list
        """

        no_mapeadas = []
        for sonda, genes in mapeos.items():
            if genes == ["None"]:
                no_mapeadas.append(sonda)

        #Si bien no es lo más eficiente, es recomendable no modificar
        #un diccionario mientras se itera sobre él
        for sonda in no_mapeadas:
            mapeos.pop(sonda)

        return no_mapeadas
    
    @staticmethod
    def quitar_y_obtener_lista_multimappers(mapeos) -> list:
        """
        Quita los mapeos de las sondas que se mapearon a más de un gen.

        :param mapeos: Diccionario con las sondas mapeadas a genes.
        :type mapeos: dict
        :return: Lista con las sondas que se mapearon a más de un gen.
        :rtype: list
        """
        multimappers = []
        for sonda, genes in mapeos.items():
            if len(genes) > 1:
                multimappers.append(sonda)
                
        for sonda in multimappers:
            mapeos.pop(sonda)

        return multimappers