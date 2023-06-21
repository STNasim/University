library(pacman)
p_load(openxlsx,ggplot2,lubridate,dplyr)
rm(list = ls())
gc()
datos <- read.xlsx("datos_limpios.xlsx")
datos2 <- datos %>% group_by(BillNo,Itemname) %>% distinct(BillNo,Itemname)
#BillNo

#En este caso la variable categórica, más bien un factor,
#representa cada compra de item diferente en una misma transacción

datos$BillNo <- as.factor(datos$BillNo)

#Lo mas apropiado es utilizar un histograma para ver la
#distribución de cantidad de items diferentes por transacción

hist(table(datos$BillNo), main = "Histograma de BillNo", 
     xlab = "Items diferentes por transacción", ylab = "Frecuencia")

#Haciendo zoom a los valores menores a 300
tabla_aux <- table(datos$BillNo)

tabla_filtrada <- tabla_aux[tabla_aux < 300]

hist(tabla_filtrada,
     main = "Histograma de BillNo",
     xlab = "Items diferentes por transacción",
     ylab = "Frecuencia",
     breaks = 30)

#Se ve que en la gran mayoría de transacciones el número de items diferentes comprados
#es pequeño, mayoritariamente menor a 50


#Itemname


#Se realiza un proceso similar a Billno para esta variable
#que representaría la cantidad de veces que un item aparece en las transacciones

datos$Itemname <- as.factor(datos$Itemname)

#Nuevamente se usa un histograma

hist(table(datos$Itemname), main = "Histograma de Itemname", breaks = 20,
     xlab = "Apariciones en transacciones", ylab = "Numero de items")

#Se observa que la gran mayoria de items aparecen en las transacciones menos de 100 veces

#Auxiliar

# Count the frequency of each unique value in the 'Itemname' column
frequency <- datos %>% distinct(Itemname,BillNo) %>%count(Itemname)

# Sort the frequencies in descending order and select the top 10
top_10 <- frequency %>% arrange(desc(n)) %>% head(10)

# Calculate the percentage of the total number of rows in the dataframe that belong to the top 10 values
top_10_percentage <- (sum(top_10$n) / nrow(datos)) * 100
other_percentage <- unique(100 - top_10_percentage)

# Create a new dataframe for the pie chart
pie_data <- data.frame(
  category = c("Top 10", "Otros"),
  percentage = c(top_10_percentage, other_percentage)
)

# Create a pie chart to visualize the percentage distribution
ggplot(pie_data, aes(x = "", y = percentage, fill = category)) +
  geom_bar(width = 1, stat = "identity") +
  coord_polar("y", start = 0) +
  theme_void() +
  theme(legend.position = "right") +
  labs(title = "Percentage of Rows Belonging to Top 10 Values", x = NULL, y = NULL, fill = "Category") +
  ggtitle("Distribución de items pertenecientes al top 10 más comprado") +
  labs(fill= "") +
  geom_text(aes(label = paste0(round(percentage, 1), "%")), 
            position = position_stack(vjust = 0.5), 
            color = "white", size = 4)
#Quantity


#Si bien esta variable es númerica y puede analizarse de manera diferente a las anteriores,
#que eran categóricas, al ser los precios tan dispersos, es posible que no se pueda en profundidad

boxplot(datos$Quantity, main = "Boxplot de Quantity", xlab = "Cantidad", ylab = "Frequencia")
#El boxplot es intentendible por la dispersión de los datos

hist(datos$Quantity, main = "Histograma de Quantity",
     xlab = "Cantidad comprada", ylab = "Frecuencia")

#Se ve que los valores son muy dispersos, asi que se hace un "zoom" imputando valores muy grandes
datos_aux <- datos
datos_aux$Quantity <- ifelse(datos_aux$Quantity > 4000,
                             NA, datos_aux$Quantity)

hist(datos_aux$Quantity, main = "Histograma de Quantity", breaks = 20,
     xlab = "Cantidad comprada", ylab = "Frecuencia")

#Se ve finalmente que las cantidades por compra suelen ser bajos, en gran parte de las veces,
#menores a 10, lo que dice que por lo general no se realizan compras al por mayor

#Auxiliar

below_threshold <- datos %>% filter(Quantity < 50) %>% nrow()
total_values <- nrow(datos)
percentage_below <- (below_threshold / total_values) * 100
percentage_above <- 100 - percentage_below

percentages <- data.frame(
  category = c("Debajo", "Igual o encima"),
  percentage = c(percentage_below, percentage_above)
)

ggplot(percentages, aes(x = "", y = percentage, fill = category)) +
  geom_bar(stat = "identity", width = 1) +
  coord_polar("y", start = 0) +
  theme_void() +
  ggtitle("Distribución de datos con cantidad 50") +
  labs(fill= "") +
  geom_text(aes(label = paste0(round(percentage, 1), "%")), 
            position = position_stack(vjust = 0.5), 
            color = "white", size = 4)

