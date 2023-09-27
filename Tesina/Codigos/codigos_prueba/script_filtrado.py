import os
import pandas as pd

if __name__ == "__main__":
    #si existe en el directorio el archivo sondas_no_mapeables.tsv
    if os.path.isfile("sondas_no_mapeables.tsv"):
        #Leerlo, y guardarlo en una lista
        with open("sondas_no_mapeables.tsv", "r") as f:
            sondas_no_mapeables = f.readlines()
        #Eliminar el salto de linea
        sondas_no_mapeables = [s.rstrip("\n") for s in sondas_no_mapeables]
        #Eliminar el encabezado
        sondas_no_mapeables = sondas_no_mapeables[1:]
        #hacer los valores numeros
        sondas_no_mapeables = [int(s) for s in sondas_no_mapeables]

    lista_ruta_archivos = os.listdir()
    for archivo in lista_ruta_archivos.copy():
        if not archivo.endswith("_sample_table.txt"):
            lista_ruta_archivos.remove(archivo)

    datos = pd.read_csv(lista_ruta_archivos[0], sep = '\t', usecols=[0,1])

    datos.columns = ["id_sonda", lista_ruta_archivos[0].split("_")[0]]

    for ruta_archivo in lista_ruta_archivos[1:]:
        datos_a_agregar = pd.read_csv(ruta_archivo, sep='\t', usecols=[0,1])
        datos_a_agregar.columns = ["id_sonda", ruta_archivo.split("_")[0]]

        datos.insert(len(datos.columns), ruta_archivo.split("_")[0], datos_a_agregar.iloc[:, 1])


    #quitar las filas cuyo id_sonda este en la lista de sondas no mapeables
    datos = datos[~datos["id_sonda"].isin(sondas_no_mapeables)]

    #para cada columna aparte de la primera, guardar un archivo con el nombre de la columna+_sample_table_fil.txt
    # y que contenga el id_sonda y el valor de la columna
    for columna in datos.columns[1:]:
        datos[[datos.columns[0], columna]].to_csv(columna+"_sample_table_fil.txt", sep="\t", index=False)

    print("Finalizado")