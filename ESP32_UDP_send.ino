#include <WiFi.h>
#include <WiFiUdp.h>

const char ssid[] = "ESP32_Server";    // SSID
const char password[] = "1234567890";  // password

static WiFiUDP wifiUdp;
static const char *Destination_IPAddress = "192.168.1.2";  //送信先のIPアドレス
static const int Destination_UdpPort = 64211;           //送信先のポート番号
static const int localPort = 64212;               //自身のポート番号
int i = 0;
bool flag = true;

void setup() 
{
  Serial.begin(115200);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) 
  {
    i++;
    if (i > 30) 
    {
      flag = false;
      break;
    }
    delay(500);
  }
  if (flag == true) 
  {
    wifiUdp.begin(localPort);
  } 
}

void loop()
{
  if (flag == true) 
  {
    wifiUdp.beginPacket(Destination_IPAddress, Destination_UdpPort);
    wifiUdp.print("test data"); 
    wifiUdp.endPacket();
  }
  delay(50);
}