#include <WiFi.h>

bool is_wifi_connected() {
  return WiFi.status() == WL_CONNECTED;
}

void wifi_setup(const char *ssid, const char *pass) {
  WiFi.mode(WIFI_STA); // Put wifi into station mode
  WiFi.begin(ssid, pass); // start connecting to wifi

  Serial.print("Connecting...");
  while(!is_wifi_connected()) {
    delay(500);
    Serial.print(".");
    delay(500);
  }

  // connection established
  Serial.println("");
  Serial.println("WiFi Connection Established!!");
  Serial.println(WiFi.SSID());

  // print IP Address
  Serial.print("Assinged IP: ");
  Serial.println(WiFi.localIP());

}

// this also checks if wifi is connected and returns the string "No IP" when none found
String get_ip_addr_to_print() {
  IPAddress ip = WiFi.localIP();
  if (is_wifi_connected()) {
    return WiFi.localIP().toString();
  } else {
    return "No IP";
  }
}
