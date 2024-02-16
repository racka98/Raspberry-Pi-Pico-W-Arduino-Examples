#include <GyverOLED.h>

static const unsigned char PROGMEM logo_bmp[] =
{ 0b00000000, 0b11000000,
  0b00000001, 0b11000000,
  0b00000001, 0b11000000,
  0b00000011, 0b11100000,
  0b11110011, 0b11100000,
  0b11111110, 0b11111000,
  0b01111110, 0b11111111,
  0b00110011, 0b10011111,
  0b00011111, 0b11111100,
  0b00001101, 0b01110000,
  0b00011011, 0b10100000,
  0b00111111, 0b11100000,
  0b00111111, 0b11110000,
  0b01111100, 0b11110000,
  0b01110000, 0b01110000,
  0b00000000, 0b00110000 };

//GyverOLED<SSD1306_128x32, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x32, OLED_NO_BUFFER> oled;
GyverOLED<SSD1306_128x64, OLED_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_NO_BUFFER> oled;
//GyverOLED<SSD1306_128x64, OLED_BUFFER, OLED_SPI, 8, 7, 6> oled;
//GyverOLED<SSH1106_128x64> oled;
// можно передать адрес: GyverOLED oled(0x3C);


void display_setup() {
  oled.init();
  oled.clear();
}

void print_wifi_info(const char *ssid, char *ip);

void display_run(const char *ssid, const char *ip) {
  for (byte i = 0; i < 100; i += 5) {
    oled.clear();
    oled.setCursorXY(0, 0);
    drawBattery(i);
    //write wifi info text
    print_wifi_info(ssid, ip);
    oled.update();
    delay(50);
  }
  for (int i = 100; i > 0; i -= 5) {
    oled.clear();
    oled.setCursorXY(0, 0);
    drawBattery(i);
    //write wifi info text
    print_wifi_info(ssid, ip);
    oled.update();
    delay(50);
  }
}

void drawBattery(byte percent) {
  oled.drawByte(0b00111100);
  oled.drawByte(0b00111100);
  oled.drawByte(0b11111111);
  for (byte i = 0; i < 100 / 8; i++) {
    if (i < (100 - percent) / 8) oled.drawByte(0b10000001);
    else oled.drawByte(0b11111111);
  }
  oled.drawByte(0b11111111);
}

void print_wifi_info(const char *ssid, const char *ip) {
  oled.setCursorXY(28, 16);
  oled.print("AP: ");
  oled.print(ssid);
  oled.setCursorXY(14, 34);
  oled.print("IP: ");
  if (ip != NULL) {
    oled.print(ip);
  } else {
    oled.print("...........");
  }
}

void show_wifi_connecting(const char *ssid) {
  print_wifi_info(ssid, "............");
  oled.update();
}
