import pandas as pd
import mygene

class Enriquecedor:
    """
    Clase que enriquece los datos de los genes con información de MyGeneInfo . 
    """
    @staticmethod
    def obtener_datos_enriquecidos(genes : list) -> pd.DataFrame:
        """
        Enriquece los datos de los genes con información de MyGeneInfo.

        :param genes: Lista de genes.
        :type genes: list
        :return: DataFrame con los datos enriquecidos.
        :rtype: pd.DataFrame
        """
        mg = mygene.MyGeneInfo()
        salida = mg.querymany(genes, scopes = 'ensembl.gene',
                            fields = 'symbol, pathway.reactome, go.BP.term, go.MF.term, go.CC.term',
                              species = 'human')
        for gen in salida:
            if 'pathway' in gen and 'reactome' in gen['pathway']:
                gen['vias_reactome'] = ', '.join(set([path['name'] for path in gen['pathway']['reactome'] if isinstance(path, dict)]))

            if 'go' in gen:
                if 'BP' in gen['go']:
                    gen['BP'] = ', '.join(set([term['term'] for term in gen['go']['BP'] if isinstance(term, dict)]))
                if 'MF' in gen['go']:
                    gen['MF'] = ', '.join(set([term['term'] for term in gen['go']['MF'] if isinstance(term, dict)]))
                if 'CC' in gen['go']:
                    gen['CC'] = ', '.join(set([term['term'] for term in gen['go']['CC'] if isinstance(term, dict)]))

        df = pd.DataFrame(salida)

        columnas_a_quitar = set(['_id', '_score', 'pathway', 'go','notfound']) & set(df.columns)
        df.drop(columnas_a_quitar, axis=1, inplace=True)

        return df
