#include <LiquidCrystal.h>

// Ultrasonic sensor
const int trigpin = 13; 
const int echopin = 12; 

// RGB LED
const int redpin = 2; 
const int greenpin = 3; 
const int bluepin = 4; 

// Buzzer
const int buzzerpin = 5; 

// LCD: RS=11, E=10, D4=9, D5=8, D6=7, D7=6
LiquidCrystal lcd(11, 10, 9, 8, 7, 6); 
float distance = 0.0; 
long duration = 0;
 
void setup()
{
  Serial.begin(9600);

  // Ultrasonic pins
  pinMode(trigpin, OUTPUT); 
  pinMode(echopin, INPUT);  

  // RGB pins 
  pinMode(redpin, OUTPUT); 
  pinMode(greenpin, OUTPUT); 
  pinMode(bluepin, OUTPUT);

  // buzzer pin 
  pinMode(buzzerpin, OUTPUT);

  // LCD
  lcd.begin(16, 2);
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Hello...");
}

void loop()
{ 
  // Measure distance
  digitalWrite(trigpin, LOW); 
  delayMicroseconds(2); 
  digitalWrite(trigpin, HIGH); 
  delayMicroseconds(10); 
  digitalWrite(trigpin, LOW);

  duration = pulseIn(echopin, HIGH); 
  distance = (duration / 2) * 0.0343; 

  // Show on LCD
  lcd.setCursor(0,1);
  lcd.print("                ");
  lcd.setCursor(0,1);

  if (distance > 40 || distance < 3)
  {
    Serial.println("out of range");  
    lcd.print("Out of Range");

    setcolor(0,0,0); 

    digitalWrite(buzzerpin, HIGH);
    delay(600); 
    digitalWrite(buzzerpin, LOW);
    delay(600);  
  }
  else 
  {
    Serial.print("Distance : "); 
    Serial.print(distance);
    Serial.println("cm"); 
    
    lcd.print("Distance: ");
    lcd.print(distance);
    lcd.print("cm");

    if (distance <= 10 && distance >= 3)
    {
      setcolor(255, 0, 0);   // Red
    } 
    else if (distance > 10 && distance <= 20)   
    {
      setcolor(0, 255, 0);   // Green
    }
    else if (distance > 20 && distance <= 30) 
    {
      setcolor(0, 0, 255);   // Blue
    }
    else 
    {
      setcolor(255, 255, 0); // Yellow
    }
  }
  delay(1000);
}

void setcolor(int R, int G, int B)
{
  digitalWrite(redpin, R > 0 ? HIGH : LOW);
  digitalWrite(greenpin, G > 0 ? HIGH : LOW);
  digitalWrite(bluepin, B > 0 ? HIGH : LOW);
}
