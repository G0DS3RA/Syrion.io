package main

import (
    "bytes"
    "encoding/json"
    "fmt"
    "net/http"
    "os"
)

func main() {
    var apiKey, ipAddress string
    fmt.Print("Enter your API key: ")
    fmt.Scanln(&apiKey)
    fmt.Print("Enter the IP address to check: ")
    fmt.Scanln(&ipAddress)

    url := "https://api.syrion.io/check"
    payload := map[string]string{"ip": ipAddress}
    payloadBytes, _ := json.Marshal(payload)

    req, _ := http.NewRequest("POST", url, bytes.NewBuffer(payloadBytes))
    req.Header.Set("x-api-key", apiKey)
    req.Header.Set("Content-Type", "application/json")

    client := &http.Client{}
    resp, err := client.Do(req)
    if err != nil {
        fmt.Println("Error:", err)
        os.Exit(1)
    }
    defer resp.Body.Close()

    fmt.Println("Response Status:", resp.Status)
}
