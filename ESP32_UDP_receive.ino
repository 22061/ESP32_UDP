#include <WiFi.h>
#include <WiFiUdp.h>

const char ssid[] = "ESP32_Server";       // SSID
const char password[] = "1234567890";     // password
const int localPort = 64211;              // ポート番号
const IPAddress ip(192, 168, 1, 2);       // ServerのIPアドレス
const IPAddress gateway(192, 168, 1, 2);  // gatewayのIPアドレス
const IPAddress subnet(255, 255, 255, 0); // サブネットマスク

WiFiUDP udp;
char packetBuffer[256];
int packetSize;
int i;

void setup() 
{
  Serial.begin(115200);

  WiFi.softAP(ssid, password);
  delay(100);
  WiFi.softAPConfig(ip, gateway, subnet);

  udp.begin(localPort);
}

void loop() 
{
  packetSize = udp.parsePacket();
  if (packetSize) 
  {
    for (i = 0 ; i < 256 ; i++) 
    {
      packetBuffer[i] = 0;
    }
    udp.read(packetBuffer, 256);
    Serial.println(packetBuffer);
  }
}