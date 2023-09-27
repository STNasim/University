import pandas as pd

def leer_lista(archivo):
    with open(archivo) as f:
        lista = f.readlines()
    lista = [x.strip() for x in lista]
    return lista

def filtrar_dataframe(df, lista):
    df_filtrado = df[df['symbol'].isin(lista)]
    return df_filtrado

expresados_pos = leer_lista('expresados_pos.txt')

expresados_neg = leer_lista('expresados_neg.txt')

df = pd.read_csv('resultados/resultado_final_ambos.tsv', sep = '\t', header = 0)

df_pos = filtrar_dataframe(df, expresados_pos)
df_neg = filtrar_dataframe(df, expresados_neg)

df_pos.to_csv('resultados/resultado_final_pos.tsv', sep = '\t', index = False)
df_neg.to_csv('resultados/resultado_final_neg.tsv', sep = '\t', index = False)