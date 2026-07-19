Industrial IoT Gateway with AI-Based Predictive Maintenance

📌 Overview

The Industrial IoT Gateway is an ESP32-based smart monitoring system designed to collect, analyze, and visualize machine operating data in real time. The project monitors machine temperature and load, displays live information on an OLED screen, uploads data to the Blynk IoT Cloud, and performs AI-based anomaly detection using Python.

This project demonstrates the integration of Embedded Systems, IoT, Cloud Computing, Data Analytics, and Artificial Intelligence for industrial monitoring and predictive maintenance.

⸻

🚀 Features

* Real-time machine temperature monitoring using DHT22
* Machine load monitoring using a potentiometer (simulation)
* Live data visualization on OLED display
* Industrial status indication using LEDs and buzzer
* Real-time cloud monitoring with Blynk IoT
* CSV data logging for analysis
* Data analysis using Pandas
* Machine performance visualization using Matplotlib
* AI-based anomaly detection using Isolation Forest
* Machine Health Score (0–100%)
* Predictive maintenance recommendations

⸻

🛠 Hardware Components

* ESP32 DevKit V4
* DHT22 Temperature Sensor
* OLED Display (SSD1306, I2C)
* Potentiometer
* Green LED
* Red LED
* Buzzer
* Jumper Wires

⸻

💻 Software & Tools

* Arduino IDE / Wokwi Simulator
* Blynk IoT Platform
* Python
* Pandas
* Matplotlib
* Scikit-learn
* Git & GitHub
* VS Code

⸻

📊 System Workflow

Sensors
   │
   ▼
ESP32
   │
   ▼
OLED Display
   │
   ▼
Blynk Cloud Dashboard
   │
   ▼
CSV Data Logging
   │
   ▼
Python Analysis
   │
   ▼
AI Anomaly Detection
   │
   ▼
Machine Health Score
   │
   ▼
Predictive Maintenance

⸻

🤖 AI Features

The AI module analyzes sensor readings to identify abnormal operating conditions.

* Detects abnormal temperature and load patterns
* Identifies anomalous machine behavior
* Calculates Machine Health Score
* Supports predictive maintenance decisions

Machine Learning Algorithm:

* Isolation Forest (Scikit-learn)

⸻

📈 Data Analysis

Collected sensor data is stored in CSV format and analyzed using Python.

Graphs include:

* Temperature Monitoring
* Machine Load Monitoring
* AI Anomaly Detection
* Machine Health Score

⸻

📁 Project Structure

Industrial-IoT-Gateway/
│
├── Arduino_Code/
├── Python/
│   ├── analyze_data.py
│   └── energy_data.csv
├── Images/
├── Documentation/
├── README.md
└── LICENSE

⸻

▶️ How to Run

1. Open the Arduino project in Wokwi or Arduino IDE.
2. Configure Wi-Fi and Blynk credentials.
3. Upload the code to ESP32.
4. Monitor live sensor data on the OLED display.
5. View real-time values on the Blynk dashboard.
6. Export sensor data to energy_data.csv.
7. Run:

python3 analyze_data.py

8. View generated graphs and AI analysis.

⸻

📌 Future Improvements

* Vibration Sensor Integration
* Current & Voltage Monitoring
* MQTT Communication
* Firebase Cloud Storage
* Predictive Failure Forecasting
* Email/SMS Alerts
* Mobile App Integration

