import serial
import time

arduino = serial.Serial(port='COM3', baudrate=9600, timeout=1)  # Change 'COM3' as needed
time.sleep(2)  # Wait for Arduino to reset after connecting

arduino.write(b'Hello Arduino!\n')  # Send data
time.sleep(1)  # Give Arduino time to process

while True:
    data = arduino.readline().decode().strip()
    if data:
        print("Arduino says:", data)
