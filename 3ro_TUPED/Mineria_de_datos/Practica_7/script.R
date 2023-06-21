rm(list = ls())
gc()
library(pacman)
p_load(arules,arulesCBA,arulesViz,caret)

#1
load("titanic.raw.rdata")
set.seed(1234)
porc <- 0.8

train.ind <- createDataPartition(titanic.raw$Survived, p=porc, list = F)
datos.train <- titanic.raw[train.ind,]
datos.test <- titanic.raw[-train.ind,]

#A 4 reglas
CARs1 <- CBA(Survived ~ .,
             data =datos.train,
             parameter = list(supp=0.1, conf=0.3),
             verbose = FALSE)

inspect(CARs1$rules)
prediccion1 <- predict(CARs1, datos.test)
tabla1 <- confusionMatrix(prediccion1,datos.test$Survived)
tabla1

#B 7 reglas. Mejoró en gran parte los que no sobrevivieron
CARs2 <- CBA(Survived ~ .,
             data =datos.train,
             parameter = list(supp=0.001, conf=0.8),
             verbose = FALSE)

inspect(CARs2$rules)
prediccion2 <- predict(CARs2, datos.test)
tabla2 <- confusionMatrix(prediccion2,datos.test$Survived)
tabla2

#C 30 reglas Ligeramente peor al primero
CARs3 <- CMAR(Survived ~ .,
             data =datos.train,
             supp=0.1, 
             conf=0.3,
             verbose = FALSE)

inspect(CARs3$rules)
prediccion3 <- predict(CARs3, datos.test)
tabla3 <- confusionMatrix(prediccion3,datos.test$Survived)
tabla3

#D 15 reglas. Mismo resultado al 2do.
CARs4 <- CMAR(Survived ~ .,
              data =datos.train,
              supp=0.001, 
              conf=0.8,
              verbose = FALSE)

inspect(CARs4$rules)
prediccion4 <- predict(CARs4, datos.test)
tabla4 <- confusionMatrix(prediccion4,datos.test$Survived)
tabla4

#2

rm(list = ls())
gc()

#a
datos <- read.csv("Entrenamiento_ECI_2020.csv", sep = ",")
set.seed(1234)
porc <- 0.8

table(datos$Stage)
datos$Stage <- ifelse(datos$Stage == "Closed Won", 1, 0)
table(datos$Stage)
datos$Stage <- as.factor(datos$Stage) # convert to factor

train.ind <- createDataPartition(datos$Stage, p=porc, list = F)
datos.train <- datos[train.ind,]
datos.test <- datos[-train.ind,]

#A
CARCBA <- CBA(Stage ~ .,
              data =datos.train,
              parameter = list(supp=0.1, conf=0.5),
              verbose = FALSE)

inspect(CARCBA$rules)
prediccionCBA <- predict(CARCBA, datos.test)
tablaCBA <- confusionMatrix(prediccionCBA,datos.test$Stage)
tablaCBA

#B
CARCMAR <- CMAR(Stage ~ .,
                data =datos.train,
                supp=0.1, 
                conf=0.5,
                verbose = FALSE)

inspect(CARCMAR$rules)
prediccionCMAR <- predict(CARCMAR, datos.test)
tablaCMAR <- confusionMatrix(prediccionCMAR,datos.test$Stage)
tablaCMAR

#A cate

col.utiles <- c(2:9,11:22,24:28,32:35,43,51)

CARCBA2 <- CBA(Stage ~ .,
              data =datos.train[,col.utiles],
              parameter = list(supp=0.1, conf=0.5),
              verbose = FALSE)

inspect(CARCBA2$rules)
prediccionCBA2 <- predict(CARCBA2, datos.test)
tablaCBA2 <- confusionMatrix(prediccionCBA2,datos.test$Stage)
tablaCBA2

#B cate
CARCMAR2 <- CMAR(Stage ~ .,
                data =datos.train[,col.utiles],
                supp=0.1, 
                conf=0.5,
                verbose = FALSE)

inspect(CARCMAR2$rules)
prediccionCMAR2 <- predict(CARCMAR2, datos.test)
tablaCMAR2 <- confusionMatrix(prediccionCMAR2,datos.test$Stage)
tablaCMAR2


