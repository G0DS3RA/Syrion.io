#!/bin/bash

# Replace 'your-api-key' with your actual API key
API_KEY="your-api-key"
ENDPOINT="https://api.syrion.io/check"

# JSON payload to send to the API
DATA=$(cat <<EOF
{
  "ip": "192.168.1.1",
  "userAgent": "Mozilla/5.0"
}
EOF
)

# Make the POST request to the Syrion Antibot API
curl -X POST "$ENDPOINT" \
     -H "Content-Type: application/json" \
     -H "x-api-key: $API_KEY" \
     -d "$DATA"
