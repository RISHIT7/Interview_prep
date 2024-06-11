import requests

proxies = {
    "http": "139.99.237.62:80",
    "https": "139.99.237.62:80"
}

reponse = requests.get('http://httpbin.org/get', 
                       proxies=proxies)

print(reponse.text)
