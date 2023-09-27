if __name__ == '__main__':
    procesador = crear_procesador_de_archivo('resultados')
    #datos = procesador.cargar_archivos(['datos/GSM955496_sample_table.txt', 'datos/GSM955468_sample_table.txt'])
    #datos = procesador.cargar_archivo('datos/GSM955496_sample_table.txt')
    #datos = procesador.cargar(['datos/res1_sinteticos.txt'])
    datos = procesador.cargar(['datos/res1_sinteticos.txt','datos/res2_sinteticos.txt','datos/res3_sinteticos.txt'])
    print(datos)