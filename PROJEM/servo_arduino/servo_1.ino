#include <Servo.h>  //Servo kitaplığını içerir
Servo servo_motor_1;//Servo motoru kontrol etmek için bir servo nesnesi oluşturur

void setup() {// void= fonksiyon geriye değer döndürmez 
  //setup()=arduino'daki .ino uzantılı kod parçasının kod IDE başlatıldığında ilk çalışan kısmı 
 
  servo_motor_1.attach(3);//Servo motorun hangi pime bağlı olduğunu tanımlar

}

void loop() {// loop = setup dan sonra çalışır sonsuz döngü işlevi görür
  // rotates the servo motor from 0 to 180 
  
  servo_motor_1.write(0);//write(açıdegeri) motor açı değeri ayarlar
  delay(100);// belilenen süre kadar bekler delay(1000)= 1sn
  
  servo_motor_1.write(45);
 delay(100); 
 
 servo_motor_1.write(90);
 delay(100);

 servo_motor_1.write(135);
 delay(100);
 
 servo_motor_1.write(180);
  delay(100);

}
