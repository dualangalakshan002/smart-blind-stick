// Smart Blind Stick with Two Ultrasonic Sensors
// Both sensors detect obstacles in front
// Buzzer rings whenever any object is within range

#define TRIG1_PIN 9
#define ECHO1_PIN 10
#define TRIG2_PIN 5
#define ECHO2_PIN 6
#define BUZZER_PIN 8
#define MOTOR_PIN 7

// Distance thresholds (cm)
#define NEAR_THRESHOLD 50
#define FAR_THRESHOLD  100

void setup() {
  pinMode(TRIG1_PIN, OUTPUT);
  pinMode(ECHO1_PIN, INPUT);
  pinMode(TRIG2_PIN, OUTPUT);
  pinMode(ECHO2_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Smart Blind Stick Ready");
}

// Read distance from any HC-SR04 sensor
float readDistance(int trigPin, int echoPin) {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  long duration = pulseIn(echoPin, HIGH, 30000);
  if (duration == 0) return 999.0;
  return (float)duration * 0.034 / 2.0;
}

// Beep buzzer + vibrate motor with given on/off times
void alertBeep(int onTime, int offTime) {
  digitalWrite(BUZZER_PIN, HIGH);
  digitalWrite(MOTOR_PIN, HIGH);
  delay(onTime);
  digitalWrite(BUZZER_PIN, LOW);
  digitalWrite(MOTOR_PIN, LOW);
  delay(offTime);
}

void loop() {
  float dist1 = readDistance(TRIG1_PIN, ECHO1_PIN);
  delay(30);
  float dist2 = readDistance(TRIG2_PIN, ECHO2_PIN);

  Serial.print("Sensor 1: ");
  Serial.print(dist1);
  Serial.print(" cm | Sensor 2: ");
  Serial.print(dist2);
  Serial.println(" cm");

  float minDist = 999.0;
  if (dist1 < 400 && dist1 < minDist) minDist = dist1;
  if (dist2 < 400 && dist2 < minDist) minDist = dist2;

  if (minDist < NEAR_THRESHOLD) {
    Serial.println(">> Object very close!");
    alertBeep(100, 50);
  }
  else if (minDist < FAR_THRESHOLD) {
    Serial.println(">> Object approaching");
    alertBeep(150, 350);
  }
  else {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(MOTOR_PIN, LOW);
    delay(100);
  }
}