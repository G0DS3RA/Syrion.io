use reqwest::blocking::Client;
use std::io;

fn main() {
    let mut api_key = String::new();
    let mut ip_address = String::new();

    println!("Enter your API key:");
    io::stdin().read_line(&mut api_key).unwrap();
    println!("Enter the IP address to check:");
    io::stdin().read_line(&mut ip_address).unwrap();

    let client = Client::new();
    let url = "https://api.syrion.io/check";
    let payload = serde_json::json!({ "ip": ip_address.trim() });

    let response = client
        .post(url)
        .header("x-api-key", api_key.trim())
        .json(&payload)
        .send();

    match response {
        Ok(resp) => println!("Response: {:?}", resp.text().unwrap()),
        Err(err) => println!("Error: {:?}", err),
    }
}
