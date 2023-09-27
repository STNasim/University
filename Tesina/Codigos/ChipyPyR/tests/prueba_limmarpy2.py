if __name__ == "__main__":
    import pandas as pd
    datos = pd.read_csv("datos/agrupado3_datos.tsv", sep = "\t")
    grupos = ["tratamiento2","control","tratamiento","tratamiento","control","tratamiento2","tratamiento",
              "tratamiento2","control","tratamiento2","control","tratamiento","control","tratamiento"]
    datos.set_index(datos.columns[0], inplace=True)
    print(LimmaRPY2.correr_script_rpy2(datos, "control", grupos))