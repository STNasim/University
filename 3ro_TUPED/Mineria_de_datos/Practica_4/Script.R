#Ejercicio 1
rm(list =ls())
gc()
library(pacman)
datos <- read.csv("Entrenamiento_ECI_2020.csv", stringsAsFactors = TRUE)
#a
dim(datos)
str(datos)
summary(datos)
colSums(is.na(datos))
#b
table(datos$Stage)
datos2 <- subset(datos, grepl("Closed", Stage))
table(datos2$Stage)
datos2$Stage <- ifelse(datos2$Stage == "Closed Won", 1, 0)
table(datos2$Stage)
datos2$Stage <- as.factor(datos2$Stage) # convert to factor
str(datos2)
#c
ggplot(data = datos2, aes(x = Stage,
                   y = Total_Amount,
                   fill = Stage)) + geom_boxplot()
#d
plot(datos[c("TRF","Total_Amount","Total_Taxable_Amount")],col = datos$Stage)

#Ejercicio 2
rm(list =ls())
gc()
library(pacman)
p_load(ggplot2,rmatio)

nombres <- list.files(path = "./ECGs", pattern = "*.mat", full.names = TRUE)
lista <- lapply(nombres, read.mat)
lista <- lapply(lista,unlist)

fun <- function(x) {
  length(x)/300
}

minimos <- unlist(lapply(lista, min))
medianas <- unlist(lapply(lista, median))
maximos <- unlist(lapply(lista, max))
tiempos <- unlist(lapply(lista, fun))
desvios <- unlist(lapply(lista, sd))

                  