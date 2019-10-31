from ArduinoSerial import sendData
import serial
import time

ser = serial.Serial("/dev/ttyACM0",9600)
ser.flushInput()

square = [(100,100),(100,-100),(100,100),(100,-100),(100,100),(100,-100),(100,100),(100,-100),(0,0)]

for cmd in square:
	sendData(ser, 1, cmd[0])
	sendData(ser, 2, cmd[1])
	time.sleep(1)




