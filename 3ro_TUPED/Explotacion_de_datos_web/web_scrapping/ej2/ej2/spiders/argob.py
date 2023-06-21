import scrapy
import json
from collections import Counter
import re

class UnerSpider(scrapy.Spider):
    name = 'argob'
    start_urls = ['https://www.argentina.gob.ar/']

    def parse(self, response):
        all_tags = response.xpath("//*").getall()
        tag_pattern = re.compile(r'<(/?\w+)')
        
        tag_counts = Counter(tag_pattern.match(tag).group(1) for tag in all_tags)

        # Save the results to a JSON file
        with open("tag_counts.json", "w") as f:
            json.dump(tag_counts, f)