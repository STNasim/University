import pandas as pd
from urllib.request import urlopen
from bs4 import BeautifulSoup
import plotly.express as px
import dash
from dash import dcc, html
from dash.dependencies import Input, Output
import plotly.graph_objects as go

url = "https://www.hubertiming.com/results/2016GPTR"
html_texto = urlopen(url)

soup = BeautifulSoup(html_texto, 'lxml')

# Titulo
title = soup.title

# Datos
list_rows = []
rows = soup.find_all('tr')
for row in rows:
    row_td = row.find_all('td')
    str_cells = str(row_td)
    cleantext = BeautifulSoup(str_cells, "lxml").get_text()
    #remove all empty spaces, \r and \n from clean text
    cleantext = cleantext.replace('\r', '').replace('\n', '').replace('  ', '')
    list_rows.append(cleantext)

df = pd.DataFrame(list_rows)

df1 = df[0].str.split(',', expand=True)
df1[0] = df1[0].str.strip('[')
#Headers
col_labels = soup.find_all('th')
all_header = []
col_str = str(col_labels)
cleantext2 = BeautifulSoup(col_str, "lxml").get_text()
cleantext2 = cleantext2.replace(', ', ',')
all_header.append(cleantext2)

df2 = pd.DataFrame(all_header)

df3 = df2[0].str.split(',', expand=True)
df3[0] = df3[0].str.strip('[')
frames = [df3, df1]

df4 = pd.concat(frames)
df4[7] = df4[7].str.strip(']')
df5 = df4.rename(columns=df4.iloc[0])

df6 = df5.dropna(axis=0, how='any')

df7 = df6.drop(df6.index[0])

df = df7
df['Place'] = pd.to_numeric(df['Place'], errors='coerce')

#graficación

app = dash.Dash(__name__)

app.layout = html.Div([
    html.H1("Runners Dashboard"),
    dcc.Dropdown(id="gender_dropdown",
                 options=[{'label': gender, 'value': gender} for gender in df['Gender'].unique()],
                 value='M',
                 multi=False,
                 clearable=False,
                 style={'width': "50%"}),
    dcc.Graph(id='bar_chart')
])

def create_city_color_map(df, color_palette):
    city_list = df['City'].unique()
    color_map = {}
    for i, city in enumerate(city_list):
        color_map[city] = color_palette[i % len(color_palette)]
    return color_map


@app.callback(
    Output(component_id='bar_chart', component_property='figure'),
    [Input(component_id='gender_dropdown', component_property='value')]
)

def update_graph(selected_gender):
    filtered_df = df[df['Gender'] == selected_gender]
    filtered_df['Place'] = pd.to_numeric(filtered_df['Place'])
    filtered_df = filtered_df.sort_values(by='Place')

    # Create a unique label for each bar by concatenating 'Name' and 'Place' columns
    filtered_df['Name_Bib'] = filtered_df['Name'] + ' - ' + filtered_df['Bib'].astype(str)

    # Create a custom color scale for the 'City' column
    color_map = create_city_color_map(filtered_df, px.colors.qualitative.Dark24)

    # Initialize a Plotly Figure
    fig = go.Figure()

    # Iterate over the filtered DataFrame and create a trace for each row
    for index, row in filtered_df.iterrows():
        fig.add_trace(go.Bar(x=[row['Name_Bib']], y=[row['Place']], text=[row['Time']],
                             marker_color=color_map[row['City']], name=row['City'],
                             legendgroup=row['City'], showlegend=row['City'] not in [trace.name for trace in fig.data]))

    # Set the title and layout options
    fig.update_layout(title='Runners by Gender', xaxis_title='Name - Place', yaxis_title='Place', height=800)

    return fig

if __name__ == '__main__':
    app.run_server(debug=True)