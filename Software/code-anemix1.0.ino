#include <Adafruit_LiquidCrystal.h>

int led = 2; 
int led_ir = 4;
int photodio = A0;
int lectura = 0;
double hb = 9 ;


Adafruit_LiquidCrystal lcd(0);

void setup()
{
 //pinMode(LED_BUILTIN, OUTPUT);
  pinMode (led, OUTPUT);
  pinMode (led_ir, OUTPUT);
  pinMode (photodio, INPUT);
  lcd.begin(16, 2);
  lcd.setCursor(5, 0);
  lcd.print("ANEMIX");
  delay(3000);
  lcd.clear();
  lcd.print("Midiendo");
  lcd.setCursor(0,1);
  lcd.print("concentracion... ");
  delay(1500);
  digitalWrite(led, HIGH);
  digitalWrite(led_ir, HIGH);
 
Serial.begin(9600);
 }

void loop()
{
  lectura = analogRead(photodio);
  Serial.println(lectura);
  
  //codigo hemoglobina
  //double lectura_1 = 0;
  //double lectura_2 = 0;
  //double HbO2 = 0;
  //double HHb = 0;
  //double L; 
  //double e1HHb_660nm;
  //double e2HHb_660nm;
  //double e1HbO2_940nm;
  //double e2HbO2_940nm;
  
  //HbO2 = (e2HHb*lectura_1-e1HHb*lectura_2)/L*(e2HHb*e1HbO2-e1HHb*e2HbO2);
  //HHb = (e2HbO2*lectura_1-e1HbO2*lectura_2)/L*(e1HHb*e2HbO2-e2HHb*e1HbO2);
  //hb = HbO2 + HHb;
  
  lcd.clear();
  lcd.print(hb), lcd.print(" g/dL");
  delay(2000);
  lcd.clear();
  
  if (hb < 11.5) {
  
  lcd.print("Bajo nivel");
  lcd.setCursor(0,1);
  lcd.print("de Hb");
  }
            
  else {
    lcd.print("Nivel seguro");
  }         
  delay(3000);
  //digitalWrite(LED_BUILTIN, HIGH);
  //delay(1000); // Wait for 1000 millisecond(s)
  //digitalWrite(LED_BUILTIN, LOW);
  //delay(1000); // Wait for 1000 millisecond(s) 
}


