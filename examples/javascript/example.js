const fetch = require('node-fetch');

const apiKey = 'your-api-key';
const endpoint = 'https://api.syrion.io/check';

const data = {
    ip: '192.168.1.1',
    userAgent: 'Mozilla/5.0',
};

fetch(endpoint, {
    method: 'POST',
    headers: {
        'Content-Type': 'application/json',
        'x-api-key': apiKey,
    },
    body: JSON.stringify(data),
})
    .then((response) => response.json())
    .then((result) => console.log(result))
    .catch((error) => console.error('Error:', error));
