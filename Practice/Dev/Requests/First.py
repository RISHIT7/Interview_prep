import requests

url = 'https://www.google.com'
r = requests.get(url)
print(r.status_code)
print(r.headers)
print(r.encoding)
print(r.json())
