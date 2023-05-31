rm(list =ls())
gc()
# ---- Importar librerías ----
library(pacman)
p_load(DESeq2,biomaRt,tidyverse,ggplot2,pheatmap,ggrepel)

# Archivos de conteos de entrada - STAR

files <- list.files(path = "../alignments", pattern = "_ReadsPerGene.out.tab")
data <- NULL
for(archivo in files){
  data <- read_tsv(paste0("../alignments/",archivo), skip = 4 ,col_names = c("Gene_ID", "Total", "+", "-"), col_types = cols(.default = "c"), show_col_types = FALSE)
  write_tsv(data[,1:2], file = paste0(str_split(archivo, "_Reads")[[1]][1], "_counts.txt"), col_names = F)    
}
rm(data)

#---- Tabla de muestras ----

muestras <- sapply(str_split(files,"_Reads"),"[",1)

sampletable <- data.frame(SampleName=muestras,
                          FileName=paste0(muestras, "_counts.txt"),
                          Condition=c(rep("batch", 6), rep("quimiostato", 6)))
rownames(sampletable) <- gsub("_counts.txt", "", sampletable$FileName)

#---- Importar conteos STAR ----

se_star <- DESeqDataSetFromHTSeqCount(sampleTable = sampletable,
                                      design = ~ Condition)

# ----Filtrado de genes de baja expresión----

#Numero de genes antes del filtrado:
nrow(se_star)
#Filtrado:
se_star <- se_star[rowSums(counts(se_star)) > 10, ]
#Número de genes luego del filtrado:
nrow(se_star)

# ----Preparar anotación----

#Cargar la base de datos correspondiente
mart <- useMart(biomart="ensembl",
                dataset="scerevisiae_gene_ensembl")

#Se buscan los disponibles provenientes de ensembl
grep("ensembl", listFilters(mart)[,1], value=TRUE)
#ensembl_gene_id se encuentra!


#Lista de ENSEMBL IDs que queremos anotar
gene_ids <- rownames(se_star)

#Anotar!
annot <- getBM(attributes=c('ensembl_gene_id', 'chromosome_name', 'start_position', 'end_position', 'description', 'external_gene_name'), filters ='ensembl_gene_id', values = gene_ids, mart = mart)
dim(annot)
#1 sin anotar

head(annot)

#---- Ajustar modelo estadístico----

se_star2 <- DESeq(se_star)
#Calcular conteo normalizado (transformación log2); + 1
norm_counts <- log2(counts(se_star2, normalized = TRUE)+1)
#Agregar anotación
norm_counts_symbols <- merge(data.frame(ID=rownames(norm_counts), norm_counts, check.names=FALSE), annot, by.x="ID", by.y="ensembl_gene_id", all=F)
#Escribir conteos normalizados en un archivo
write.table(norm_counts_symbols, "normalized_counts_log2_star.txt", quote=F, col.names=T, row.names=F, sep="\t")

#----Análisis de expresiones diferenciales----

resultsNames(se_star2)

de <- results(object = se_star2, 
              name="Condition_quimiostato_vs_batch")

head(de)

de_symbols <- merge(data.frame(ID=rownames(de), de, check.names=FALSE), annot, by.x="ID", by.y="ensembl_gene_id", all=F)

write.table(de_symbols, "deseq2_results.txt", quote=F, col.names=T, row.names=F, sep="\t")

#----Selección de genes----

#Cuantos genes están expresados diferencialmente
de_select <- de_symbols[de_symbols$padj < 0.05 & !is.na(de_symbols$padj) & abs(de_symbols$log2FoldChange) > 0.5,]
write.table(de_select, "deseq2_selection.txt", quote=F, col.names=T, row.names=F, sep="\t")

#---- Visualización----

# Transforme los recuentos sin procesar para poder visualizar los datos
se_rlog <- rlog(se_star2)

#---- Visualización - Correlación de muestras----

#Calcular la matriz de distancia entre muestras
sampleDistMatrix <- as.matrix(dist(t(assay(se_rlog))))
#Preparar metadata
metadata <- as.data.frame(x = sampletable[("Condition")])
rownames(metadata) <- sampletable$SampleName
#Gráfico
pheatmap(sampleDistMatrix, annotation_col=metadata)

#-----Visualización - Análisis de componentes principales (PCA)----
plotPCA(object = se_rlog,
        intgroup = c("Condition"))

#---- Visualización - Volcano plot---- 

#Agregar columna de diferenciación
de_symbols$diffexpressed <- "NO"
#si log2Foldchange > 0.5 y pvalue < 0.05, setear "UP" 
de_symbols$diffexpressed[de_symbols$log2FoldChange > 0.5 & de_symbols$pvalue < 0.05] <- "UP"
#si log2Foldchange < -0.5 y pvalue < 0.05, setear "DOWN"
de_symbols$diffexpressed[de_symbols$log2FoldChange < -0.5 & de_symbols$pvalue < 0.05] <- "DOWN"
# Crear columna con los Ids de los genes que tienen expresión diferencial
de_symbols$delabel <- NA
de_symbols$delabel[de_symbols$diffexpressed != "NO"] <- de_symbols$external_gene_name[de_symbols$diffexpressed != "NO"]
#Graficar
ggplot(data = de_symbols,
       aes(
         x = log2FoldChange,
         y = -log10(pvalue),
         color = diffexpressed,
         label = delabel
       )) +
  geom_point() +
  geom_text_repel() +
  scale_color_manual(values = c("blue", "black", "red")) +
  geom_vline(xintercept = c(-0.5, 0.5), col = "red") +
  geom_hline(yintercept = -log10(0.05), col = "red") +
  labs(
    x = "log2FoldChange",
    y = "-log10(pvalue)",
    title = "Volcano plot",
    subtitle = "Se observa el -log10(pvalue) en función del log2FoldChange",
    color = "Expresión"
  ) +
  theme(
    legend.background = element_blank(),
    legend.position = "bottom",
    plot.title = element_text(hjust = 0.5),
    plot.subtitle = element_text(hjust = 0.5),
    panel.grid = element_blank(),
    panel.background = element_blank(),
    panel.border = element_rect(
      colour = "black",
      fill = NA,
      linewidth = 2
    )
  )
  
#Escribir los upregulated y downregulated

write.table(de_symbols[de_symbols$diffexpressed == "UP",]$external_gene_name, "upregulated.txt", quote=F, col.names=F, row.names=F, sep="\t")
write.table(de_symbols[de_symbols$diffexpressed == "DOWN",]$external_gene_name, "downregulated.txt", quote=F, col.names=F, row.names=F, sep="\t")
write.table(de_symbols[de_symbols$diffexpressed == "UP",]$ID, "Y-upregulated.txt", quote=F, col.names=F, row.names=F, sep="\t")
write.table(de_symbols[de_symbols$diffexpressed == "DOWN",]$ID, "Y-downregulated.txt", quote=F, col.names=F, row.names=F, sep="\t")

