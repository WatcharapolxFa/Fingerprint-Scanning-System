#include <Wire.h>
#include <hd44780.h> // main hd44780 header
#include <hd44780_I2Cexp.h> // i2c expander i/o class header
hd44780_I2Cexp lcd; // declare lcd object: auto locate & config exapander chip
#include <SoftwareSerial.h>
#include <SD.h>
#define SD_ChipSelectPin 4
//#include <TMRpcm.h>
#include <SPI.h>
const int LCD_COLS = 16;
const int LCD_ROWS = 2;
int col;
int row;
int status;
int i_data = 3;
bool testLCD = false;
//TMRpcm tmrpcm;
// HELLO PUP  ////////////////////////////////////////////////////////////////////////////////
SoftwareSerial NodeSerial(5, 6); // RX | TX

void setup()
{
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);

  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  digitalWrite(7, HIGH);
  digitalWrite(8, LOW);
  Serial.begin(9600);
  status = lcd.begin(LCD_COLS, LCD_ROWS);
  NodeSerial.begin(57600);
  Serial.println();
  Serial.println("NodeMCU/ESP8266 Run");
  if (status) // non zero status means it was unsuccesful
  {
    // begin() failed so blink error code using the onboard LED if possible
    hd44780::fatalError(status); // does not return
  }
  // lcd.lineWrap();
  //  tmrpcm.speakerPin = 9;
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");
    return;
  }
}

void loop()
{
  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
  int i_data = NodeSerial.parseInt();
  Serial.print("NodeMCU or ESP8266");
  Serial.print(" : ");
  Serial.println (i_data);
  testLCD = false;
  if (i_data == 0 && testLCD == false)
  {
    pinMode(7, HIGH);
    pinMode(8, LOW);
    lcd.clear();
    lcd.setCursor(3, 0);
    lcd.print("2077 HOME");
    delay(300);
    testLCD = true;
  }
  if (i_data == 1 && testLCD == false)
  { digitalWrite(8, HIGH);
    digitalWrite(7, LOW);
    
    lcd.clear();
    lcd.setCursor(2, 0);
    lcd.print("HI YONGYUT!");
    delay(300);
    testLCD = true;
  }
  if (i_data == 2 && testLCD == false)
  {
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    lcd.clear();
    lcd.setCursor(1, 0);
    lcd.print("HI ASARAWOOT!");
    delay(300);
    testLCD = true;

  }
//  digitalWrite(7, HIGH);
  digitalWrite(8, HIGH);
}
