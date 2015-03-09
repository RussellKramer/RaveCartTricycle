from time import sleep
import os
import RPi.GPIO as GPIO
import threading
import usb.core, usb.util, time
from mutagen.easyid3 import EasyID3
from mutagen.mp3 import MP3
import time
import random
from Adafruit_CharLCD_Dual import Adafruit_CharLCD_Dual
from subprocess import * 
from time import sleep, strftime
from datetime import datetime


GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

#LCD STUFF
lcd = Adafruit_CharLCD_Dual()



lcd.begin(16,2)
#lcd.begin(16,2,1)



lcd.clear(0)
lcd.clear(1)
#lcd.clear(1)

lcd.message('Ready1    \n',0)
lcd.message('Read2       ',0)

lcd.message('Ready3\n',1)
lcd.message('Ready4',1)






#SWITCH STUFF
GPIO.setup(14, GPIO.OUT)
GPIO.setup(23, GPIO.OUT)
GPIO.setup(18, GPIO.OUT)
GPIO.setup(15, GPIO.OUT)

GPIO.setup(3, GPIO.OUT) #indicator LED


CTRL_LOOPBACK_WRITE = 0
CTRL_LOOPBACK_READ = 1

BUTTONMATRIX_TRACK  = 0
BUTTONMATRIX_VOLUME = 1
BUTTONMATRIX_PATTERN = 2
BUTTONMATRIX_FFRW = 3

BUTTONMATRIX_TRACK_PLUS = BUTTONMATRIX_PATTERN_PLUS = BUTTONMATRIX_VOLUME_PLUS =8
BUTTONMATRIX_TRACK_MINUS = BUTTONMATRIX_PATTERN_MINUS = BUTTONMATRIX_VOLUME_MINUS =24
BUTTONMATRIX_TRACK_SWITCH = BUTTONMATRIX_PATTERN_SWITCH = BUTTONMATRIX_VOLUME_SWITCH = 25

GPIO.setup(BUTTONMATRIX_TRACK_PLUS, GPIO.IN)
GPIO.setup(BUTTONMATRIX_TRACK_MINUS, GPIO.IN)
GPIO.setup(BUTTONMATRIX_TRACK_SWITCH, GPIO.IN)

def SelectButtonCol(identifier):
	if(identifier == BUTTONMATRIX_PATTERN):
		GPIO.output(14,False)
		GPIO.output(23,True)
		GPIO.output(18,False)
		GPIO.output(15,False)
		
	elif(identifier == BUTTONMATRIX_VOLUME):
		GPIO.output(14,False)
		GPIO.output(23,False)
		GPIO.output(18,False)
		GPIO.output(15,True)

	elif(identifier == BUTTONMATRIX_TRACK):
		GPIO.output(14,False)
		GPIO.output(23,False)
		GPIO.output(18,True)
		GPIO.output(15,False)
		
	elif(identifier == BUTTONMATRIX_FFRW):
		GPIO.output(14,True)
		GPIO.output(23,False)
		GPIO.output(18,False)
		GPIO.output(15,False)
	
	sleep(0.1);
	
	




