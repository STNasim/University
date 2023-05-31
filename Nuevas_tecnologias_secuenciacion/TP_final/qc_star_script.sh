#!/bin/bash
samples=("batch1_1" "batch2_1" "batch3_1" "quimiostato1_1" "quimiostato2_1" "quimiostato3_1" "batch1_2" "batch2_2" "batch3_2" "quimiostato1_2" "quimiostato2_2" "quimiostato3_2")
gtf_file="datos/sacCer_genes.gtf"
output_dir="qc_qualimap_STAR"
for sample in "${samples[@]}"; do
    qualimap rnaseq -bam alignments/${sample}_Aligned.sortedByCoord.out.bam \
    -gtf $gtf_file \
    -outdir $output_dir/${sample}_qualimap -p non-strand-specific
done