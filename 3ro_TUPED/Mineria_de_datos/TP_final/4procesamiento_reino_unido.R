rm(list = ls())
gc()
library(pacman)
p_load(arules,arulesSequences,openxlsx,dplyr)

datos_crudos <- read.xlsx("datos_limpios.xlsx")

datos_uk <- na.omit(datos_crudos)
datos_uk <- datos_uk[datos_uk$Country == "United Kingdom", ]
table(datos_uk$Country)

#Reemplazar todos los espacios por guion para que sean leidas 
#correctamente las transacciones por read_baskets()
datos_uk$Itemname <- gsub(" ", "-", datos_uk$Itemname)

datos3 <- datos_uk %>%
  group_by(CustomerID, Date) %>%
  summarise(Itemname = list(Itemname)) %>%
  mutate(item_id = row_number()) %>%
  ungroup() %>%
  select(CustomerID, item_id, Itemname)

transactions_list <- datos3 %>%
  pull(Itemname)

sequence_event_info <- unique(datos3[, c("item_id", "CustomerID")])

output_data <- cbind(sequence_event_info, item_lists = sapply(transactions_list, function(x) paste(x, collapse = " ")))

output_data$item_id <- as.character(output_data$item_id)
output_data$CustomerID <- as.character(output_data$CustomerID)
salida <- apply(output_data, 1, paste, collapse=" ")

write.table(salida, file = "datos_basket_uk.txt", 
            row.names = FALSE, quote = FALSE, col.names = FALSE)

# Carga

rm(list = ls())
gc()

transacciones <- read_baskets(con = "datos_basket_uk.txt",
                              info = c("eventID","sequenceID"))
transacciones

#Procesamiento

itemsets <- eclat(transacciones,
              parameter = list(support = 0.01, minlen = 2),
              control = list(verbose=F))

inspect(itemsets)

reglas <- ruleInduction(itemsets, transacciones, confidence = 0.7)
reglas
reglas <- sort(reglas, by = "lift", decreasing = TRUE)
inspect(reglas[1:10])

#Guardado

reglas_df <- as(reglas, "data.frame")
#Reemplazar todos las comas por punto y coma para que se guarde correctamente
reglas_df$rules <- gsub(",", ";", reglas_df$rules)
write.csv(reglas_df[1:10,], file = "reglas_lift_10.csv", row.names = FALSE, quote = FALSE)
