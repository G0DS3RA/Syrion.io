import requests

API_KEY = 'your-api-key'
ENDPOINT = 'https://api.syrion.io/check'

data = {
    'ip': '192.168.1.1',
    'userAgent': 'Mozilla/5.0',
}

headers = {
    'Content-Type': 'application/json',
    'x-api-key': API_KEY,
}

response = requests.post(ENDPOINT, json=data, headers=headers)

if response.status_code == 200:
    print(response.json())
else:
    print(f"Error: {response.status_code}, {response.text}")
