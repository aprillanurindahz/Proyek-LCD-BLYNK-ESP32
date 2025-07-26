#define BLYNK_TEMPLATE_ID "TMPL6hCIcSARP"
#define BLYNK_TEMPLATE_NAME "Percobaan LCD"
#define BLYNK_AUTH_TOKEN "_6bWsg-kjACR2PA4KrDo-WL8XuGZV80Z"

#include <WiFi.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <BlynkSimpleEsp32.h>

// Ganti dengan WiFi kamu
char ssid[] = "Instar";
char pass[] = "Adminsjt123";

// Inisialisasi LCD I2C (alamat bisa 0x27 atau 0x3F tergantung modul)
LiquidCrystal_I2C lcd(0x27, 16, 2);  // 16 kolom, 2 baris

// Ketika menerima input dari Virtual Pin V0 (Text Input)
BLYNK_WRITE(V0) {
  String inputText = param.asStr(); // Ambil string dari Blynk
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Blynk V0:");
  lcd.setCursor(0, 1);
  lcd.print(inputText);
}

void setup() {
  Serial.begin(115200);
  Wire.begin();          // SDA = GPIO21, SCL = GPIO22
  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Connecting...");
  
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("WiFi OK");
  lcd.setCursor(0, 1);
  lcd.print("Blynk OK");
}

void loop() {
  Blynk.run();
}