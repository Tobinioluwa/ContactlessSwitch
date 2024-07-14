// Define pin numbers
const int irSensorPin = 9;
const int relay1Pin = 10;
const int relay2Pin = 11;

// Variables to store the relay states
int relay1State = LOW;
int relay2State = LOW;

// Variable to store the previous IR sensor state
int lastIrSensorState = HIGH;

void setup() {
  // Initialize serial communication for debugging purposes
  Serial.begin(9600);

  // Set the relay pins as outputs
  pinMode(relay1Pin, OUTPUT);
  pinMode(relay2Pin, OUTPUT);

  // Set the IR sensor pin as input
  pinMode(irSensorPin, INPUT);

  // Initialize the relays to be off initially
  digitalWrite(relay1Pin, relay1State);
  digitalWrite(relay2Pin, relay2State);
}

void loop() {
  // Read the value from the IR sensor
  int irSensorValue = digitalRead(irSensorPin);

  // Print the sensor value to the Serial Monitor for debugging
  Serial.println(irSensorValue);

  // Check for a change in the IR sensor state (from HIGH to LOW)
  if (irSensorValue == LOW && lastIrSensorState == HIGH) {
    // Toggle the state of the relays
    relay1State = !relay1State;
    relay2State = !relay2State;
    
    // Update the relays with the new states
    digitalWrite(relay1Pin, relay1State);
    digitalWrite(relay2Pin, relay2State);
    
    // Print the new relay states to the Serial Monitor for debugging
    Serial.print("Relay 1: ");
    Serial.println(relay1State);
    Serial.print("Relay 2: ");
    Serial.println(relay2State);
    
    // Wait for a while to avoid multiple toggles due to sensor noise
    delay(500); // Adjust the delay time as needed
  }

  // Update the last IR sensor state
  lastIrSensorState = irSensorValue;

  // Add a short delay before the next loop iteration
  delay(100);
}
