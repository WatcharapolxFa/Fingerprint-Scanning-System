#include <Adafruit_Fingerprint.h>
#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <TridentTD_LineNotify.h>
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
const int LCD_COLS = 16;
const int LCD_ROWS = 2;

int data=0;

int col;
int row;
int status;
#include <SoftwareSerial.h>
SoftwareSerial mySerial(5, 4);
SoftwareSerial UnoSerial(D0, D8);
SoftwareSerial UnoSerial2(D9, D10);
#include <Servo.h>
Servo myservo;

Adafruit_Fingerprint finger = Adafruit_Fingerprint(&mySerial);

#define SSID"Sasmha"
#define PASSWORD "313326339" 
#define LINE_TOKEN "RUdy3janrTKJLc2PBemilWNwKdS1NWzyGbqkjA3Pskj"
char auth[] = "-_1fmlHGBwGamlig5rzLbKmVk_0d1Vgb";
char ssid[] = "Sasmha";
char pass[] = "313326339";

void setup()  
{
  pinMode(D0, INPUT);
  pinMode(D8, OUTPUT);
  pinMode(D9, INPUT);
  pinMode(D10, OUTPUT);
  
  LINE.setToken(LINE_TOKEN);
  myservo.attach(D7);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
 // pinMode(D8, OUTPUT);
  digitalWrite(D5, HIGH);
  digitalWrite(D6, LOW);
  //digitalWrite(D8, LOW);
  Serial.begin(9600);
  UnoSerial.begin(57600);
  UnoSerial2.begin(57600);
  while (!Serial);  // For Yun/Leo/Micro/Zero/...
  delay(100);
  Serial.println("\n\nAdafruit finger detect test");

  // set the data rate for the sensor serial port
  finger.begin(57600);
  
  if (finger.verifyPassword()) {
    Serial.println("Found fingerprint sensor!");
  } else {
    Serial.println("Did not find fingerprint sensor :(");
    while (1) { delay(1); }
  }

  finger.getTemplateCount();
  Serial.print("Sensor contains "); Serial.print(finger.templateCount); Serial.println(" templates");
  Serial.println("Waiting for valid finger...");
  Blynk.syncAll();
  myservo.write(10);
   WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting to %s\n",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(400);
     Blynk.begin(auth, ssid, pass);
}
}

void loop()                     // run over and over again
{
  
  UnoSerial.print(data);
  UnoSerial.print("\n");
  getFingerprintIDez();
  delay(50);
  Blynk.run();//don't ned to run this at full speed.
  if(digitalRead(D4)==0)
  {
    //LINE.notify("ประตูปิด");
    myservo.write(0); // สั่งให้ Servo หมุนไปองศาที่ 0
      delay(500); // หน่วงเวลา 1000ms
      
  }
  else if(digitalRead(D4)==1)
  {
    //LINE.notify("ประตูเปิด");
    myservo.write(90); // สั่งให้ Servo หมุนไปองศาที่ 0
      delay(500); // หน่วงเวลา 1000ms
      
  }
 
}

  uint8_t getFingerprintID() {
  uint8_t p = finger.getImage();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image taken");
      break;
    case FINGERPRINT_NOFINGER:
      Serial.println("No finger detected");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_IMAGEFAIL:
      Serial.println("Imaging error");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }

  // OK success!

  p = finger.image2Tz();
  switch (p) {
    case FINGERPRINT_OK:
      Serial.println("Image converted");
      break;
    case FINGERPRINT_IMAGEMESS:
      Serial.println("Image too messy");
      return p;
    case FINGERPRINT_PACKETRECIEVEERR:
      Serial.println("Communication error");
      return p;
    case FINGERPRINT_FEATUREFAIL:
      Serial.println("Could not find fingerprint features");
      return p;
    case FINGERPRINT_INVALIDIMAGE:
      Serial.println("Could not find fingerprint features");
      return p;
    default:
      Serial.println("Unknown error");
      return p;
  }
  
  // OK converted!
  p = finger.fingerFastSearch();
  if (p == FINGERPRINT_OK) {
    Serial.println("Found a print match!");
  } else if (p == FINGERPRINT_PACKETRECIEVEERR) {
    Serial.println("Communication error");
    return p;
  } else if (p == FINGERPRINT_NOTFOUND) {
    Serial.println("Did not find a match");
    return p;
  } else {
    Serial.println("Unknown error");
    return p;
  }   
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence); 

  return finger.fingerID;
}

// returns -1 if failed, otherwise returns ID #
int getFingerprintIDez() {
  uint8_t p = finger.getImage();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.image2Tz();
  if (p != FINGERPRINT_OK)  return -1;

  p = finger.fingerFastSearch();
  if (p != FINGERPRINT_OK)  return -1;
  
  // found a match!
  Serial.print("Found ID #"); Serial.print(finger.fingerID); 
  Serial.print(" with confidence of "); Serial.println(finger.confidence);
  if(finger.fingerID == 1){
    data= 1;
    UnoSerial.print(data);
    UnoSerial2.print(data);
  UnoSerial.print("\n");
  UnoSerial2.print("\n");
    digitalWrite(D5, LOW);
    digitalWrite(D6, HIGH);
      myservo.write(90); // สั่งให้ Servo หมุนไปองศาที่ 0
      delay(500); // หน่วงเวลา 1000ms
      LINE.notify("คุณยงยุทธ์  แก้วดวงน้อย 63010791 เข้าบ้าน");
      Serial.print("FAA");
       
      digitalWrite(D6, LOW);
      digitalWrite(D5, HIGH);
            Serial.println("ON");
      
  }
    if(finger.fingerID == 2){
    data= 2;
    UnoSerial.print(data);
    UnoSerial2.print(data);
   UnoSerial.print("\n");
    digitalWrite(D5, LOW);
    digitalWrite(D6, HIGH);
      myservo.write(90); // สั่งให้ Servo หมุนไปองศาที่ 0
      delay(500); // หน่วงเวลา 1000ms
      
      LINE.notify("คุณอัศราวุธ  สานทอง  63011078 เข้าบ้าน");
      Serial.print("PUPZ"); 
       
      digitalWrite(D6, LOW);
      digitalWrite(D5, HIGH);
      Serial.println("ON");
     
      
  }
  data = 0 ;
  return finger.fingerID; 
}
