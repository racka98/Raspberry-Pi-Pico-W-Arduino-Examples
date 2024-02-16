#include <Arduino.h>

const char *SSID = "Net"; // Put your wifi name here
const char *PASSW = "password"; // Put your wifi password here

// Blink prototype
void blink_app();
void blink_app_setup();

// Display function from ssd1306_display.ino
void display_setup();
void display_run(const char *ssid, const char *ip);
void show_wifi_connecting(const char *ssid);

// WiFi connection functions
void wifi_setup(const char *ssid, const char *pass);
String get_ip_addr_to_print();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  blink_app_setup();

  while (!Serial) {
    delay(10); // hang out until serial port opens
  }

  Serial.println("");
  Serial.println("Setting Up Pico...");

  // Set up display too
  display_setup();

  // Show WIFI connecting
  show_wifi_connecting(SSID);
  // Start wifi connection
  wifi_setup(SSID, PASSW);
}

void loop() {
  // put your main code here, to run repeatedly:

  //Blink LED
  blink_app();

  // Print IP address to Display
  const char *ip = get_ip_addr_to_print().c_str();
  Serial.println(ip);

  display_run(SSID, ip);

  delay(2000);
}

void blink_app_setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

void blink_app() {
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
  delay(500);
  digitalWrite(LED_BUILTIN, LOW);
  delay(500);
  digitalWrite(LED_BUILTIN, HIGH);
}
