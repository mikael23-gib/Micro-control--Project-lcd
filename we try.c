#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LED_PIN PC13
#define LCD_ADDR 0x27 // Change to 0x3F if needed

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

void setup() {
    pinMode(LED_PIN, OUTPUT);
    lcd.init();
    lcd.backlight();
    lcd.setCursor(0, 0);
    lcd.print("Hello World!");
}

void loop() {
    digitalWrite(LED_PIN, HIGH);
    delay(300);
    digitalWrite(LED_PIN, LOW);
    delay(300);
}
