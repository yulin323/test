#include <Arduino.h>
#include <U8g2lib.h>
#include <OneWire.h> 
#include <DallasTemperature.h> 

#define DQ_Pin 2  

OneWire oneWire(DQ_Pin);
DallasTemperature sensors(&oneWire);

#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

U8G2_SSD1306_128X64_NONAME_F_4W_SW_SPI u8g2(U8G2_R0, /* clock=*/ 13, /* data=*/ 11, /*cs*/3, /* dc=*/ 9, /* reset=*/ 8);   // Adafruit Feather M0 Basic Proto + FeatherWing OLED

void setup(void) {
  u8g2.begin();
  Serial.begin(9600);
  sensors.begin();
}

void loop(void) {
  float temp; 

  u8g2.clearBuffer();                   // 清除內存
  u8g2.setFont(u8g2_font_ncenB08_tr);   // 選字形
 
  Serial.print("Temperatures --> "); //提示將要顯示溫度
  sensors.requestTemperatures(); //請求數據
  temp = sensors.getTempCByIndex(1); //第一個感測器的溫度值

  char tempStr[10];
  dtostrf(temp, 6, 2, tempStr);  // 浮點數temp轉為字串，6是字串最小寬度，2是小數點後位，存在tempStr

  char displayStr[20];
  sprintf(displayStr, "Temperature:%s C", tempStr); //int sprintf(char *str, const char *format, ...)
  u8g2.drawStr(0, 10, displayStr);    // drawStr 只接受字串(x,y,str)

  u8g2.sendBuffer();                   // 輸出
  delay(1000); 
}

