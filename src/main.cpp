#include <Arduino.h>
#include <U8g2lib.h>
#ifdef U8X8_HAVE_HW_SPI
#include <SPI.h>
#endif
#ifdef U8X8_HAVE_HW_I2C
#include <Wire.h>
#endif

// https://github.com/olikraus/u8g2/wiki/u8g2setupcpp#st7920-128x64=
#ifdef HAS_HARDWARDE_I2C
U8G2_SSD1327_WS_128X128_1_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);  // paged, use the 128X128_F for framebuffer mode
#else
U8G2_SSD1327_WS_128X128_1_SW_I2C u8g2(U8G2_R0, SCL_PIN, SDA_PIN);  // paged, use the 128X128_F for framebuffer mode
#endif

int getalleke = 0;
char str[8];

void setup(void) {
  #ifdef HAS_HARDWARDE_I2C
  u8g2.setBusClock(2000000);
  #endif
  u8g2.begin();
  u8g2.setFont(u8g2_font_inb63_mn );
}


void loop(void) {
  getalleke++;
  u8g2.firstPage(); // remove if using framebuffer
  do {
  // u8g2.clearBuffer();  // for framebuffer
  sprintf(str, "%d", getalleke);
  u8g2.drawStr(24,64, str);
  // u8g2.sendBuffer();  // for framebuffer

  } while ( u8g2.nextPage() );   // remove if using framebuffer
}