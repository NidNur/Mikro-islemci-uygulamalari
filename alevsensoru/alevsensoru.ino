#define BLYNK_TEMPLATE_ID "TMPLjObdfSj4"
#define BLYNK_DEVICE_NAME "AlevDedektor"
#define BLYNK_AUTH_TOKEN "s8o5iHidZmtIA4PLooFe_GgVXF2siSui"

char auth[] = "s8o5iHidZmtIA4PLooFe_GgVXF2siSui"; //
char ssid[] = "Alaska"; //Wifi Isminizi buraya yazin
char pass[] = "alaska1234"; //Wifi sifrenizi buraya yazin

#include <SPI.h>
#include <BlynkSimpleEsp8266.h> 

#define alevpin (A0)
#define BLYNK_PRINT Serial
#define buzzerPin 0 
#define GreenLed 14 
#define RedLed 12 
#define Water 5 
#define Wateriki 4 


BlynkTimer timer;

float sensorDegeri;

int n,m;

void setup()
{

  Serial.begin(9600);
  Serial.println("Gas sensor warming up!");  
  delay(5000);

  Blynk.begin(auth, ssid, pass);
 
  pinMode(Water, OUTPUT);
  pinMode(Wateriki, OUTPUT);
  pinMode(GreenLed, OUTPUT);
  pinMode(RedLed, OUTPUT);
  pinMode(16,OUTPUT);
  pinMode(buzzerPin,OUTPUT);
  pinMode(alevpin, INPUT);

  digitalWrite(GreenLed, LOW);
  digitalWrite(RedLed, LOW);
  timer.setInterval(1000L, sendUptime);
}


void sendUptime()
{
  Blynk.virtualWrite(V2, sensorDegeri);  
  
}

void loop()
{
  
  sensorDegeri = analogRead(alevpin); 
  Serial.println("");
  Serial.print("Sensor Degeri: ");
  Serial.print(sensorDegeri);
  Serial.println("");
  Serial.println("");
  Serial.print("alev: ");
  Serial.print(A0);
  Serial.println("");
  Blynk.virtualWrite(V2, sensorDegeri);
  if(sensorDegeri < 700 )
  {
    Serial.print("fire detected!");
    digitalWrite(Water, HIGH);
    digitalWrite(Wateriki, LOW);
    delay(2000);
  }
  
  
  n=analogRead(A0);

  if(n>900)
  {
  
    n==m;
    m=analogRead(A0);
    Serial.println(m);
    
  }
  if(n<700 && n<900)
  {
    digitalWrite(buzzerPin, LOW);
    digitalWrite(RedLed, HIGH); 
    digitalWrite(Water, HIGH);
    digitalWrite(Wateriki, LOW);
    digitalWrite(GreenLed, LOW);
    digitalWrite(Water, HIGH);
    tone(buzzerPin,800,80);
    delay(2000);  
  }
  
  if(n>700)
  {
      digitalWrite(GreenLed,HIGH );
      digitalWrite(buzzerPin,LOW);
       digitalWrite(Water,LOW);
      digitalWrite(Wateriki,LOW);
      digitalWrite(RedLed,LOW);
      delay(2000);
      noTone(buzzerPin);
  }

  Blynk.run();
}