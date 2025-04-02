require 'net/http'
require 'json'

puts "Enter your API key:"
api_key = gets.chomp
puts "Enter the IP address to check:"
ip_address = gets.chomp

url = URI("https://api.syrion.io/check")
http = Net::HTTP.new(url.host, url.port)
http.use_ssl = true

request = Net::HTTP::Post.new(url)
request["x-api-key"] = api_key
request["Content-Type"] = "application/json"
request.body = { ip: ip_address }.to_json

response = http.request(request)
puts "Response: #{response.body}"
