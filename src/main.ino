#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// ========== Config ==========
#define pinMQ3 A0
#define greenLed 6
#define redLed 7
#define buzzer 5
#define timeCalibra 5000  // 5 seconds calibration
#define timeMeasure 10000 // 10 seconds measurement
#define displayResult 5000  // 5 seconds to display result
const float limit = 0.25; // Legal limit threshold (mg/L)

LiquidCrystal_I2C lcd(0x27, 16, 2);
float baseLine = 0.0;
float maxAL = 0.0;
bool isMeasuring = false;
bool isBlowingDetected = false;
unsigned long timeStart;

enum Mode { READY, FAIL, PASS };
Mode currentMode = READY; // Default mode is READY 

// ========== SETUP ==========
void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buzzer, OUTPUT);

  lcd.init();
  lcd.backlight();

  lcd.clear();
  lcd.print("  Breavo  v1.0   "); // Name device and version
  lcd.setCursor(0, 1);
  lcd.print("  Alcohol Test  ");
  delay(3000);

  // Sensor Calibration
  calibrateSensor();

  lcd.clear();
  lcd.print("READY TO TEST");
  // Loop two times
  for (int i = 0; i < 2; i++) {
    digitalWrite(greenLed, HIGH);
    delay(500);
    digitalWrite(greenLed, LOW);
    delay(500);
  }
}

// ========== LOOP ==========
void loop() {
  // Main measurement loop
  float currentAL = getAL();

  // Detect blowing and start measuring if not already measuring
  if (detectBlow(currentAL) && !isMeasuring) {
    startMeasure();
  }

  // Update measuring status
  if (isMeasuring) {
    updateMeasure(currentAL);
  }

  // Actions based on current mode (PASS or FAIL)
  switch (currentMode) {
    case FAIL:
      digitalWrite(redLed, HIGH);   // Red ON
      digitalWrite(greenLed, LOW);  // Green OFF
      break;
    case PASS:
      digitalWrite(greenLed, HIGH); // Green ON
      digitalWrite(redLed, LOW);    // Red OFF
      break;
    case READY:
      digitalWrite(redLed, LOW);    // Red OFF
      digitalWrite(greenLed, LOW);  // Green OFF
      break;
  }
}

// ========== SENSOR CALIBRATION ==========
void calibrateSensor() {
  lcd.clear();
  lcd.print("Warming up...");
  float sum = 0;
  // Loop 50 times
  for (int i = 0; i < 50; i++) {
    sum += analogRead(pinMQ3);
    delay(60);
  }

  baseLine = sum / 50.0;
  lcd.clear();
  lcd.print("Warm-up OK");
  delay(4000);
}

// ========== READ ALCOHOL VALUE ==========
float getAL() {
  int rawValue = analogRead(pinMQ3) - baseLine; //A0(0 - 1023)
  if (rawValue < 0) rawValue = 0; // Ensure non-negative value
  return rawValue * (5.0 / 1023); // Convert to mg/L (needs real calibration)
}

// ========== DETECT BLOWING ==========
bool detectBlow(float currentAL) {
  if (currentAL > 0.02) { // Threshold to detect blowing
    if (!isBlowingDetected) {
      isBlowingDetected = true;
      return true;
    }
  } else {
    isBlowingDetected = false;
  }
  return false;
}

// ========== START MEASUREMENT ==========
void startMeasure() {
  maxAL = 0; // Set max alcohol = 0
  isMeasuring = true;
  timeStart = millis(); // Set start time for measurement
  lcd.clear();
}

// ========== UPDATE MEASUREMENT ==========
void updateMeasure(float currentAL) {
  // Compare current alcohol level to max alcohol level
  if (currentAL > maxAL) maxAL = currentAL; // Update new value of maxAL

  lcd.setCursor(0, 0);
  lcd.print("Real: ");
  lcd.print(currentAL, 3);
  lcd.print(" mg/L ");

  lcd.setCursor(0, 1);
  lcd.print("Max: ");
  lcd.print(maxAL, 3);
  lcd.print(" mg/L ");

  // Check if measuring time has elapsed
  if (millis() - timeStart >= timeMeasure) { // Trigger end when duration exceeds limit
    endMeasure();
  }
}

// ========== END MEASUREMENT ==========
void endMeasure() {
  isMeasuring = false;
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RESULTS: ");
  lcd.print(maxAL, 3);

  lcd.setCursor(0, 1);
  // Compare max Alcohol to limit allow
  if (maxAL < limit) { // Check if max alcohol is below allowed limit
    lcd.print(">> PASS <<");
    currentMode = PASS;           // Move to PASS
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  } else {
    lcd.print(">> FAIL <<");
    currentMode = FAIL;           // Move to FAIL
    //Loop 20 times
    for (int i = 0; i < 20; i++) {  
      digitalWrite(buzzer, HIGH); // Buzzer ON
      digitalWrite(redLed, HIGH); // Red ON
      delay(200);
      digitalWrite(buzzer, LOW); // Buzzer OFF
      digitalWrite(redLed, LOW); // Red OFF
      delay(200);
    }
  }
  delay(5000); // Display results in 5 sec
  resetSystem(); 
}

// ========== RESET SYSTEM ==========
void resetSystem() {
  digitalWrite(redLed, LOW); // Red OFF
  digitalWrite(greenLed, LOW); // Green OFF
  digitalWrite(buzzer, LOW); // Buzzer OFF
  lcd.clear();
  lcd.print("READY TO TEST");
  //Loop 2 times
  for (int i = 0; i < 2; i++) {
    digitalWrite(greenLed, HIGH); // Green ON
    delay(500);
    digitalWrite(greenLed, LOW); // Green OFF
    delay(500);
  }
  currentMode = READY;
}