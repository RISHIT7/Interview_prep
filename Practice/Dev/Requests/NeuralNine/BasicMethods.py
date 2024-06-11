import requests

response = requests.get('https://httpbin.org/get')

# params
params = {
    "name": "Rishit",
    "age": 19
}
response = requests.get('https://httpbin.org/get', params = params)
print(response.url)

print(response.status_code)

print(response.text)
print(response.json())

# post request
payload = {
    "name": "Rishit",
    "age": 19
}

response = requests.post('https://httpbin.org/post', data=payload)
print(response.url)

print(response.status_code)

print(response.text)
print(response.json())