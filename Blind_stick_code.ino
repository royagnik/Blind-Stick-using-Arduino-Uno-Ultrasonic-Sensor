// Define pins
const int trigPin = 9;  // Trigger pin of HC-SR04
const int echoPin = 10; // Echo pin of HC-SR04
const int buzzerPin = 8; // Buzzer pin

// Variables
long duration;
int distance;
int alertDistance = 50; // Distance in cm to trigger the buzzer (adjust as needed)

void setup() {
  // Set pins as input/output
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  
  // Begin serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Send a pulse from the ultrasonic sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Measure the duration of the pulse
  duration = pulseIn(echoPin, HIGH);
  
  // Calculate the distance in cm
  distance = duration * 0.034 / 2;

  // Print the distance (for debugging)
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  // Check if the distance is within the alert range
  if (distance > 0 && distance <= alertDistance) {
    // If object is detected within alert range, beep the buzzer
    digitalWrite(buzzerPin, HIGH);
  } else {
    // If no object is detected in alert range, stop the buzzer
    digitalWrite(buzzerPin, LOW);
  }
  
  // Delay for stability
  delay(100);
}
