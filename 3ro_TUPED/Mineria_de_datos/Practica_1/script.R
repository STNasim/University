library(pacman)
p_load(readxl,rvest,data.table,dyplyr)

#Actividad 1
rm( list=ls() )
gc()
download.file(url = "https://archive.ics.uci.edu/ml/machine-learning-databases/00616/Tetuan%20City%20power%20consumption.csv",
              destfile = "TetuanCityPowerConsumption.csv")

#Actividad 2
rm( list=ls() )
gc()
pagina <- read_html("http://www.espn.com/nfl/superbowl/history/winners")
cssTabla <- "td"
filas <- pagina %>% 
  html_nodes(css = cssTabla) %>% 
  html_text(trim = T)
filas<-filas[-1]
header <- filas[1:4]
filas <- filas[-(1:4)]
indices <- seq(from = 1,
               to = length(filas), 
               by = length(header))
tabla <- NULL
for (i in indices){
  aux <- filas[i:(i+3)]
  tabla <- c(tabla, aux)
}
tabla <- data.frame(matrix(tabla, ncol = length(header), byrow = T))
colnames(tabla) <- header
head(tabla)
fwrite(tabla, file = "./ganadores_Super_Bowl.csv", sep = ";")

#Actividad 3
rm( list=ls() )
gc()
# Definimos el elemento CSS del encabezado de la tabla
pagina <- read_html("https://statistics.stanford.edu/people/alumni?page=0")
cssHeader <- ".hb-table-pattern__row"
header <- pagina %>% 
  html_nodes(cssHeader) %>%
  html_nodes("div") %>%
  html_text(trim = T)
# Definimos los CSS de los campos de interés 
cssTabla <- ".hb-table-pattern__body" #
cssFila <- ".hb-table-row"
cssCamposAlumno <- ".hb-table-row__column" # 
path <- "https://statistics.stanford.edu/people/alumni?page="
ini <-2
fin <- 7
tabla <- NULL
#Corregir indices

for(i in (fin:ini)){
  pagina <- read_html(paste0(path,i))
  filas <- pagina %>% 
    html_nodes(css = cssTabla) %>% 
    html_nodes(css = cssFila) %>% 
    html_nodes(css = cssCamposAlumno) %>% 
    html_text(trim = T)
  indices <- seq(from = 1,
                 to = length(filas), 
                 by = length(header))
  for (i in indices){
    aux <- filas[i:(i+length(header)-1)]
    tabla <- c(tabla, aux)
  }
}
tabla <- data.frame(matrix(tabla, ncol = length(header), byrow = T))
colnames(tabla) <- header
head(tabla)
tail(tabla)
tabla <- tabla[tabla$"Graduation Year" >= 1980 & tabla$"Graduation Year" <= 2007, ]
tabla <- tabla[order(tabla$"Graduation Year"),]
head(tabla)
tail(tabla)
fwrite(tabla, file = "./alumnos.csv", sep = ";")