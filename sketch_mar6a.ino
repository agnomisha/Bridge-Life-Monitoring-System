void setup() {
    Serial.begin(9600);
    Serial.println("Arduino is ready!");
}

void loop() {
    if (Serial.available() > 0) {  // Check if data is available
        char received = Serial.read();  // Read one character
        Serial.print("Received from Python: ");
        Serial.println(received);
    } else {
        Serial.println("Waiting for data...");  // Debugging line
        delay(1000);  // Print every second
    }
}
