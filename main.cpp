#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <TimeLib.h> 

#define I2C_ADDR    0x27

#define LCD_COLS    16
#define LCD_ROWS    2

LiquidCrystal_I2C lcd(I2C_ADDR, LCD_COLS, LCD_ROWS); 

void setup() {
  lcd.init(); 
  lcd.backlight(); 

  // Установка начального времени
  setTime(12, 0, 0, 1, 1, 2024); // Устанавливаем время 12:00:00 01.01.2024
}

void loop() {
  if (second() != 0) {
    displayTime();
    delay(1000);
  }

  if (Serial.available() > 0) {
    int hours = Serial.parseInt();
    int minutes = Serial.parseInt();
    int seconds = Serial.parseInt();
    setTime(hours, minutes, seconds, day(), month(), year());
  }
}

void displayTime() {
  int hours = hour();
  int minutes = minute();
  int seconds = second();

  // Отображаем время на LCD
  lcd.setCursor(0, 0);
  lcd.print("Time: ");
  if (hours < 10) {
    lcd.print("0");
  }
  lcd.print(hours);
  lcd.print(":");
  if (minutes < 10) {
    lcd.print("0");
  }
  lcd.print(minutes);
  lcd.print(":");
  if (seconds < 10) {
    lcd.print("0");
  }
  lcd.print(seconds);
}

