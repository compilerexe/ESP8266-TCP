#include <ESP8266WiFi.h>
#include <WiFiServer.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <AsciiToString.h>

#define MAX_CLIENTS 1 // Telnet client 

/*=== Variable WiFi ===*/
const char* ssid = "__Your__SSID__";
const char* password = "__Your__SSID__";
const char* wifi_ip[4] = {"192", "168", "0", "200"};
const char* wifi_subnet[4] = {"255", "255", "255", "0"};
const char* wifi_gateway[4] = {"192", "168", "0", "1"};

/*=== WiFiAccessPoint ===*/
const char* ssidAP = "__Your__WiFi__AP__";
const char* ssidPass = "";

/*=== Variable WebServer ===*/
String get_name;
String get_value;
String get_url;

uint8_t pin = 15;

AsciiToString ascii_str;
WiFiServer server_telnet(23);
WiFiClient serverClients[MAX_CLIENTS];

ESP8266WebServer server(80);

void WiFi_Config() {
  WiFi.begin(ssid, password);
  WiFi.config(
    IPAddress(atoi(wifi_ip[0]), atoi(wifi_ip[1]), atoi(wifi_ip[2]), atoi(wifi_ip[3])),
    IPAddress(atoi(wifi_gateway[0]), atoi(wifi_gateway[1]), atoi(wifi_gateway[2]), atoi(wifi_gateway[3])),
    IPAddress(atoi(wifi_subnet[0]), atoi(wifi_subnet[1]), atoi(wifi_subnet[2]), atoi(wifi_subnet[3]))
  );
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

/*=== TELNET ===*/
void telnet_server() {

  uint8_t i;
  server_telnet.begin();
  server_telnet.setNoDelay(true);

  if (server_telnet.hasClient()) {
    for (i = 0; i < MAX_CLIENTS; i++) {
      if (!serverClients[i].connected()) {
        if (serverClients[i]) {
          serverClients[i].stop();
        }
        serverClients[i] = server_telnet.available();
        Serial.print("Telnet client id : ");
        Serial.print(i);
      }
    }
    Serial.println();
  }

  for (i = 0; i < MAX_CLIENTS; i++) {
    if (serverClients[i].connected()) {
      while (serverClients[i].available()) {
        ascii_str.getString(serverClients[i].read());
        if (ascii_str.message == "on") {

          Serial.println("TELNET : ON");
          digitalWrite(pin, HIGH);
          ascii_str.clear();

        } else if (ascii_str.message == "off") {

          Serial.println("TELNET : OFF");
          digitalWrite(pin, LOW);
          ascii_str.clear();

        }
      }
    }
  }

}/*===== END TELNET =====*/

void WebServer_Config() {
  server.on("/", webserver_display);
  server.begin();
  Serial.println("HTTP server started");
}

void webserver_display() {
  server.send(200, "text/html", "WAITING HTTP GET / TELNET TCP ...");
  get_name = server.argName(0);
  get_value = server.arg(0);
  get_url = get_name;
  get_url += ":";
  get_url += get_value;

  if (get_url == "on:1") {
    digitalWrite(pin, HIGH);
    Serial.println("HTTP GET : ON");
  } else if (get_url == "on:0") {
    digitalWrite(pin, LOW);
    Serial.println("HTTP GET : OFF");
  }
}

void WiFi_AP() {
  WiFi.softAP(ssidAP);
  Serial.print("WiFi AP : ");
  Serial.print(ssidAP);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("WiFi AP Success");
  IPAddress myIP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(myIP);
}

void setup(void) {
  Serial.begin(115200);
  pinMode(pin, OUTPUT);
  WiFi_Config();
  WiFi_AP();
  WebServer_Config();
}

void loop(void) {

  server.handleClient();
  telnet_server();
  delay(500);

}
