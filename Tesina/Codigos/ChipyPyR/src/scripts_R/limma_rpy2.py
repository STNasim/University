from scripts_R.set_R import set_r
set_r()

import pandas as pd

import rpy2.robjects as robjects
from rpy2.robjects import pandas2ri, StrVector
from rpy2.robjects.conversion import localconverter

class LimmaRPY2:
    """
    Clase que se encarga de ejecutar el script de limma.
    """
    @staticmethod
    def correr_script_rpy2(datos_numericos_con_columna_id : pd.DataFrame,
                            lista_grupos : list, control : str) -> pd.DataFrame:
        """
        Ejecuta el script de limma.

        :param datos_numericos_con_columna_id: Datos numericos con una columna id.
        :type datos_numericos_con_columna_id: pd.DataFrame
        :param lista_grupos: Lista con los nombres de los grupos.
        :type lista_grupos: list
        :param control: Nombre del grupo control.
        :type control: str
        :return: Resultados del script de limma.
        :rtype: pd.DataFrame
        """
        # Convertir el dataframe pandas a un dataframe de R
        datos_numericos_con_columna_id.set_index(datos_numericos_con_columna_id.columns[0], inplace = True)
        with localconverter(robjects.default_converter + pandas2ri.converter):
            r_datos = pandas2ri.py2rpy(datos_numericos_con_columna_id)
        
        r = robjects.r

        r.assign("grupo_control",
                  "Grupo" + control.replace(' ', '_') if control.isdigit() else control.replace(' ', '_'))
        r.assign("grupos",
                  StrVector(["Grupo" + i.replace(' ', '_') if i.isdigit() else i.replace(' ', '_') for i in lista_grupos]))
        r.assign("r_datos", r_datos)

        r('''
# Instalar el paquete limma y sus dependencias si no están instaladas
if (!"BiocManager" %in% rownames(installed.packages()))
    install.packages("BiocManager", method = "curl", dependencies = TRUE)
BiocManager::install("limma", ask = FALSE, dependencies = TRUE, method = "curl")

library("limma")
# Leer datos
datos <- r_datos
filas <- rownames(datos)

# Convertir columnas a numérico
datos <- as.data.frame(lapply(datos, function(x) as.numeric(as.character(x))))
rownames(datos) <- filas
          
datos <- na.omit(datos)

# Preparar los datos para limma
matriz_datos <- as.matrix(datos)
rownames(matriz_datos) <- rownames(datos)
colnames(matriz_datos) <- colnames(datos)

# Crear la matriz de diseño
grupos_factor <- factor(grupos)
diseño <- model.matrix(~0 + grupos_factor)
colnames(diseño) <- levels(grupos_factor)

# Definir los contrastes
nombres_grupos <- colnames(diseño)
nombres_grupos <- nombres_grupos[nombres_grupos != grupo_control]
lista_contraste <- list()
for (grupo in nombres_grupos) {
    lista_contraste <- append(lista_contraste, paste0(grupo, " - ", grupo_control))
}

# Crear la matriz de contrastes
matriz_constraste <- makeContrasts(contrasts = lista_contraste, levels = diseño)

fit <- lmFit(matriz_datos, diseño)

# Obtener los resultados para cada comparación
lista_resultados <- list()
for (grupo in nombres_grupos) {
  fit_contrasts <- contrasts.fit(fit, matriz_constraste[, paste0(grupo, " - ", grupo_control)])
  fit_contrasts <- eBayes(fit_contrasts)
  
  tabla_genes <- topTable(fit_contrasts, adjust = "fdr", sort.by = "B", n = Inf)
          
  # Filtrar la tabla con algunas de las columnas
  resultados <- tabla_genes[, c("logFC", "adj.P.Val","t")]
  
  
  resultados <- data.frame(id_gen = rownames(resultados), resultados)
  colnames(resultados) <- c("id_gen",
                         paste0("log2FC_",grupo,"_vs_",grupo_control),
                         paste0("adj-p-value_",grupo,"_vs_",grupo_control),
                         paste0("t_",grupo,"_vs_",grupo_control))
  
  lista_resultados[[grupo]] <- resultados
}

# Combinar los resultados en un solo dataframe
resultados_combinados <- Reduce(function(x, y) merge(x, y, by = "id_gen"), lista_resultados)
        ''')

        r_resultados = r['resultados_combinados']

        with localconverter(robjects.default_converter + pandas2ri.converter):
            df_resultados = pandas2ri.rpy2py(r_resultados)

        return df_resultados