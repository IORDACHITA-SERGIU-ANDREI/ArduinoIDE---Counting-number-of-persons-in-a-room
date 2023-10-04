#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

int countA = 0;

int sensorA = 2;
int sensorB = 3;
int buzzerPin = 4;

void setup() {

  lcd.begin();
  lcd.backlight();

  pinMode(sensorA, INPUT);
  pinMode(sensorB, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {

  if (countA <= 0) {
    lcd.setCursor(0, 0);
    lcd.print("Room empty        ");
    countA = 0;
    //delay(1000);
  }
  if (digitalRead(sensorA) == LOW) {
    delay(100);
    if (digitalRead(sensorB) == LOW) {
      countA++;

      if (countA > 10) {
        digitalWrite(buzzerPin, HIGH);
        delay(500);
        digitalWrite(buzzerPin, LOW);
      }


      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Count :    ");
      lcd.print(countA);
      delay(1000);
    }
  } else if (digitalRead(sensorB) == LOW) {
    delay(100);
    if (digitalRead(sensorA) == LOW) {
      countA--;
      if (countA <= 0) {
        countA = 0;
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Room empty        ");
        delay(1000);
      } else {
        lcd.clear();
        lcd.setCursor(0, 0);
        lcd.print("Count :    ");
        lcd.print(countA);
        delay(1000);
      }
    }
  }
}
