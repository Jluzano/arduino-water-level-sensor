
const int waterSensorPin = A0; // Analog input pin connected to the water sensor

void setup() {
  Serial.begin(9600); // Initialize serial communication for debugging (optional)

  // set the LEDs pins as outputs
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);

  // turn all the LEDs off
  digitalWrite(LEDR, HIGH);
  digitalWrite(LEDG, HIGH);
  digitalWrite(LEDB, HIGH);
}

void loop() {
  int waterLevel = analogRead(waterSensorPin); // Read the analog value from the water sensor

  if(waterLevel == 0)
  {
    Serial.println("Water Level: N/A");
    Serial.println(waterLevel);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDB, LOW);
  }
  if(waterLevel > 0 && waterLevel <= 500)
  {
    Serial.println("Water Level: Low");
    Serial.println(waterLevel);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, HIGH);
    digitalWrite(LEDB, HIGH);
  }
  if(waterLevel > 500 && waterLevel <= 520)
  {
    Serial.println("Water Level: Medium");
    Serial.println(waterLevel);
    digitalWrite(LEDG, LOW);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDB, HIGH);
  }
  if(waterLevel > 520)
  {
    Serial.println("Water Level: High");
    Serial.println(waterLevel);
    digitalWrite(LEDG, HIGH);
    digitalWrite(LEDR, LOW);
    digitalWrite(LEDB, HIGH);
  }

  delay(100); // Add a small delay to avoid rapid readings
  Serial.println("---------------------------------");
}
