#include <TimerOne.h>
#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH110X.h>

#define i2c_Address 0x3c

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels
#define OLED_RESET -1   
Adafruit_SH1106G display = Adafruit_SH1106G(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

int CNY = A0;
int led = 6;
int lectura;
int indicator = 2;
int i = 0;

void setup() {
  pinMode(led, OUTPUT);
  pinMode(indicator, OUTPUT);
  Timer1.initialize(4000000);
  Timer1.attachInterrupt(blinkLED); // blinkLED to run every 5 seconds
  Serial.begin(9600);

  delay(250); // wait for the OLED to power up
  display.begin(i2c_Address, true); // Address 0x3C default
 
  display.display();
  delay(2000);

  display.clearDisplay();

  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);

  delay(500);
  digitalWrite(indicator, HIGH);
  delay(800);
  digitalWrite(indicator, LOW);
  delay(800);

  display.setCursor(30, 30);
  display.println("AnemiX");
  display.display();
  delay(1500);
  display.clearDisplay();
  display.setTextSize(1.5);
  display.setCursor(30, 25);
  display.println("Midiendo Hb...");
  display.display();

  delay(10000);

  i = 1;

  
}

// The interrupt will blink the LED, and keep
// track of how many times it has blinked.
int ledState = LOW;
volatile unsigned long blinkCount = 0; // use volatile for shared variables

void blinkLED(void)
{
  if (ledState == LOW) {
    ledState = HIGH;
    blinkCount = blinkCount + 1;  // increase when LED turns on
  } else {
    ledState = LOW;
  }
  digitalWrite(led, ledState);
}


// The main program will print the blink count
// to the Arduino Serial Monitor
void loop() {
  lectura = analogRead(CNY);
  printText();
  //Serial.println(lectura);
  delay(1000);

  if (i=1) {
    exit(0);
  }
  
}

void printText() {
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SH110X_WHITE);
  display.setCursor(30, 30);
  display.println(lectura-1009);
  display.display();
}

  //HbO2 = (e2HHb_If*lectura_1-e1HHb_Red*lectura_2)/(L*(e2HHb_If*e1HbO2_Red-e1HHb_Red*e2HbO2));
  //HHb = (e2HbO2_If*lectura_1-e1HbO2_Red*lectura_2)/(L*(e1HHb_Red*e2HbO2_If-e2HHb_If*e1HbO2_Red));
  //hb = HbO2 + HHb;


