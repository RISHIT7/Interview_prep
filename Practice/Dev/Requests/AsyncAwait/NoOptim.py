# synchronous
import requests
from time import perf_counter

def sync_request(urls: list[int]) -> None:
    for url in urls:
        response = requests.get(f'https://httpbin.org/get?{url}')
        # print(response.json())

start = perf_counter()
sync_request(range(1, 100))
stop = perf_counter()
print(f"Time taken: {stop-start}")
# 88.16490099400016 seconds