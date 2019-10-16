#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2);

//es para 
const int QRD1114 = A0;
int tension;
const int umbral = 120;
int voltaje;

void setup() {
 lcd.init(); 
 lcd.backlight();
 lcd.print("Hola,iniciando");
 Serial.begin(9600);
}

void loop() {
  tension = analogRead(QRD1114);
  Serial.println(tension);
  voltaje = map(tension, 1024,0,3.3,0);
  Serial.println(voltaje);
  Serial.println(" ");
  if(tension > umbral)
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("objeto");
    lcd.setCursor(0,1);
    lcd.print("detectado");
  }
  else
  {
    lcd.clear();
    lcd.setCursor(0,0);
    lcd.print("objeto");
    lcd.setCursor(0,1);
    lcd.print("no detectado");
  }
  delay(1000);
}
