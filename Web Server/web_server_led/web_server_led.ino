#include <ESP8266WiFi.h>
const char* ssid = "ssid";
const char* password = "password";
int ledPin = 2; // GPIO13
WiFiServer server(80);
void setup() {
  Serial.begin(115200);
  delay(10); 
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);   // Connect to WiFi network
  Serial.println();
  Serial.println();
  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");
  server.begin();       // Start the server
  Serial.println("Server started");
  Serial.print("Use this URL to connect: ");
  Serial.print("http://");
  Serial.print(WiFi.localIP()); // Print the IP address
  Serial.println("/");
}
void loop() {
  WiFiClient client = server.available();   // Check if a client has connected
  if (!client) {
    return;
  }
  Serial.println("new client");
  while(!client.available()){     // Wait until the client sends some data
    delay(1);
  }
  String request = client.readStringUntil('\r');    // Read the first line of the request
  Serial.println(request);
  client.flush();
  if (request.indexOf("/LED=ON") != -1)  {
    digitalWrite(ledPin, LOW);
  }
  if (request.indexOf("/LED=OFF") != -1)  {
    digitalWrite(ledPin, HIGH);
  }
  client.println("<a href=\"/LED=ON\"><button>Turn On </button></a>");
  client.println("<a href=\"/LED=OFF\"><button>Turn Off </button></a>");
  delay(1);
  Serial.println("Client disonnected");
  Serial.println("");
}