#Date


#Esta variable de tipo fecha se puede explorar de manera similar a las categóricas,
#viendo si existe, por ejemplo, algun mes dónde hubo gran cantidad de compras, ya que
#visualizar los datos dia por dia sería imposible por la gran cantidad en el rango

datos$Date <- convertToDate(datos$Date)

datos$mes <- floor_date(datos$Date, "month")

por_mes <- function(x, n = 1) {
  seq(min(x, na.rm = TRUE), max(x, na.rm = TRUE), by = paste0(n, " months"))
}

# Plot the histogram
ggplot(datos, aes(mes)) +
  geom_histogram(breaks = por_mes(datos$mes)) +
  scale_x_date(labels = scales::date_format("%Y-%m"), breaks = por_mes(datos$mes)) +
  theme(axis.text.x = element_text(angle = 90)) +
  ggtitle("Compras por mes") +
  ylab("Cantidad") +
  xlab("Mes") +
  theme(plot.title = element_text(hjust = 0.5))

#Se borra mes despues de ser usada

borrar <- c("mes")
datos <- datos[ , !(names(datos) %in% borrar)]

#Se observa que los valores de compras únicas se mantienen más o menos constante pero tuvieron picos
#durante diciembre de 2010 y la época entre Agosto y Noviembre de 2011


#Price


#Con esta variable puede ocurrir algo similar a lo que pasó con Quantity


boxplot(datos$Price, main = "Boxplot de Price", xlab = "Precio", ylab = "Frequencia")
#El boxplot es intentendible por la dispersión de los datos

hist(datos$Price, main = "Histograma de Precio",
     xlab = "Precio", ylab = "Frecuencia")

#Se ve que los valores son muy dispersos, asi que se hace un "zoom" imputando valores muy grandes
datos_aux <- datos
datos_aux$Price <- ifelse(datos_aux$Price > 50,NA, datos_aux$Price)

hist(datos_aux$Price, main = "Histograma de Price",
     xlab = "Precio", ylab = "Frecuencia")

#Se ve finalmente que los precios por compra suelen ser muy bajos, mayoritariamente, menores a 6,
#lo que indicaria que los productos vendidos suelen ser relativamente baratos

#Auxiliar

below_threshold <- datos %>% filter(Price < 20) %>% nrow()
total_values <- nrow(datos)
percentage_below <- (below_threshold / total_values) * 100
percentage_above <- 100 - percentage_below

percentages <- data.frame(
  category = c("Debajo", "Igual o encima"),
  percentage = c(percentage_below, percentage_above)
)

ggplot(percentages, aes(x = "", y = percentage, fill = category)) +
  geom_bar(stat = "identity", width = 1) +
  coord_polar("y", start = 0) +
  theme_void() +
  ggtitle("Distribución de datos con cantidad 20") +
  labs(fill= "") +
  geom_text(aes(label = paste0(round(percentage, 1), "%")), 
            position = position_stack(vjust = 0.5), 
            color = "white", size = 4)

#CustomerID

#Se puede realizar un analisis similar al de otras variables categóricas

datos$CustomerID <- as.factor(datos$CustomerID)

#Nuevamente se usa un histograma

hist(table(datos$CustomerID), main = "Histograma de CustomerID", breaks = 50,
     xlab = "Compras diferentes por cliente", ylab = "Numero de clientes")

#Haciendo zoom a los valores menores a 500
tabla_aux <- table(datos$CustomerID)

tabla_filtrada <- tabla_aux[tabla_aux < 500]

hist(tabla_filtrada,
     main = "Histograma de CustomerID",
     xlab = "Compras diferentes por cliente",
     ylab = "Numero de clientes",
     breaks = 50)

#Se observa que la gran mayoria de clientes no realiza muchas compras, la mayoria
#se ubica por debajo de las 200

#Country

#Se puede realizar un analisis similar al de otras variables categóricas

datos$Country <- as.factor(datos$Country)

#En este caso al ser relativamente pocos datos se podría utilizar un gráfico de barras

par(mar = c(10, 8, 4, 2))

barplot(table(datos$Country), main = "Grafico de Country", las = 2)
title(xlab = "Pais", line = 6)
title(ylab = "Compras", line = 5)
#Por lo que se ve, la gran mayoría de las compras provienen del Reino Unido lo que tiene
#sentido ya que la tienda se encuentra allí, tambien se ve una pequeña diferencia de ventas
#en paises europeas a comparación con el resto, seguramente por la cercania


#Como ahora se convirtieron las variables la funcion summary() provee información
#mas util de cada una

summary(datos)

#Para las variables cualitativas se puede ver información como los datos más comunes
#que antes no podian apreciarse

