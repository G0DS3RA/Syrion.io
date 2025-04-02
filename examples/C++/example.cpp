#include <iostream>
#include <string>
#include <curl/curl.h>

int main() {
    std::string api_key, ip_address;
    std::cout << "Enter your API key: ";
    std::cin >> api_key;
    std::cout << "Enter the IP address to check: ";
    std::cin >> ip_address;

    CURL *curl = curl_easy_init();
    if (curl) {
        std::string url = "https://api.syrion.io/check";
        std::string payload = "{\"ip\": \"" + ip_address + "\"}";

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        headers = curl_slist_append(headers, ("x-api-key: " + api_key).c_str());

        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload.c_str());
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << std::endl;
        }

        curl_easy_cleanup(curl);
    }
    return 0;
}
