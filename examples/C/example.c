#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

int main() {
    char api_key[256], ip_address[256];
    printf("Enter your API key: ");
    scanf("%255s", api_key);
    printf("Enter the IP address to check: ");
    scanf("%255s", ip_address);

    CURL *curl = curl_easy_init();
    if (curl) {
        char url[] = "https://api.syrion.io/check";
        char payload[512];
        snprintf(payload, sizeof(payload), "{\"ip\": \"%s\"}", ip_address);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        char auth_header[512];
        snprintf(auth_header, sizeof(auth_header), "x-api-key: %s", api_key);
        headers = curl_slist_append(headers, auth_header);

        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, payload);
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            fprintf(stderr, "curl_easy_perform() failed: %s\n", curl_easy_strerror(res));
        }

        curl_easy_cleanup(curl);
    }
    return 0;
}
