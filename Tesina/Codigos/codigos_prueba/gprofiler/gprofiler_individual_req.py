import requests

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

api_url = "https://biit.cs.ut.ee/gprofiler/api/gost/profile/"
headers = {"Content-Type": "application/json"}

for ensembl_id in ensembl_ids:
    payload = {
        "organism": "hsapiens",
        "query": [ensembl_id],
        "sources": ["GO:BP"],
        "user_threshold": 0.05,
        "all_results": False,
        "ordered": False,
        "no_iea": False,
        "combined": True,
        "measure_underrepresentation": False,
        "domain_scope": "annotated",
        "significance_threshold_method": "fdr",
        "background": [],
        "numeric_namespace": "ENTREZGENE_ACC",
    }

    response = requests.post(api_url, json=payload, headers=headers)
    results = response.json()

    print(f"Gene: {ensembl_id}")
    if "result" in results:
        for result in results["result"]:
            print(f"{result['native']} ({result['name']}): p-value: {result['p_values']}")
    else:
        print("No significant terms were found.")
    print("\n")