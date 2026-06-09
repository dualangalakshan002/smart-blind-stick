# Smart Blind Stick

An Arduino-based assistive device that helps visually impaired people detect obstacles using ultrasonic sensors. Alerts the user through a buzzer and vibration motor based on obstacle proximity.

## Components

- Arduino Uno
- 2 × HC-SR04 Ultrasonic Sensors
- Buzzer
- Vibration Motor
- 9 V Battery
- ON/OFF Switch
- PVC pipe (cane structure)

## Pin Connections

| Component | Arduino Pin |
|-----------|-------------|
| Sensor 1 Trig | Pin 9 |
| Sensor 1 Echo | Pin 10 |
| Sensor 2 Trig | Pin 5 |
| Sensor 2 Echo | Pin 6 |
| Buzzer | Pin 8 |
| Vibration Motor | Pin 7 |

## How It Works

| Distance | Action |
|----------|--------|
| > 100 cm | No alert |
| 50 – 100 cm | Slow beep + slow vibration |
| < 50 cm | Fast beep + strong vibration |

## How to Run

1. Open `SmartBlindStick.ino` in Arduino IDE
2. Select **Tools → Board → Arduino Uno**
3. Select the correct COM port
4. Click **Upload**
