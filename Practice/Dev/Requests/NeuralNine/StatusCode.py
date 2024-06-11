import requests

response = requests.get('https://httpbin.org/status/404')
print(response.status_code)

if response.status_code == requests.codes.not_found:
    print("Not found")
else:
    print(response.status_code)