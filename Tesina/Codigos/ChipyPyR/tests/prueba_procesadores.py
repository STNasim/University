#Enriquecedor

if __name__ == "__main__":
    pandas = {"gen_id": ["ENSG00000204580", "ENSG00000146678", "ENSG00000117009"],
              "prueba": [1,2,3]}
    pandas = pd.DataFrame(pandas)
    resultados = Enriquecedor.obtener_datos_enriquecidos(pandas["gen_id"].tolist())
    res = pandas.merge(resultados, left_on="gen_id", right_on="query", how="left")
    print(res)
    res.to_csv("prueba_enriquecedor.tsv", sep="\t", index=False)
#Filtrador mapeos

if __name__ == "__main__":
    dic_mapeos = {  '1007_s_at': ['ENSG00000204580'],
                    '205302_at': ['ENSG00000146678'],
                    'AFFX-TrpnX-3_at': ['None'],
                    '205306_x_at': ['ENSG00000117009'],
                    'AFFX-CreX-5_at': ['None'],
                    'AFFX-HUMRGE/M10098_5_at': ['ENSG00000264063', 'ENSG00000264462',
                                                'ENSG00000275708', 'ENSG00000277437']}
    lista_no_mapeadas = FiltradorMapeos.quitar_y_obtener_lista_no_mappers(dic_mapeos)
    print("Lista de sondas no mapeadas: ")
    print(lista_no_mapeadas)
    print("Diccionario de sondas mapeadas: ")
    print(dic_mapeos)

    lista_multimappers = FiltradorMapeos.quitar_y_obtener_lista_multimappers(dic_mapeos)
    print("Lista de sondas multimapeadas: ")
    print(lista_multimappers)
    print("Diccionario de sondas mapeadas: ")
    print(dic_mapeos)

#Filtrador promediador datos

if __name__ == "__main__":
    datos = {
    'Sample': ['Gen1', 'Gen2', 'Gen3', 'Gen4', 'Gen5', 'Gen6', 'Gen7'],
    'Muestra1': [62, 47, 55, 74, 31, 77, 85],
    'Muestra2': [60, 87, 67, 55, 47, 72, 76],
    'Muestra3': [56, 86, 77, 45, 73, 62, 74]
            }
    datos = pd.DataFrame(datos)
    datos, datos_filtrados = FiltradorPromediadorDeDatos.filtrar_por_error_estandar(datos, 10, True)
    print("datos")
    print(datos)
    print("datos filtrados")
    print(datos_filtrados)

#Mapeador sondas

if __name__ == "__main__":
    import pandas as pd
    pandas = pd.read_csv("datos\E-GEOD-50421\GSM1218903_sample_table.txt", sep = "\t")
    #pandas = pd.read_csv("datos\E-GEOD-39084\GSM955440_sample_table.txt", sep = "\t")
    lista_sondas = ["3579063","3478396", "3320558",
             "4125242","2653228","2321847"]
    
    dic_mapeado = MapeadorSondas.obtener_sondas_mapeadas(list(pandas["ID_REF"]))
    #dic_mapeado = MapeadorSondas.obtener_sondas_mapeadas(lista_sondas)
    #print(dic_mapeado)
    #guardar el diccionario en un archivo
    dic_mapeado = pd.DataFrame(dic_mapeado, index = ["id_gen"])
    dic_mapeado.to_csv("dic_mapeado.tsv", sep = "\t", index = True)