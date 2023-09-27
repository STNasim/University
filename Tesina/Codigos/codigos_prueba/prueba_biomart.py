from Bio import Entrez
import xml.etree.ElementTree as ET

def get_ensembl_mappings(lista_sondas):
    Entrez.email = "nasimtaleb@hotmail.com"
    mapeo = {}
    for sonda in lista_sondas:
        try:
            handle = Entrez.esearch(db="gene", term=sonda)
            record = Entrez.read(handle)
            if len(record["IdList"]) > 0:
                gene_id = record['IdList'][0]
                mapeo[sonda] = gene_id
            else:
                mapeo[sonda] = 'None'
        except Exception as e:
            print(f"No se pudo obtener el mapeo para la sonda {sonda}. Error: {str(e)}")
            mapeo[sonda] = 'Error'
    return mapeo


import pandas as pd
#pandas = pd.read_csv("datos\E-GEOD-50421\GSM1218903_sample_table.txt", sep = "\t")
#pandas = pd.read_csv("datos\E-GEOD-39084\GSM955440_sample_table.txt", sep = "\t")
lista_sondas = ["2609210", "2616957",
             "2391254","3499280","2807653"]
    
#dic_mapeado = get_ensembl_mappings(list(pandas["ID_REF"]))
dic_mapeado = get_ensembl_mappings(lista_sondas)
print(dic_mapeado)