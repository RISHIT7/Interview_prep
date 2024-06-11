from concurrent.futures import ThreadPoolExecutor
from time import perf_counter
import requests

start = perf_counter()
urls = range(1, 100)

def get_data(url: int) -> dict:
    response = requests.get(f'https://httpbin.org/get?{url}')
    return response.json()

with ThreadPoolExecutor() as executor:
    executor.map(get_data, urls)
    
stop = perf_counter()
print(f"Time taken: {stop-start}")
# 14.957279958999607 seconds