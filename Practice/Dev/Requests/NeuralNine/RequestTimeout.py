import requests

# response = requests.get('https://httpbin.org/delay/3', timeout=1)
# response = requests.get('https://httpbin.org/delay/3')

for _ in range(5):
    try:
        response = requests.get('https://httpbin.org/delay/3', timeout=1)
        print(response)
    except requests.exceptions.Timeout as e:
        print(e)
    except requests.exceptions.RequestException as e:
        print(e)

print(response.text)
print(response.status_code)
print(response.elapsed.total_seconds())
print(response.json())