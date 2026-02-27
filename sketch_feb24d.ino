#include <Wire.h>
#include <LiquidCrystal.h>

#define ADXL345 0x53

int16_t AccX, AccY, AccZ;
float Ax, Ay, Az;

const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define IN1 8
#define IN2 9
#define ENA 6

void setup() {
  Wire.begin();
  Serial.begin(9600);
  lcd.begin(16, 2);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);
  Wire.write(0x08);
  Wire.endTransmission();

  lcd.print("Fan Control Ready");
  delay(2000);
  lcd.clear();
}

void loop() {

  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345, 6, true);

  AccX = Wire.read() | (Wire.read() << 8);
  AccY = Wire.read() | (Wire.read() << 8);
  AccZ = Wire.read() | (Wire.read() << 8);

  Ax = AccX * 0.0039;
  Ay = AccY * 0.0039;
  Az = AccZ * 0.0039;

  lcd.clear();

  if (Ax > 0.5) {           
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 180);

    lcd.print("Fan FORWARD");
  }
  else if (Ay > 0.5) {      
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, 180);

    lcd.print("Fan BACKWARD");
  }
  else {                    
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);

    lcd.print("Fan STOP");
  }

  delay(300);
}