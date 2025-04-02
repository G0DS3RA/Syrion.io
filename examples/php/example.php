<?php

$apiKey = 'your-api-key';
$endpoint = 'https://api.syrion.io/check';

$data = [
    'ip' => '192.168.1.1',
    'userAgent' => $_SERVER['HTTP_USER_AGENT'],
];

$options = [
    'http' => [
        'header' => "Content-Type: application/json\r\n" .
                    "x-api-key: $apiKey\r\n",
        'method' => 'POST',
        'content' => json_encode($data),
    ],
];

$context = stream_context_create($options);
$response = file_get_contents($endpoint, false, $context);

if ($response === false) {
    die('Error contacting Syrion Antibot API.');
}

$result = json_decode($response, true);
print_r($result);