def SendDisplayData(Mp3Name,TrackNumber,VolumeNumber,PatternNumber,length,bother):

	ID3data = MP3('/usr/bin/env_python/mp3/' + Mp3Name, ID3=EasyID3)
   	#print("Title:" + ID3data["title"][0])
    	#print("Year:" + ID3data["date"][0])
	
	print(ID3data)
	#LCD info
	try:
		album = (ID3data["album"][0])
	except:
		album = 'Untitled'
		
	try:
		artist = (ID3data["artist"][0])
	except:
		artist = 'Anonymous'	
		
	try:
		genre = (ID3data["genre"][0])
	except:
		genre = 'No Genre'
		pass
		

	if (bother == 1):
		lcd.clear(0)
		lcd.message(album + '\n',0)
		lcd.message(artist,0)

		lcd.clear(1)
		lcd.message(genre + '\n',1)
		lcd.message('System Normal',1)

	if(length < 0):
		try:
			length = int(ID3data.info.length)
		except:
			length = 999

	print(ID3data.info.length)

    	#print(ID3data)
	try:
		year = int(ID3data["date"][0])
	except:
		year = 9999
		pass

	    #helmar- afterhours
	try:#television rules the nat
		if(len(artist) + len(ID3data["title"][0]) < 25):
			TitleString = artist + "-" + ID3data["title"][0]
		else:
			TitleString = ID3data["title"][0]
	
    		unicode(TitleString)
		title = list(TitleString)
	except:
		title = ['U','N','T','I','T','L','E','D']
		
			
		#AAA-BB-C
		#XXXX ZZZZ
	
	msg = [0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]
	
	#LINE 1
	#msg[0] = (TrackNumber/100)%10
	msg[0] = (TrackNumber/10)%10
	msg[1] = (TrackNumber/1)%10
	msg[2] = 11
	msg[3] = ((VolumeNumber - 11)/10)%10 #doc brown was here
	msg[4] = ((VolumeNumber - 11)/1)%10
	msg[5] = 11
	msg[6] = (PatternNumber/10)%10
	msg[7] = PatternNumber%10
	
	#LINE 2
	msg[8 ] = (year/1000)%10
	msg[9 ] = (year/100)%10
	msg[10] = (year/10)%10
	msg[11] = (year/1)%10
	
	msg[12 ] = 11
	msg[13 ] = (length/100)%10
	msg[14] =  (length/10)%10
	msg[15] =  (length/1)%10

	lengther = len(title)
	if(lengther + 19 > len(msg)):
		lengther = len(msg) - 19
	
	for x in range(0, len(title)):
		msg[16+x] = ord(title[x][0])
               	print(ord(title[x][0]))
	msg[len(title)+16] = ord(' ')
	msg[len(title)+17] = 0

	if DisplayBoard is None:
		print("## CAN'T SEND TO DISPLAY BOARD ##")
	else:
		print(" ## sending data to display board ## ")
		try:	
			DisplayBoard.write(1,msg,0)
		except:
			print("USB ERROR: DisplayBoard")
			pass
	

		
	if RightPanel is None:
		print("## CAN'T SEND TO right panel ##")
	else:
		print("## sending data to right panel ##")
		try:	
			RightPanel.write(1,msg,0)
		except:
			print("USB ERROR: RightPanel")
			pass
	
	
	if LeftPanel is None:
		print("## CAN'T SEND TO left panel ##")
	else:
		print("## sending data TO left panel ##")
		try:	
			LeftPanel.write(1,msg,0)
		except:
			print("USB ERROR: LeftPanel")
			pass

	if FrontPanel is None:
		print("## CAN'T SEND TO front panel ##")
	else:
		print("## sending data TO front panel ##")
		try:	
			FrontPanel.write(1,msg,0)
		except:
			print("USB ERROR: FrontPanel")
			pass
			
	return length
	
	

def DummyStartThread():
	os.system('mpg123 /usr/bin/env_python/button-1.mp3')
	
#sound thread
def PlayMp3(Mp3Name):
	os.system('mpg123 /usr/bin/env_python/mp3/' + Mp3Name)
	

	
	
#initialize USB DEVICES
DisplayBoard = usb.core.find(idVendor=0x1267, idProduct=0x0000)
if DisplayBoard is None:
	print("## can't find display board ##")
else:
	print(" ## display board found ## ")	


RightPanel = usb.core.find(idVendor=0x1267, idProduct=0x0001)
if RightPanel is None:
	print("## can't find RightPanel  ##")
else:
	print(" ## RightPanel found ## ")	
	
LeftPanel = usb.core.find(idVendor=0x1267, idProduct=0x0002)
if LeftPanel is None:
	print("## can't find LeftPanel  ##")
else:
	print(" ## LeftPanel  found ## ")	
	
FrontPanel = usb.core.find(idVendor=0x1267, idProduct=0x0003)
if FrontPanel is None:
	print("## can't find FrontPanel  ##")
else:
	print(" ## FrontPanel  found ## ")	
	
	
#Configure Panels
if DisplayBoard is None:
	print("## Display Board Not Found ##")
else:
	print("FOUND DISPLAY BOARD")
	DisplayBoard.set_configuration()
		
if RightPanel is None:
	print("## Right Panel Board Not Found ##")
else:
	print("FOUND Right Panel ")
	RightPanel.set_configuration()
	
if LeftPanel is None:
	print("## Left Panel Not Found ##")
else:
	print("FOUND Left Panel")
	LeftPanel.set_configuration()
	
if FrontPanel is None:
	print("## Front Panel Not Found ##")
else:
	print("FOUND Front Panel ")
	FrontPanel.set_configuration()
	

 
SongList = os.listdir("/usr/bin/env_python/mp3")
#print(SongList) 	
SongNumber =  91
VolumeNumber = 99
os.system('amixer set PCM ' + str(VolumeNumber) + '%')

PatternNumber  = 22
Songtime = 999
SongLength = 999;
last_time = 0
DEBOUNCE = 1
DebounceTime = 0
		
