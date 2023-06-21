#Ejercicio 1
rm(list =ls())
gc()
library(pacman)
p_load(pdftools,stringr,data.table)
datos <- pdf_text("./datos/usbp_stats_fy2017_sector_profile.pdf")
# Cada elemento del objeto datos es una de las hojas del pdf
head(datos)
datos[1]
datos[2]
datos[3]
datos[4]

# Tomamos la primer tabla
# Vamos a separar toda la cadena en un vector de cadenas por fila \n
sector_profile <- datos[1]
sector_profile <- strsplit(sector_profile, "\n")
# Queda en forma de lista, así que nos quedamos con el primer elemento
sector_profile <- sector_profile[[1]]
head(sector_profile)
# Eliminamos los espacios en blanco al inicio y final de las cadenas filas
sector_profile <- trimws(sector_profile)
head(sector_profile)
# Nos quedamos con las filas que necesitamos: desde "Miami" hasta 
# "Natiowide Total"
# Con grep() encontramos las posiciones que queremos
ini <- grep("Miami", sector_profile)
fin <- grep("Nationwide Total", sector_profile)
tabla1 <- sector_profile[ini:fin]
head(tabla1)
# Vamos a dividir las cadenas de las filas en 10 columnas y usamos como
# patrón en espacio " ", pero que aparezca 2 o más veces
tabla1 <- str_split_fixed(tabla1, " {2,}", 10)
# Como los números aparece con la "," como divisor de miles, la eliminamos
tabla1 <- str_remove_all(tabla1,",")
head(tabla1)
# Armamos un dataframe
tabla1 <- data.frame(matrix(tabla1,ncol=10))
# Le damos los nombres
colnames(tabla1) <- c("Sector", "AgentStaffing", "Apprehensions", 
                      "Ather_than_mexican_apprehensions", "MarijuanaPounds",
                      "CocainePounds", "AcceptedProsecutions", "Assaults",
                      "Rescues", "Deaths")
# Eliminamos las filas nulas
tabla1 <- tabla1[-c(5,15),]
# Vemos los tipos de datos
str(tabla1)

# Cambiamos los tipos de datos
tabla1$AgentStaffing <- as.numeric(tabla1$AgentStaffing)
tabla1$Apprehensions <- as.numeric(tabla1$Apprehensions)
tabla1$Ather_than_mexican_apprehensions <- as.numeric(tabla1$Ather_than_mexican_apprehensions)
tabla1$MarijuanaPounds <- as.numeric(tabla1$MarijuanaPounds)
tabla1$CocainePounds <- as.numeric(tabla1$CocainePounds)
tabla1$AcceptedProsecutions <- as.numeric(tabla1$AcceptedProsecutions)
tabla1$Assaults <- as.numeric(tabla1$Assaults)
tabla1$Rescues <- as.numeric(tabla1$Rescues)
tabla1$Deaths <- as.numeric(tabla1$Deaths)
str(tabla1)
head(tabla1)

#Ejercicio 2
rm(list =ls())
gc()
datos <- pdf_text("rep_covid-19_er_01_06_2022.pdf")
reporte <- datos[5:8]
reporte <- strsplit(reporte, "\n")
reporte <- unlist(reporte)
# Eliminamos los espacios en blanco al inicio y final de las cadenas filas
reporte <- trimws(reporte)
head(reporte)
# Nos quedamos con las filas que necesitamos: desde "Miami" hasta 
# "Natiowide Total"
# Con grep() encontramos las posiciones que queremos
ini <- grep("Colón", reporte)
fin <- grep("Villaguay", reporte)
tabla1 <- reporte[ini[1]:tail(fin,1)]
print(tabla1)
tabla1 <- tabla1[-(58:68)]
tabla1 <- tabla1[-(117:127)]
tabla1 <- tabla1[-(181:191)]
tabla1 <- tabla1[seq (from = 2, to = 232, by = 2)]
# Vamos a dividir las cadenas de las filas en 10 columnas y usamos como
# patrón en espacio " ", pero que aparezca 2 o más veces
tabla2 <- str_split_fixed(tabla1, " {2,}", 9)
# Como los números aparece con la "," como divisor de miles, la eliminamos
tabla2 <- str_remove_all(tabla2,",")

print(tabla3)
# Armamos un dataframe
tabla1 <- data.frame(matrix(tabla1,ncol=10))
# Le damos los nombres
colnames(tabla1) <- c("Sector", "AgentStaffing", "Apprehensions", 
                      "Ather_than_mexican_apprehensions", "MarijuanaPounds",
                      "CocainePounds", "AcceptedProsecutions", "Assaults",
                      "Rescues", "Deaths")
# Eliminamos las filas nulas
tabla1 <- tabla1[-c(5,15),]
# Vemos los tipos de datos
str(tabla1)

# Cambiamos los tipos de datos
tabla1$AgentStaffing <- as.numeric(tabla1$AgentStaffing)
tabla1$Apprehensions <- as.numeric(tabla1$Apprehensions)
tabla1$Ather_than_mexican_apprehensions <- as.numeric(tabla1$Ather_than_mexican_apprehensions)
tabla1$MarijuanaPounds <- as.numeric(tabla1$MarijuanaPounds)
tabla1$CocainePounds <- as.numeric(tabla1$CocainePounds)
tabla1$AcceptedProsecutions <- as.numeric(tabla1$AcceptedProsecutions)
tabla1$Assaults <- as.numeric(tabla1$Assaults)
tabla1$Rescues <- as.numeric(tabla1$Rescues)
tabla1$Deaths <- as.numeric(tabla1$Deaths)
str(tabla1)
head(tabla1)

#Ejercicio 3
rm(list =ls())
gc()

# Extraer el texto del archivo PDF (página 11)
datos <- pdf_text("https://bancos.salud.gob.ar/sites/default/files/2022-10/BEN_621_SE_39.pdf")[11]
print(datos)

# Vamos a separar toda la cadena en un vector de cadenas por fila \n

datos2 <- strsplit(datos, "\n")
# Queda en forma de lista, así que nos quedamos con el primer elemento
datos2 <- datos2[[1]]
print(datos2)
# Eliminamos los espacios en blanco al inicio y final de las cadenas filas
datos2 <- trimws(datos2)
print(datos2)
# Nos quedamos con las filas que necesitamos: desde "Miami" hasta 
# "Natiowide Total"
# Con grep() encontramos las posiciones que queremos
ini <- grep("Región de África", datos2)
fin <- grep("Región del Pacífico Occidental", datos2)
tabla1 <- datos2[ini:fin]
print(tabla1)
# Vamos a dividir las cadenas de las filas en 10 columnas y usamos como
# patrón en espacio " ", pero que aparezca 2 o más veces
tabla2 <- str_remove_all(tabla2,"\\.")
tabla2 <- str_remove_all(tabla2,",")
tabla2 <- str_split_fixed(tabla1, " {2,}", 3)
print(tabla2)
# Armamos un dataframe
tabla3 <- data.frame(matrix(tabla2,ncol=3))
# Le damos los nombres
colnames(tabla3) <- c("Región","Casos","Fallecidos")
# Vemos los tipos de datos
print(tabla3)
str(tabla3)

# Cambiamos los tipos de datos
tabla3$Casos <- as.numeric(tabla3$Casos)
tabla3$Fallecidos <- as.numeric(tabla3$Fallecidos)
str(tabla3)
print(tabla3)

# Guardar la tabla de datos en un archivo CSV
fwrite(tabla3, "tablaej3.csv", sep = ";")
