library(shiny)
library(rstudioapi)

write.table(c(1,2,3,4), file = "resultados.tsv", row.names = FALSE, sep = "\t", quote = FALSE)

setwd(dirname(rstudioapi::getActiveDocumentContext()$path))

write.table(c(1,2,3,4), file = "resultados2.tsv", row.names = FALSE, sep = "\t", quote = FALSE)
ui <- fluidPage(
  textOutput("workingDirectory")
)

server <- function(input, output) {
  output$workingDirectory <- renderText({
    getwd()
  })
}

shinyApp(ui, server)