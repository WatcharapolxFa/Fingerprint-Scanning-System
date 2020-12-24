# Home 2077  ❤ 

<br><br> ![QON](https://github.com/WatcharapolxFa/Fingerprint_scanning_system/blob/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B%E0%B9%82%E0%B8%9B%E0%B8%A3%E0%B9%80%E0%B8%88%E0%B8%81/intro.png) <br><br>

`  Home 2077 | C++  `   พัฒนาขึ้นโดยใช้   `  Arduino IDE X Blynk` 🦩 <br><br>

## 🦩 Developer 🦩

* Watcharapol Yotadee 🦩
* Asarawoot Santhong 🦩
* Manutsawin Koonmeng 🦩


## 💻 Tool 

* Arduino IDE 💻 

## 🗂 Library

* #include <Adafruit_Fingerprint.h>
  #include <Wire.h>
  #include <hd44780.h> 
  #include <hd44780_I2Cexp.h> 
  #include <ESP8266WiFi.h>
  #include <BlynkSimpleEsp8266.h>
  #include <TridentTD_LineNotify.h> 
  #include <SoftwareSerial.h> 🗂

## 👾 Feature

*Inspiration 
 - ที่มีการนำ fingerprint , blynk , ลำโพงขนาด 5 watt , จอ LCD และเซอโวเป็นการทำงานหลักของโปรเจคนี้ 
โดยมีการใช้ board Arduino Uno 2 ตัว และ  ESP8266 อีก 1 ตัว เชื่อมต่อกัน 3 บอร์ด โดยใช้ softwareSerial 
   
*Working principle
  การทำงานแบ่งเป้น 2 ระบบใหญ่
 - ระบบเปิดบ้านโดยการสแกนนิ้ว
    โดยเมื่อแตะแสกนนิ้วจะมีการเช็ค User ถ้าถูกต้องไฟสถานะจะเปลี่ยนเป็นสีเขียว แล้วประตูจะเปิด
    จากนั้นจอ lcd และลำโพง จะมีการทักทายเจ้าของบ้านโดยแสดงข้อความและเล่นเสียงและจะมีข้อความไลน์เข้ามายัง User 
    เมื่อมี User ใด  User หนึ่งเข้าบ้าน แล้วประตูจะปิดโดยอัตโนมัติ 
 - ระบบการเปิด-ปิดประตูบ้านโดยผ่าน blynk สามารถสั่งงานจากที่ใดเวลาใดก็ได้ที่มีการเชื่อมต่ออินเตอร์เน็ต  👾

## ♠ Home 2077  >> Please click on the picture. <<

[![alt text](https://github.com/WatcharapolxFa/Fingerprint_scanning_system/blob/master/%E0%B8%A3%E0%B8%B9%E0%B8%9B%E0%B9%82%E0%B8%9B%E0%B8%A3%E0%B9%80%E0%B8%88%E0%B8%81/3in1.png?raw=true)](https://www.youtube.com/watch?v=aXzMEtPj1uk&fbclid=IwAR2dQJ0i6ndV6og_DMwQbiOsOOs5i4dHjhRkz1ndwUpmCC2CZRYcpNZZ96g)

<br> 
