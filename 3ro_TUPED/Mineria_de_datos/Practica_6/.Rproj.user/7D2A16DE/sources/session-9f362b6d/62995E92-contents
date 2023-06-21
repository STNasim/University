#Ejercicio 1
library("pacman")
p_load(arules)
rm(list = ls())
gc()
transacciones <- read.transactions("groceries.csv",format = "basket", sep = ",", header = FALSE)

#a
summary(transacciones)
n.trans <- size(transacciones)
hist(n.trans)

#b
soporte = median(itemFrequency(transacciones))
itemsets <- eclat(transacciones,
                  parameter = list(support = soporte
                                   #confidence = confianza
                                   #minlen = 2
                                   ),
                  control = list(verbose = F))
top5 <- (sort(itemsets, decreasing = TRUE, by = "support"))[1:5]
inspect(top5)

#c
confianza <- 0.25
reglas25 <- apriori(transacciones,
                  parameter = list(support = soporte,
                                   confidence = confianza,
                                   #minlen = 2,
                                   target = "rules"),
                  control = list(verbose = F))
inspect(sort(reglas25, decreasing = TRUE, by = "confidence"))

confianza <- 0.5
reglas50 <- apriori(transacciones,
                    parameter = list(support = soporte,
                                     confidence = confianza,
                                     #minlen = 2,
                                     target = "rules"),
                    control = list(verbose = F))
inspect(sort(reglas50, decreasing = TRUE, by = "confidence"))

reglas25
reglas50

#d
reglas25_lift_mayor_2 <- subset(reglas25, lift >2)
inspect(reglas25_lift_mayor_2)

reglas25_lift_mayor_2_veg_cons <- subset(reglas25_lift_mayor_2, subset = rhs %in% "other vegetables")
inspect(reglas25_lift_mayor_2_veg_cons)

reglas25_lift_mayor_2_veg_yogurt_ante <- subset(reglas25_lift_mayor_2, subset = lhs %oin% c("other vegetables", "yogurt"))
inspect(reglas25_lift_mayor_2_veg_yogurt_ante)

reglas25_lift_mayor_2_veg_yogurt_cons <- subset(reglas25_lift_mayor_2, subset = rhs %in% c("other vegetables", "yogurt"))
inspect(reglas25_lift_mayor_2_veg_yogurt_cons)

#Ejercicio 2
library("pacman")
p_load(arules)
rm(list = ls())
gc()
transacciones <- read.transactions("orders.csv",format = "single", sep = ";", header = TRUE, col = c("order_id","product_name"))
summary(transacciones)
n.trans <- size(transacciones)
hist(n.trans)

#a
soporte = 0.001
itemsets <- eclat(transacciones,
                  parameter = list(support = soporte,
                                   #confidence = confianza
                                   minlen = 3
                  ),
                  control = list(verbose = F))
inspect(itemsets)

#b
confianza = 0.7
reglas_eclat <- ruleInduction(x = itemsets,
                        transactions = transacciones,
                        confidence = confianza)
inspect(sort(reglas_eclat, decreasing = TRUE, by = "lift"))

#c
reglas_apriori <- apriori(transacciones,
                    parameter = list(support = soporte,
                                     confidence = confianza,
                                     minlen = 3,
                                     target = "rules"),
                    control = list(verbose = F))
inspect(reglas_apriori)

interestMeasure(reglas_eclat, measure = "coverage")
interestMeasure(reglas_apriori, measure = "coverage")

interestMeasure(reglas_eclat, measure = "lift")
interestMeasure(reglas_apriori, measure = "lift")

interestMeasure(reglas_eclat, measure = "fishersExactTest")
interestMeasure(reglas_apriori, measure = "fishersExactTest")
