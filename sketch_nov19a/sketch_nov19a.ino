#include "U8glib.h" //使用 U8glib
//OLED 初使化設定//SSD1306
 u8g(13, 11, 10, 9);	// SW SPI 
 Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9

void setup(void)
{
    u8g.setFont(u8g_font_unifont);//設定字型
}
void loop(void)
{
    u8g.drawStr(20, 40, "Hello World."); //輸出字串(x座標,y座標,文字)
}
//U8GLIB_SSD1306_128X64
//U8GLIB_SSD1306_128X64 u8g(4, 5, 6, 7);	// SW SPI Com: SCK = 4, MOSI = 5, CS = 6, A0 = 7 (new white HalTec OLED)
//U8GLIB_SSD1306_128X64 u8g(10, 9);		// HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)

//U8GLIB_SSD1306_ADAFRUIT_128X64 u8g(13, 11, 10, 9);	// SW SPI Com: SCK = 13, MOSI = 11, CS = 10, A0 = 9
//U8GLIB_SSD1306_ADAFRUIT_128X64 u8g(10, 9);		// HW SPI Com: CS = 10, A0 = 9 (Hardware Pins are  SCK = 13 and MOSI = 11)
