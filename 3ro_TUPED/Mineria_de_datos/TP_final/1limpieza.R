library(pacman)
p_load(openxlsx)
rm(list = ls())
gc()

#a

datos <- read.xlsx("Assignment-1_Data.xlsx") #3 Warnings, posiblemente los 3 valores con A de BillNo
dim(datos)
str(datos)
summary(datos)
# Se observan valores extraños, como una cantidad negativa y una cantidad inmensamente alta
#Tambien un precio negativo y otro precio excesivamente alto en comparación a los otros datos

colSums(is.na(datos))
#En cuanto a valores NA, Pocos en la variable Itemname, insignificantes en BillNo y una cantidad 
#considerable un cuarto de los datos, en la variable CustomerID

#Primero que nada, se decide eliminar todas las filas dónde la cantidad sea negativa 
#ya que representan operaciones canceladas y no aportan información relevante al analisis

datos <- datos[datos$Quantity >= 0,]

#Tambien se eliminan filas donde no haya un nombre de Item ya que no tiene sentido
#contabilizar una compra para encontrar patrones si no se sabe que se vendió

datos <- datos[!is.na(datos$Itemname), ]

#Tambien las operaciones dónde el precio sea negativo

datos <- datos[datos$Price >= 0,]

#Finalmente, se observan nombres de items extraños en algunas filas como "amazon", "found", "?",
#"check" "had been put aside" que en principio no aportan ninguna información relevante al problema,
#coincidentemente, el precio de esa fila es siempre 0, pero también existen ventas que fueron por 0,
#donde tal vez se regaló un item, por lo cual no se pueden simplemente eliminar todas las de precio 0
#Sin embargo, se obsverga un patrón común, la mayoría tiene al menos una letra en minúscula y
#ninguna mayúscula o el simbolo "?", por lo que, en principio, se podrían borrar gracias a esto, 
#pero primero se debe observar que valores serán los afectados

valores_invalidos <- grepl("^[^A-Z]*[a-z][^A-Z]*$|\\?", datos$Itemname)
lista_valores_invalidos <- datos$Itemname[valores_invalidos]
print(as.character(lista_valores_invalidos))

#Tambien se agregan otros valores que se encontraron como inválidos como "POSTAGE", 
#"DOTCOM POSTAGE", "AMAZON FEE", "Adjust bad debt" y "Manual"
lista_valores_invalidos <- c(lista_valores_invalidos, "Adjust bad debt",
                             "POSTAGE", "DOTCOM POSTAGE", "AMAZON FEE", "Manual")

datos <- datos[!datos$Itemname %in% lista_valores_invalidos, ]

summary(datos)
#Ahora los datos están en una mejor calidad

write.xlsx(datos, "datos_limpios.xlsx")