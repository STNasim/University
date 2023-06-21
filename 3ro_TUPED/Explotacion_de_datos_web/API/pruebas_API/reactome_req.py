import requests
import matplotlib.pyplot as plt

# Define the Ensembl IDs for the genes
ensembl_ids = {
    "TP53": "ENSG00000141510",
    "BRCA1": "ENSG00000012048",
    "EGFR": "ENSG00000146648",
    "TNF": "ENSG00000232810",
    "APOE": "ENSG00000130203",
    "IL6": "ENSG00000136244",
    "AKT1": "ENSG00000142208",
    "VEGFA": "ENSG00000112715",
    "MTHFR": "ENSG00000177000",
    "ESR1": "ENSG00000091831"
}

# Fetch gene information from the Reactome API
headers = {"Content-Type": "text/plain"}

genes_data = {}
for gene, ensembl_id in ensembl_ids.items():
    response = requests.post(f"https://reactome.org/AnalysisService/identifiers/projection",
                             headers=headers,
                             data=ensembl_id)
    genes_data[gene] = response.json()

# Extract the number of associated pathways for each gene
pathways_counts = {gene: len(data["pathways"]) for gene, data in genes_data.items()}

# Plot the number of associated pathways for each gene
plt.bar(pathways_counts.keys(), pathways_counts.values())
plt.xlabel("Genes")
plt.ylabel("Number of Associated Pathways")
plt.title("Number of Associated Pathways for TP53, BRCA1, and EGFR")
plt.show()