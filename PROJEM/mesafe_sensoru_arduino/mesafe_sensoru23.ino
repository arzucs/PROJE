int trigPin = 3;// integer(tamsayı(2,4,8 byte)) türünde trig ve echo pinleri tanımlar
int echoPin = 2;

long sure;//( long :4 byte yani 32 bit işaretli tam sayı türünden verileri tutabilir)
long uzaklik;// sure ve uzaklık tanımlanır

void setup(){//setup()=arduino'daki .ino uzantılı kod parçasının kod IDE başlatıldığında ilk çalışan kısmı 
  //(çalışma ortamını hazırlar)
  
pinMode(trigPin, OUTPUT);// trig pinini çıkış pini olarak atar 
pinMode(echoPin,INPUT);// echo pinini giriş pini olarak ayarlar
Serial.begin(9600);// (seri port ile)seri iletişim başlatmak için void setup() fonksiyonunun içine yazılır
  // içerde yazan 9600 saniye başına gönderilen ve alınan bit (0 veya 1)
}
void loop(){// loop = setup dan sonra çalışır sonsuz döngü işlevi görür
  // rotates the servo motor from 0 to 180 degrees
digitalWrite(trigPin, LOW);
delayMicroseconds(5);// TrigPin'i 5 mikro saniye için DÜŞÜK duruma ayarlar
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);//TrigPin'i 10 mikro saniye için YÜKSEK duruma ayarlar
digitalWrite(trigPin, LOW);// TrigPin'i düşük duruma ayarlanır
sure = pulseIn(echoPin, HIGH);// Gönderilen ses dalgasının geri dönmesindeki süre ölçülüyor
uzaklik= sure /29.1/2;//Ölçütüğümüz süre uzaklığa çevriliyor
if(uzaklik > 200)
uzaklik = 200;// eğer uzaklık 200 den büyükse 200 e sabitlenir
Serial.print("Uzaklik ");// "Uzaklık " yazılır seri port ekranına
Serial.print(uzaklik); // Geçerli deger(yani uzaklik) seri port ekranına gönderir
Serial.println(" CM olarak olculmustur.");// "CM olarak olculmustur." yazılır seri port ekranına
delay(500);// belilenen süre kadar bekler delay(1000)= 1sn 
}
