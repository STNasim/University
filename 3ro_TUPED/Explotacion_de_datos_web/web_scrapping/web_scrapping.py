import csv
import requests
from bs4 import BeautifulSoup
import pandas as pd

# URL to be scraped
url = 'https://www.worldometers.info/world-population/population-by-country/'

# Get the HTML content
html_content = requests.get(url).text

# Parse the HTML content
soup = BeautifulSoup(html_content)

# Extract the table
table = soup.find_all('table') [0]

# extract the first data of the HTML

df_population = pd.read_html(str(table))[0]

# show the first elements

print(df_population.head())

# Save the data in a CSV file

df_population.to_csv('population.csv', index=False)

