#use pip3 install pyserial
import serial

def sendData(ser, motN, spd):
	#ser is the serial object
	#motn is the motor number; 1-2 are for the first sabetooth, 3-4 for the second and so on...
	#spd is the speed, from 127 to -127
	speed = spd+127
	cmd = '#'+str(motN)+'$'+str(spd) 
	ser.write(bytes(cmd,'utf-8'))
