// import library
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>
#include <Servo.h>

LiquidCrystal_I2C lcd(0x27,16,2);           // to control the I2C LCD module

// initialize pin
const int led_red = 6;           
const int led_green = 7;
const int trigPin = A0;
const int echoPin = A1;

unsigned long duration;
int distance;
Servo palang_servo;

void setup() {

  lcd.init();


  lcd.backlight();
  lcd.setCursor(0,0);                       // to set the cursor position (row, col)
  lcd.print(" FINAL PROJECT. ");            // to display text
  lcd.setCursor(4,1);
  lcd.print(" KOMDAT "); 
  delay(2800);
  lcd.clear();

  lcd.setCursor(0,0);                       // to set the cursor position (row, col)
  lcd.print("  PALANG PINTU");    
  lcd.setCursor(0,1);
  lcd.print("    OTOMATIS");
  delay(2800);
  lcd.clear();

  palang_servo.attach(3);                   // initialize pin palang_servo to pin 3
  
  pinMode(led_red, OUTPUT);
  pinMode(led_green, OUTPUT);

  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

void loop() {

  // first step in measuring distances using ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  if (distance > 0 && distance < 15) {	    // conditional statement
    lcd.setCursor(0,0);
    lcd.print("Jarak ");
    lcd.print(distance);
    lcd.print(" Cm  ");
    lcd.setCursor(0,1);                                                 
    lcd.print("Palang TERBUKA ");

    digitalWrite(led_red, LOW);		          // red led (OFF)
    digitalWrite(led_green, HIGH);	        // green led (ON)

    palang_servo.write(90);		              //set servo motor to a 90°
    delay(700);
    
  } else {
    lcd.setCursor(0,0);
    lcd.print("Jarak ");
    lcd.print(distance);
    lcd.print(" Cm   ");
    lcd.setCursor(0,1);                                                 
    lcd.print("Palang TERTUTUP ");

    digitalWrite(led_red, HIGH);             // red led (ON)
    digitalWrite(led_green, LOW);            // green led (OFF)

    palang_servo.write(0);                   // set servo motor to a 0°
    delay(1000);
  }
}

