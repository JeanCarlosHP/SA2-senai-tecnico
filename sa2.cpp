#include <WiFi.h>
#include <HTTPClient.h>

const char* ssid = "Wokwi-GUEST";
const char* password = "";

const String api_key = "MLNMDOUG0W1I3I1E";

void setup() {
  Serial.begin(9600);
  Serial.print("Connecting to WiFi");
  WiFi.begin(ssid, password, 6);
  while (WiFi.status() != WL_CONNECTED) {
    delay(100);
    Serial.print(".");
  }
  Serial.println("\nConnected!");

}

void loop() {
  // Simula um sensor de temperatura em graus celsius
  int temperature = random(30);

  HTTPClient http;

  String url = "https://api.thingspeak.com/update?api_key=" + api_key + "&field1=" + temperature;
  http.begin(url);
  int httpCode = http.GET();

  if (httpCode == 200) {
    Serial.println("Temperatura armazenada: " + temperature);
  }
  
  delay(100);
}
