import requests

headers = {
    "User-Agent": "Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/58.0.3029.110 Safari/537.3",
    "Accept": "text/html,application/xhtml+xml,application/xml;q=0.9,image/webp,image/png,*/*;q=0.8"
}

response = requests.get('https://httpbin.org/headers', 
                        headers=headers)

print(response.text)

# saving as file
with open("myimage.webp", "wb") as f:
    f.write(response.content)