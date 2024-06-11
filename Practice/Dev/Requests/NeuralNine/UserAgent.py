import requests

response = requests.get('https://httpbin.org/user-agent')
print(response.text)

# manully specifying the user-agent, to change the behaviour of the server
headers = {
    "User-Agent": "Rishit"
}
response = requests.get('https://httpbin.org/user-agent', 
                        headers=headers)
print(response.text)