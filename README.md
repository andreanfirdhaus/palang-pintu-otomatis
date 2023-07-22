Rangkaian fisik: https://youtube.com/shorts/PySjOwQG7-Y

1. Arduino Uno R3 ATMEGA328P SMD CH340
2. HC-SR04 SR04 ULTRASONIC
3. TOWERPRO MOTOR SERVO SG90
4. LCD with I2C Module
5. Mini Solderless Breadboard
6. Kabel Jumper
7. LED 5MM (Red & Green)

Simulasi rangkaian palang pintu otomatis

![Alt text](https://github.com/andreanfirdhaus/palang-pintu-otomatis/blob/main/Simulasi%20Rangkaian.png)

1. Copy semua file TEP dan LIB yang ada di folder library "Arduino & Sensor Ultrasonic", kemudian Paste di folder LIBRARY pada Proteus:
   "C:\Program Files (x86)\Labcenter Electronics\Proteus 7 Professional\LIBRARY"
   "C:\Program Files (x86)\Labcenter Electronics\Proteus 8 Professional\DATA\LIBRARY"

2. Masukkan file berikut ke dalam rangkaian proteus:

   UltraSonicTEP.HEX -> ultrasonic sensor

   Source_Code.ino.hex -> arduino uno
   
4. Arudino IDE - Rangkaian Fisik/Source_Code/Source_Code.ino => custom kode arduino uno pada rangkaian fisik

5. Proteus - Simulasi Rangkaian/Arduino IDE - Simulasi Rangkaian/Source_Code/Source_Code.ino => custom kode arduino uno pada simulasi rangkaian proteus
