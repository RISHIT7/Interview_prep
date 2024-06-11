import requests
import asyncio, aiohttp
from time import perf_counter

async def fetch(s, url):
    async with s.get(f'https://httpbin.org/get?{url}') as response:
        if response.status != 200:
            response.raise_for_status()
        return await response.json()

async def fetch_all(s, urls):
    tasks = []
    for url in urls:
        task = asyncio.create_task(fetch(s, url))
        tasks.append(task)
    res = await asyncio.gather(*tasks)
    return res

async def main():
    urls = range(1, 100)
    async with aiohttp.ClientSession() as session:
        htmls = await fetch_all(session, urls)
        print(htmls)

if __name__ == "__main__":
    start = perf_counter()
    asyncio.run(main())
    end = perf_counter()
    print(f"Time taken: {end - start}")
    # 2.5679320280005413 seconds