#include <Wire.h>
#include <LiquidCrystal_I2C.h>

#define LED_PIN PC13
#define LCD_ADDR 0x27 // Change to 0x3F if needed

LiquidCrystal_I2C lcd(LCD_ADDR, 16, 2);

unsigned long previousMillis = 0;  // stores the last time the clock updated
const long interval = 1000;  // interval at which to update the time (1 second)

int hours = 12;  // Initialize starting hour
int minutes = 0; // Initialize starting minute
int seconds = 0; // Initialize starting second

void setup() {
  pinMode(LED_PIN, OUTPUT);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Clock Initialized");
  delay(2000);  // Show initialization message for 2 seconds
}

void loop() {
  unsigned long currentMillis = millis();

  // Check if it's time to update the clock (every second)
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;  // Save the last time we updated

    // Update seconds
    seconds++;

    // Check if seconds have reached 60
    if (seconds >= 60) {
      seconds = 0;
      minutes++;
    }

    // Check if minutes have reached 60
    if (minutes >= 60) {
      minutes = 0;
      hours++;
    }

    // Check if hours have reached 24
    if (hours >= 24) {
      hours = 0;
    }

    // Display the time on the LCD (First line: HH:MM, Second line: SS)
    lcd.clear();  // Clear the display to update the time

    // First line: Hours and Minutes
    lcd.setCursor(0, 0);
    if (hours < 10) lcd.print("0");  // Add leading zero for single digit hours
    lcd.print(hours);
    lcd.print(":");
    if (minutes < 10) lcd.print("0");  // Add leading zero for single digit minutes
    lcd.print(minutes);

    // Second line: Seconds
    lcd.setCursor(0, 1);
    lcd.print("Sec: ");
    if (seconds < 10) lcd.print("0");  // Add leading zero for single digit seconds
    lcd.print(seconds);

    // Blink the LED every second
    digitalWrite(LED_PIN, HIGH);
    delay(500);  // LED ON
    digitalWrite(LED_PIN, LOW);
    delay(500);  // LED OFF
  }
}
