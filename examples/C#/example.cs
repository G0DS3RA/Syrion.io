using System;
using System.Net.Http;
using System.Text;
using System.Threading.Tasks;

class Program
{
    static async Task Main(string[] args)
    {
        Console.Write("Enter your API key: ");
        string apiKey = Console.ReadLine();
        Console.Write("Enter the IP address to check: ");
        string ipAddress = Console.ReadLine();

        string url = "https://api.syrion.io/check";
        var payload = new { ip = ipAddress };
        var json = System.Text.Json.JsonSerializer.Serialize(payload);

        using (var client = new HttpClient())
        {
            client.DefaultRequestHeaders.Add("x-api-key", apiKey);
            var content = new StringContent(json, Encoding.UTF8, "application/json");
            var response = await client.PostAsync(url, content);

            string result = await response.Content.ReadAsStringAsync();
            Console.WriteLine("Response: " + result);
        }
    }
}
