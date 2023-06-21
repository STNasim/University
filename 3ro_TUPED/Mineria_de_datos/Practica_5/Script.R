#Ejercicio 1
library("pacman")
p_load(arules)
rm(list = ls())
gc()

#a
#datos <- read.csv("orders.csv", sep = ";")

transacciones <- read.transactions("orders.csv",format = "single", sep = ";", header = TRUE, col = c("order_id","product_name"))
summary(transacciones)
n.trans <- size(transacciones)
# Vemos como se distribuyen las cantidades de items por transacción
hist(n.trans)

#b
soporte <- 0.001
itemsets_frec <- apriori(transacciones, 
                         parameter = list(support = soporte,
                                          #minlen = 2,
                                          target = "frequent itemsets"), 
                         control = list(verbose=F))
inspect(itemsets_frec)
itemsetsfrec5 <- sort(itemsets_frec, by = "support", decreasing = TRUE)[1:5]
inspect(itemsetsfrec5)

#c
confianza <- 0.7
reglas <- apriori(transacciones,
                  parameter = list(support = soporte,
                                   confidence = confianza,
                                   #minlen = 2,
                                   target = "rules"),
                  control = list(verbose = F))
inspect(sort(reglas, decreasing = TRUE, by = "confidence"))

#Ejercicio 2

rm(list = ls())
gc()
load("titanic.raw.rdata")
sobrevive <- apriori(titanic.raw,
                     parameter = list(supp=0.005,conf=0.8),
                     target = "rules",
                     appearance = list(rhs=c("Survived=Yes", "Survived=No"),
                                            default="lhs"),
                     control = list(verbose=F))
inspect(sort(sobrevive, decreasing = TRUE, by = "confidence"))
