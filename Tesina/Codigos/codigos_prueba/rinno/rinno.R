rm(list =ls())
gc()
library(RInno)
#APP LIMMA
create_app(
  app_name = "limma",
  app_dir = "limma",
  pkgs = c("BiocManager","rstudioapi"),
  script = "limma_script.R",
  include_R = TRUE,
  R_version = "4.3.1"
)
#APP PRUEBA SHINY
create_app(
  app_name = "shiny_prueba",
  app_dir = "F:/shiny_prueba",
  pkgs = c("shiny","rstudioapi"),
  script = "shiny_prueba.R",
  include_R = TRUE,
  R_version = "4.3.1"
)
#install_inno()
compile_iss()
