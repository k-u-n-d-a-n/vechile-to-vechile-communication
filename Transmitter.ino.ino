#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <RH_ASK.h>
#include <SPI.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

// 2000 = baud rate
// 2 = RF receiver data pin D2
RH_ASK rf_driver(2000, 2);

void setup() {

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("STATUS: ----");

  lcd.setCursor(0, 1);
  lcd.print("ANGLE: ----");

  if (!rf_driver.init()) {
    lcd.clear();
    lcd.print("RF ERROR");
  }
}

void loop() {

  uint8_t buf[20];
  uint8_t buflen = sizeof(buf);

  if (rf_driver.recv(buf, &buflen)) {

    // Make received data a string
    buf[buflen] = '\0';

    char status;
    int angle;

    // Read data such as A,45 or N,10
    sscanf((char*)buf, "%c,%d", &status, &angle);

    // Display status
    lcd.setCursor(0, 0);

    if (status == 'A') {
      lcd.print("STATUS: ALERT  ");
    }
    else {
      lcd.print("STATUS: NORMAL ");
    }

    // Display angle
    lcd.setCursor(0, 1);
    lcd.print("ANGLE: ");
    lcd.print(angle);
    lcd.print("   ");
  }
}