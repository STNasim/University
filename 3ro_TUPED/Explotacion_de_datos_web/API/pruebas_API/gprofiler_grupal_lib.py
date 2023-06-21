from gprofiler import GProfiler

ensembl_ids = [
    "ENSG00000141510",
    "ENSG00000012048",
    "ENSG00000146648",
    "ENSG00000232810",
    "ENSG00000130203",
    "ENSG00000136244",
    "ENSG00000142208",
    "ENSG00000112715",
    "ENSG00000177000",
    "ENSG00000091831"
]

gp = GProfiler(user_agent="ExampleTool", return_dataframe=True)

results = gp.profile(
        organism='hsapiens',
        query=ensembl_ids,
        sources=["GO:BP"],
        user_threshold=0.05,
        all_results=False,
        ordered=False,
        no_iea=False,
        combined=True,
        measure_underrepresentation=False,
        domain_scope="annotated",
        significance_threshold_method="fdr",
        numeric_namespace="ENTREZGENE_ACC"
    )

if not results.empty:
    for _, result in results.iterrows():
        print(f"{result['native']} ({result['name']}): p-value: {result['p_values']}")
else:
    print("No significant terms were found.")