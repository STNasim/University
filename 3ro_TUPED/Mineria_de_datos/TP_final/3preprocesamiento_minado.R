rm(list = ls())
gc()
library(pacman)
p_load(arulesSequences,arules,openxlsx,dplyr,stringr)


datos <- read.xlsx("datos_limpios.xlsx")
datos2 <- na.omit(datos)

#Creación de transacciones

datos3 <- datos2 %>%
  group_by(CustomerID, BillNo) %>%
  summarise(Itemname = list(Itemname)) %>%
  mutate(item_id = row_number()) %>%
  ungroup() %>%
  select(CustomerID, item_id, Itemname)

transactions_list <- datos3 %>%
  pull(Itemname)

transacciones <- as(transactions_list, "transactions")

transactionInfo(transacciones) <- data.frame(sequenceID = datos3$CustomerID, 
                                             eventID = datos3$item_id)

#Analisis de transacciones

transacciones
#Hay un total de 18054 transacciones y 3843 items, lo cual coincide con:
n_distinct(datos2$Itemname)
n_distinct(datos2$BillNo)
inspect(transacciones[1:5])
summary(transacciones)

#Secuencias

seq <- cspade(transacciones,
              parameter = list(support = 0.02),
              control = list(verbose=F))
seq

inspect(sort(seq, by = "support", decreasing = TRUE)[1:10])

#Para guardar los resultados

salida <- as(seq, "data.frame") %>% as_tibble()
salida$pattern <- (str_count(salida$sequence, ",") + 1)
salida <- salida[order(-salida$support),]
write.csv(x=salida, file="sequencias_2.csv", row.names=FALSE)

#10 items mas comprados

top_10 <- head(sort(itemFrequency(transacciones), decreasing = TRUE),10)
top_10_items_df <- data.frame(item = names(top_10), frequency = top_10)

write.csv(top_10_items_df, file = "top_10_items.csv", row.names = FALSE)

#Secuencias con soporte 3

seq_3 <- cspade(transacciones,
              parameter = list(support = 0.03),
              control = list(verbose=F))
seq_3

seq_3 <- seq_3[size(seq_3,"items")>1]
seq_3

inspect(sort(seq_3, by = "support", decreasing = TRUE)[1:10])

salida <- as(seq_3, "data.frame") %>% as_tibble()
salida$pattern <- (str_count(salida$sequence, ",") + 1)
salida <- salida[order(-salida$support),]
salida$apariciones <- round(salida$support*18054)
salida$apariciones_porcentual <- salida$support*100
write.csv(x=salida, file="sequencias_3.csv", row.names=FALSE)