MyThread = threading.Thread(target=DummyStartThread)
MyThread.start()
	
	
while (True): #True
	if(DebounceTime > 0):
		DebounceTime = DebounceTime - 1
		GPIO.output(3,False)
	else:
		GPIO.output(3,True)
		
	if(time.time() - last_time > 1):
		last_time = time.time();
		Songtime = Songtime - 1

		Patterno = 0
		if(SongLength - Songtime < 30):
			Patterno = PatternNumber - (PatternNumber%4) #force text scroll for the first 30 seconds
		else:
			Patterno = PatternNumber
			
		DisplayThread = threading.Thread(target=SendDisplayData, args = (SongList[SongNumber],SongNumber,VolumeNumber,Patterno,Songtime,0,))
		DisplayThread.start()
				
		#SendDisplayData(SongList[SongNumber],SongNumber,VolumeNumber,PatternNumber,Songtime,0)
		
		
		
	SelectButtonCol(BUTTONMATRIX_VOLUME)
	if( (GPIO.input(BUTTONMATRIX_VOLUME_PLUS) or GPIO.input(BUTTONMATRIX_VOLUME_MINUS) ) and DebounceTime == 0):
		if( GPIO.input(BUTTONMATRIX_VOLUME_PLUS) and VolumeNumber < 99):
			VolumeNumber = VolumeNumber + 1
	
			
		if( GPIO.input(BUTTONMATRIX_VOLUME_MINUS) and VolumeNumber > 0):
			VolumeNumber = VolumeNumber - 1
			
		
		SendDisplayData(SongList[SongNumber],SongNumber,VolumeNumber,PatternNumber,Songtime,0)
		print("VolumeNumber#"+str(VolumeNumber))
		os.system('amixer set PCM ' + str(VolumeNumber) + '%')
	else:	
		
		
		SelectButtonCol(BUTTONMATRIX_PATTERN)
		if( (GPIO.input(BUTTONMATRIX_PATTERN_PLUS) or GPIO.input(BUTTONMATRIX_PATTERN_MINUS) ) and DebounceTime == 0):
			if( GPIO.input(BUTTONMATRIX_PATTERN_PLUS)):
				if(PatternNumber < 55):
					PatternNumber = PatternNumber + 1
				else:
					PatternNumber = 0
	
			
			if( GPIO.input(BUTTONMATRIX_PATTERN_MINUS)):
				if( PatternNumber > 0):
					PatternNumber = PatternNumber - 1
				else:
					PatternNumber = 55
			DebounceTime = DEBOUNCE
			SendDisplayData(SongList[SongNumber],SongNumber,VolumeNumber,PatternNumber,Songtime,0)
			print("PatternNumber#"+str(PatternNumber))
			SongLength = 9999 #kill the auto text scroll
		else:
		
			SelectButtonCol(BUTTONMATRIX_TRACK)
			#track selection if track complete or the track+/track- buttons are being pressed
			if ( MyThread.isAlive() == False  or (GPIO.input(BUTTONMATRIX_TRACK_PLUS) and DebounceTime == 0) or  ( GPIO.input(BUTTONMATRIX_TRACK_MINUS) and DebounceTime == 0)):
		
				if(MyThread.isAlive() == True ):
					DebounceTime = DEBOUNCE
		
		
				#advance the track by 1 if the track+ button is pressed or track is complete and shuffle disabled
				if(  GPIO.input(BUTTONMATRIX_TRACK_PLUS) or (MyThread.isAlive() == False and GPIO.input(BUTTONMATRIX_TRACK_SWITCH) == True) ): # song number +
					SongNumber = SongNumber + 1
					if SongNumber >= len(SongList):
						SongNumber =  1
		
				#pick random track if track complete and shuffle enabled
				elif( MyThread.isAlive() == False and GPIO.input(BUTTONMATRIX_TRACK_SWITCH) == False): #shuffle
					SongNumber = random.randrange(1,len(SongList)-1)
		
		
		
				elif(GPIO.input(BUTTONMATRIX_TRACK_MINUS)): #decrement track if track- button pressed
					if(SongNumber == 1):
						SongNumber = len(SongList)-1
					else:
						SongNumber = SongNumber - 1
		
				Songtime = SendDisplayData(SongList[SongNumber],SongNumber,VolumeNumber,PatternNumber,-1,1)
				SongLength = Songtime;
				os.system('pkill mpg123')
				MyThread = threading.Thread(target=PlayMp3, args = (SongList[SongNumber],))
				MyThread.start()
				sleep(1)
				print("Track#"+str(SongNumber))