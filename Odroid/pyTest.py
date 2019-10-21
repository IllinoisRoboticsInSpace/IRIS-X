#use pip3 install pyserial
import serial

#Use dmesg -wH to find what port the arduino is connected to
#It should be either ttyACM0 or ttyACM99

ser = serial.Serial("/dev/ttyACM0",9600)
ser.flushInput()

while True :
	val = bytes(str(input("Type command: ")),'utf-8') #commands must be sent into bytes form
	ser.write(val),
	print(str(ser.readline(), 'utf-8')) #If you don't have a print statement on .ino file remove this, since the program will wait for a response
