#!/bin/bash
samples=("batch1" "batch2" "batch3" "quimiostato1" "quimiostato2" "quimiostato3")
gtf_file="datos/sacCer_genes.gtf"
output_dir="qc_qualimap_hisat2"
for sample in "${samples[@]}"; do
    qualimap rnaseq -bam alignments_hisat2/output_${sample}.bam \
    -gtf $gtf_file \
    -outdir $output_dir/hisat2_${sample}_qualimap -p non-strand-specific
done
