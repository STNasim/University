import json
import plotly.graph_objects as go
import plotly.io as pio

# Load the tag counts from the JSON file
with open("tag_counts.json", "r") as f:
    tag_counts = json.load(f)

# Separate the tags and their counts
tags = list(tag_counts.keys())
counts = list(tag_counts.values())

# Create the bar chart
fig = go.Figure(go.Bar(x=counts, y=tags, orientation="h"))

# Customize the chart's appearance
fig.update_layout(
    title="HTML Tag Frequencies",
    xaxis_title="Frequency",
    yaxis_title="Tag",
    yaxis=dict(autorange="reversed"),
)

# Show the chart
pio.write_html(fig, file="tag_frequencies.html", auto_open=True)