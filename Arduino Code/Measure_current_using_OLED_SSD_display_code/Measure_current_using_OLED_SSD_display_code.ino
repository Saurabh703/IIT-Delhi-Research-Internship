#define VT_PIN A0 
#define AT_PIN A1

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for SSD1306 display connected using software SPI (default case):
#define OLED_MOSI   9
#define OLED_CLK   10
#define OLED_DC    11
#define OLED_CS    13
#define OLED_RESET 12
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT,
  OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);


  
void setup()
{
  Serial.begin(9600);
  display.begin(SSD1306_SWITCHCAPVCC);
  display.clearDisplay();

  
  
}
void loop()
{
  int vt_read = analogRead(VT_PIN);
  int at_read = analogRead(AT_PIN);
delay(0);
  float voltage = vt_read * (5.0 / 1024.0) * 5.0;
  float current = at_read * (5.0 / 1024.0) * 2.0;
  float watts = voltage * current;
  float currentini = 0;
float currentadd = currentini + current;


delay(500);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 20);
  display.println("Voltage");
  display.setCursor(50, 20);
  display.println(voltage);
  display.setCursor(75, 20);
  display.println("V");
  display.setCursor(0, 30);
  display.println("Current");
  display.setCursor(50, 30);
  display.println(current);
  display.setCursor(75, 30);
  display.println("mA");
  display.setCursor(0, 40);
  display.println("Wattage");
  display.setCursor(50, 40);
  display.println(watts);
  display.setCursor(75, 40);
  display.println("mWh");
  
  display.display();
}
