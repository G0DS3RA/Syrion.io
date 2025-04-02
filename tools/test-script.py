import requests

def main():
    api_key = input("Enter your API key: ")
    ip_address = input("Enter the IP address to check: ")

    url = "https://api.syrion.io/check"
    headers = {
        "x-api-key": api_key,
        "Content-Type": "application/json"
    }
    payload = {
        "ip": ip_address
    }

    response = requests.post(url, json=payload, headers=headers)

    if response.status_code == 200:
        print("Response:", response.json())
    else:
        print("Error:", response.status_code, response.text)

if __name__ == "__main__":
    main()
