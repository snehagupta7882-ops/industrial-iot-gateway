#define BLYNK_TEMPLATE_ID "TMPL35mP_K31V"

#define BLYNK_TEMPLATE_NAME "industrial iot gateway"
#define BLYNK_AUTH_TOKEN "mcTiDCZT3ubhGQQ9CeRL8edXHZrpqY68"


#include <WiFi.h>
#include <BlynkSimpleEsp32.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>

char ssid[] = "Wokwi-GUEST";
char pass[] = "";

// OLED
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// DHT22
#define DHTPIN 15
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);

// Pins
const int potPin = 34;
const int greenLED = 18;
const int redLED = 19;
const int buzzer = 23;

BlynkTimer timer;

void sendData() {

  float temp = dht.readTemperature();
  int load = analogRead(potPin);

  String status;

  digitalWrite(greenLED, LOW);
  digitalWrite(redLED, LOW);
  digitalWrite(buzzer, LOW);

  if (load < 1200) {
    status = "NORMAL";
    digitalWrite(greenLED, HIGH);
  }
  else if (load < 2800) {
    status = "WARNING";
    digitalWrite(redLED, HIGH);
  }
  else {
    status = "ALERT";
    digitalWrite(redLED, HIGH);
    digitalWrite(buzzer, HIGH);
  }

  // OLED
  display.clearDisplay();
  display.setTextSize(1);
  display.setCursor(0,0);
  display.println("Industrial IoT");

  display.setCursor(0,15);
  display.print("Temp: ");
  display.print(temp);
  display.println(" C");

  display.setCursor(0,30);
  display.print("Load: ");
  display.println(load);

  display.setCursor(0,45);
  display.print("Status: ");
  display.println(status);

  display.display();

  // Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print(" C  ");

  Serial.print("Load: ");
  Serial.print(load);

  Serial.print("  Status: ");
  Serial.println(status);

  // Blynk
  Blynk.virtualWrite(V0, temp);
  Blynk.virtualWrite(V1, load);
  Blynk.virtualWrite(V2, status);
}

void setup() {

  Serial.begin(115200);

  pinMode(greenLED, OUTPUT);
  pinMode(redLED, OUTPUT);
  pinMode(buzzer, OUTPUT);

  dht.begin();

  Wire.begin(21,22);

  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println("OLED Failed");
    while(true);
  }
  
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(5,15);
  display.println("IIoT");
  display.setTextSize(1);
  display.setCursor(5,45);
  display.println("Gateway Starting...");
  display.display();

  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  timer.setInterval(1000L, sendData);
}

void loop() {

  Blynk.run();
  timer.run();

}
