// import library
#include <Servo.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);   // LCD object Parameters: (rs, enable, d4, d5, d6, d7)

const int led_red = 6;                     // LED merah terhubung ke pin 6
const int led_green = 7;                   // LED hijau terhubung ke pin 7
const int trigPin = A0;                    // trigPin terhubung ke pin A0
const int echoPin = A1;                    // echopin terhubung ke pin A1

long duration, distance;                   // deklarasi variabel duration dan distance bertipe long
Servo palang_servo;                        // deklarasi variabel palang_servo bertipe servo
                                                                                               
void setup() {                             // Setup Program

  lcd.begin(16,2);                         // setup LCD 16x2

  // setup variable 
  pinMode(led_red, OUTPUT);              
  pinMode(led_green, OUTPUT);                                                          
  pinMode(trigPin, OUTPUT);               
  pinMode(echoPin, INPUT);
  palang_servo.attach(0);                  // palang_servo terhubung ke pin 0

  digitalWrite(led_red, LOW);              // LED merah (OFF)
  digitalWrite(led_green, LOW);            // LED hijau (OFF)
  palang_servo.write(0);                   // set palang_servo motor dengan sudut 0° derajat
  
  lcd.setCursor(0,0);                      // set posisi cursor (row, col) 
  
  /* customize this display
  lcd.print(" FINAL PROJECT. ");
  lcd.setCursor(4,1);
  lcd.print(" KOMDAT "); 
  delay(500);
  lcd.clear();

  lcd.setCursor(0,0);   
  lcd.print("  PALANG PINTU");    
  lcd.setCursor(0,1);
  lcd.print("    OTOMATIS");
  delay(500);
  lcd.clear();
  */
  
}

void loop() {

  digitalWrite(trigPin, LOW);               // memberikan nilai trigPin LOW untuk memastikan bahwa ‘trigger’ dalam keadaan (OFF)
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);              // trigPin (ON) => memicu sensor ultrasonik untuk memulai pengukuran jarak.
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);               // trigPin (OFF) => untuk menghentikan sementara
  
  duration = pulseIn(echoPin, HIGH);        // digunakan untuk mengukur durasi pulsa yang dikembalikan oleh sensor ultrasonik pada pin echoPin
  distance = duration*0.034/2;              // menghitung perkiraan jarak objek dari sensor ultrasonik => rumus kecepatan suara

  if (distance <= 100 && distance > 0){     // condition statement => jika jarak kurang dari 100cm dan lebih dari 0cm, maka servo akan terbuka dengan sudut 90° dan jika tidak maka akan tertutup dengan sudut 0°

      lcd.setCursor(0,0); 
      lcd.print(" Jarak :");    
      lcd.print(distance);                  // LCD akan menampilkan jarak
      lcd.print(" Cm ");
      lcd.setCursor(0,1);                                                 
      lcd.print("Palang Terbuka ");
      
      digitalWrite(led_red, LOW);           // LED merah (OFF)
      digitalWrite(led_green, HIGH);        // LED hijau (ON)
      
      palang_servo.write(90);               // set palang_servo motor dengan sudut 90° derajat
      delay(100);
      
  }else {                        

      lcd.setCursor(0,0);
      lcd.print(" Jarak :");
      lcd.print(distance);
      lcd.print(" Cm ");
      lcd.setCursor(0,1);                                                 
      lcd.print("Palang Tertutup");
      
      digitalWrite(led_red, HIGH);          // LED merah (ON)
      digitalWrite(led_green, LOW);         // LED hijau (OFF)
      
      palang_servo.write(0);                // set palang_servo motor dengan sudut 0° derajat
      delay(100);
  }
                                                                                 
}
