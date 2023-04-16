/*#include<DHT.h>
#define dhtPin 2
#define dhtType DHT11

DHT dht(dhtPin,dhtType);

void setup() {
  // put your setup code here, to run once:
    Serial.begin(9600);
    dht.begin();
}

void loop() {
  // put your main code here, to run repeatedly:
    // Serial.println("Hello World!");
    float temp = dht.readTemperature();
    float h = dht.readHumidity();

    if(isnan(temp) || isnan(h))
    {
       Serial.println("No data available");
    }

    // Serial.print("Temperature ");    
    Serial.print(temp);    
    // Serial.print("Humidty");    
    Serial.print(",");
    Serial.print(h);
    Serial.println();    
    


    delay(1000);
}
*/

#include "DHT.h"
#define DHTPIN 8     // what pin we're connected to
#define DHTTYPE DHT11   // DHT 11 
#define pwm 9
int m_s = A0;
DHT dht(DHTPIN, DHTTYPE);

void setup() {
 analogWrite(pwm, 255);
//  delay(2000);
pinMode(13,OUTPUT);
 Serial.begin(9600); 
 dht.begin();

}

void loop() {
  // Wait a few seconds between measurements.
  delay(2000);

  // Reading temperature or humidity takes about 250 milliseconds!
  // Sensor readings may also be up to 2 seconds 'old' (its a very slow sensor)
  float h = dht.readHumidity();
  // Read temperature as Celsius
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit
  float f = dht.readTemperature(true);
  
  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }

 
 /* // Serial.print("Humidity: "); 
  Serial.print(h);
  Serial.print(" %\t");
  // Serial.print("temperature: "); 
  Serial.print(t);
  // Serial.print(" *C ");
  Serial.println();*/

  if(t <20 )
    { 
       digitalWrite(pwm, 255);
       delay(100);
    }
    
    else if(t>=20 && t<30)
    {             
      digitalWrite(pwm, 135);
      delay(100);
    }
    
    else
    {
      digitalWrite(pwm, 0);
      delay(100);
    }

    int Moisture = 0;
    Moisture = analogRead(m_s);
    Serial.print("Temperature: ");
    Serial.println(t);    
    Serial.print("Humidty: ");    
    Serial.println(h);
    // Serial.print("-");    
    Serial.print("Soil Moisture Level: ");
    Serial.println(Moisture);
     Serial.println();
    if(Moisture>300)
     {
      analogWrite(13,HIGH);
    }
    else {
      analogWrite(13,LOW);
    }

}                 


