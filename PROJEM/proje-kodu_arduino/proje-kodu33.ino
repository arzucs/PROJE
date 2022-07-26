#include <Servo.h>. //Servo kütüphanesini içerir
// Ultrasonik Sensörün Trig ve Echo pinlerini tanımlar
const int trigPin = 10;//Program boyunca sabit olması istenen tamsayı const(sabit) int=... olarak atanır
const int echoPin = 11;
// Süre ve mesafe için değişkenler
long duration;// (long :4 byte yani 32 bit işaretli tam sayı türünden verileri tutabilir) duration:süre
int distance;// tamsayı tipinde mesafe büyüklğü
Servo myServo; // (...Servo motoru kontrol etmek için bir servo nesnesi oluşturur...)
void setup() { // void= fonksiyon geriye değer döndürmez 
  //setup()=arduino'daki .ino uzantılı kod parçasının kod IDE başlatıldığında ilk çalışan kısmı 
  //(çalışma ortamını hazırlar)
  pinMode(trigPin, OUTPUT); // trig pinini çıkış pini olarak atar 
  pinMode(echoPin, INPUT); // echo pinini giriş pini olarak ayarlar
  Serial.begin(9600);// (seri port ile)seri iletişim başlatmak için void setup() fonksiyonunun içine yazılır
  // içerde yazan 9600 saniye başına gönderilen ve alınan bit (0 veya 1)
  myServo.attach(12); // (Servo motorun hangi pime bağlı olduğunu tanımlar) 
}
void loop() {// loop = setup dan sonra çalışır sonsuz döngü işlevi görür
  // rotates the servo motor from 0 to 180 degrees
  for(int i=0;i<=180;i++){ //servo motoru 0 ila 180 derece arasında döndürür 
  myServo.write(i);//write(açıdegeri) motor açı değeri ayarlar
  delay(30);// belilenen süre kadar bekler delay(1000)= 1sn ,
  distance = calculateDistance();// Her derece için Ultrasonik sensör tarafından ölçülen mesafeyi hesaplamak için bir fonksiyon çağırır
  
  Serial.print(i); // Geçerli dereceyi(yani i) seri bağlantı(seri port ekranına) noktasına gönderir
  Serial.print(","); // İndeksleme için Proccesing'de daha sonra ihtiyaç duyulan önceki değerin hemen yanına ek karakter gönderir
  Serial.print(distance); // Mesafe değerini Seri Port'a gönderir
  Serial.print("."); // İndeksleme için Proccesing'de daha sonra ihtiyaç duyulan önceki değerin hemen yanına ek karakter gönderir
  }
  // Önceki satırları 180 ila 0 derece arasında tekrarlar
  for(int i=180;i>0;i--){  
  myServo.write(i);
  delay(30);
  distance = calculateDistance();
  Serial.print(i);
  Serial.print(",");
  Serial.print(distance);
  Serial.print(".");
  }
}
// Ultrasonik sensör tarafından ölçülen mesafeyi hesaplama işlevi
int calculateDistance(){ //distance(mesafe) = calculateDistance() denmişti 
  
 digitalWrite(trigPin, LOW); 
  delayMicroseconds(2);// TrigPin'i 2 mikro saniye için DÜŞÜK duruma ayarlar
 
  digitalWrite(trigPin, HIGH); 
  delayMicroseconds(10);//TrigPin'i 10 mikro saniye için YÜKSEK duruma ayarlar
  
  digitalWrite(trigPin, LOW);// TrigPin'i düşük duruma ayarlanır
  duration = pulseIn(echoPin, HIGH); // Gönderilen ses dalgasının geri dönmesindeki süre ölçülüyor
  distance= duration*0.034/2;//Ölçütüğümüz süre uzaklığa çevriliyor
  return distance;// Mesafe döndürülür
}
