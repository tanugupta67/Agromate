#include<SoftwareSerial.h>
#include<WiFiClient.h>
#include<ESP8266HTTPClient.h>
#include<ThingSpeak.h>
#include <ESP8266WiFi.h>
SoftwareSerial ms(D1,D2);

// String URL = "https://api.thingspeak.com/update?api_key=ZVS472KDKZJEM6AB&field1=0";


WiFiClient client; // Here the client is NodeMCU and Thingspeak will act as a server.
long myChannelNumber = 2081669;
const char myWriteAPIKey[] = "ZVS472KDKZJEM6AB";
 


void setup() {
  // put your setup code here, to run once:
    Serial.begin(115200);
    ms.begin(9600);
    // WiFi.disconnect();
    delay(2000);
    Serial.print("Start connection");
   WiFi.begin("MananSuthar","12345678");
    while(WiFi.status() != WL_CONNECTED)
    {
        delay(200);
        Serial.println("...");
    }
    Serial.println("Connected");
    ThingSpeak.begin(client);

}

void loop() {
  // put your main code here, to run repeatedly:
      if(ms.available()>0)
      {
          String data = ms.readStringUntil('\n'); 
          Serial.println(data);
          int comma = data.indexOf(',');
          // int dash = data.indexOf('-');
          if(comma != -1)
          {
             float t = data.substring(0,comma).toFloat();
             float h = data.substring(comma+1).toFloat();
            //  float m = data.substring(dash+1).toFloat();
               
             Serial.println(t);
             Serial.println(h);
            //  Serial.println(m);
             ThingSpeak.writeField(myChannelNumber, 1, t, myWriteAPIKey);
             ThingSpeak.writeField(myChannelNumber, 2, h, myWriteAPIKey);
            //  ThingSpeak.writeField(myChannelNumber, 3, m, myWriteAPIKey);
          }
      }
      
 }


