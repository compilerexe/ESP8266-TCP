#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ESP8266WebServer.h>
#include <ESP8266mDNS.h>
#include <WiFiServer.h>

/*=================== Variable WiFi ===================*/
const char* ssid = "OpenWrt_NAT_500GP.101";
const char* password = "activegateway";
const char* wifi_ip[11] = {"192","168","101","200"};
const char* wifi_subnet[11] = {"255","255","255","0"};
const char* wifi_gateway[11] = {"192","168","101","1"};
/*=====================================================*/

/*=================  Variable WebServer ===============*/
String get_name;
String get_value;
String get_url;
/*=====================================================*/

WiFiServer server_telnet(23);
ESP8266WebServer server(80);

void wifi_config(){
  WiFi.begin(ssid, password);
  WiFi.config(
    IPAddress(atoi(wifi_ip[0]),atoi(wifi_ip[1]),atoi(wifi_ip[2]),atoi(wifi_ip[3])),
    IPAddress(atoi(wifi_gateway[0]),atoi(wifi_gateway[1]),atoi(wifi_gateway[2]),atoi(wifi_gateway[3])),
    IPAddress(atoi(wifi_subnet[0]),atoi(wifi_subnet[1]),atoi(wifi_subnet[2]),atoi(wifi_subnet[3]))
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

void telnet_server(){
  server_telnet.begin();
  Serial.println("Telnet connection ");
  
  while (!server_telnet.available()) {
    Serial.print(".");
    delay(500);
  }
  
  Serial.println();
  Serial.println("have a new client");

  

}

void webserver_config(){
  server.on("/", webserver_display);
  server.begin();
  Serial.println("HTTP server started");
}

void webserver_display() {
  server.send(200, "text/plain", "WAITING HTTP GET / TELNET TCP ...");
}

void setup(void){
  Serial.begin(115200);
  wifi_config();
  webserver_config();
  telnet_server();
}

void loop(void){
  
  server.handleClient();

  get_name = server.argName(0);
  get_value = server.arg(0);
  get_url = get_name;
  get_url += " : ";
  get_url += get_value;
  
  if (get_url == "on : 1") {
      Serial.println("work");
  }
  
  delay(500);
  
} 
