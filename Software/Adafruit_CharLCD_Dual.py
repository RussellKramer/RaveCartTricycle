#!/usr/bin/python

#
# based on code from lrvick and LiquidCrystal
# lrvic - https://github.com/lrvick/raspi-hd44780/blob/master/hd44780.py
# LiquidCrystal - https://github.com/arduino/Arduino/blob/master/libraries/LiquidCrystal/LiquidCrystal.cpp
#

# modified for running two LCDs in parallel. 2014 Russell Kramer.

from time import sleep

class Adafruit_CharLCD_Dual:

    # commands
    LCD_CLEARDISPLAY 		= 0x01
    LCD_RETURNHOME 		= 0x02
    LCD_ENTRYMODESET 		= 0x04
    LCD_DISPLAYCONTROL 		= 0x08
    LCD_CURSORSHIFT 		= 0x10
    LCD_FUNCTIONSET 		= 0x20
    LCD_SETCGRAMADDR 		= 0x40
    LCD_SETDDRAMADDR 		= 0x80

    # flags for display entry mode
    LCD_ENTRYRIGHT 		= 0x00
    LCD_ENTRYLEFT 		= 0x02
    LCD_ENTRYSHIFTINCREMENT 	= 0x01
    LCD_ENTRYSHIFTDECREMENT 	= 0x00

    # flags for display on/off control
    LCD_DISPLAYON 		= 0x04
    LCD_DISPLAYOFF 		= 0x00
    LCD_CURSORON 		= 0x02
    LCD_CURSOROFF 		= 0x00
    LCD_BLINKON 		= 0x01
    LCD_BLINKOFF 		= 0x00

    # flags for display/cursor shift
    LCD_DISPLAYMOVE 		= 0x08
    LCD_CURSORMOVE 		= 0x00

    # flags for display/cursor shift
    LCD_DISPLAYMOVE 		= 0x08
    LCD_CURSORMOVE 		= 0x00
    LCD_MOVERIGHT 		= 0x04
    LCD_MOVELEFT 		= 0x00

    # flags for function set
    LCD_8BITMODE 		= 0x10
    LCD_4BITMODE 		= 0x00
    LCD_2LINE 			= 0x08
    LCD_1LINE 			= 0x00
    LCD_5x10DOTS 		= 0x04
    LCD_5x8DOTS 		= 0x00



    def __init__(self, pin_rs=9, pin_e0=2, pin_e1=11, pins_db=[27, 22, 17, 10], GPIO = None):
	# Emulate the old behavior of using RPi.GPIO if we haven't been given
	# an explicit GPIO interface to use
	if not GPIO:
	    import RPi.GPIO as GPIO
   	self.GPIO = GPIO
        self.pin_rs = pin_rs
        self.pin_e0 = pin_e0
        self.pin_e1 = pin_e1
        self.pins_db = pins_db

		
        self.GPIO.setmode(GPIO.BCM)
        self.GPIO.setup(self.pin_e0, GPIO.OUT)
        self.GPIO.setup(self.pin_e1, GPIO.OUT)
        self.GPIO.setup(self.pin_rs, GPIO.OUT)

        for pin in self.pins_db:
            self.GPIO.setup(pin, GPIO.OUT)

	self.write4bits(0x33,False,0) # initialization
	self.write4bits(0x32,False,0) # initialization
	self.write4bits(0x28,False,0) # 2 line 5x7 matrix
	self.write4bits(0x0C,False,0) # turn cursor off 0x0E to enable cursor
	self.write4bits(0x06,False,0) # shift cursor right
	
	
	self.write4bits(0x33,False,1) # initialization
	self.write4bits(0x32,False,1) # initialization
	self.write4bits(0x28,False,1) # 2 line 5x7 matrix
	self.write4bits(0x0C,False,1) # turn cursor off 0x0E to enable cursor
	self.write4bits(0x06,False,1) # shift cursor right

	self.displaycontrol = self.LCD_DISPLAYON | self.LCD_CURSOROFF | self.LCD_BLINKOFF

	self.displayfunction = self.LCD_4BITMODE | self.LCD_1LINE | self.LCD_5x8DOTS
	self.displayfunction |= self.LCD_2LINE

	""" Initialize to default text direction (for romance languages) """
	self.displaymode =  self.LCD_ENTRYLEFT | self.LCD_ENTRYSHIFTDECREMENT
	self.write4bits(self.LCD_ENTRYMODESET | self.displaymode,False,0) #  set the entry mode
	self.write4bits(self.LCD_ENTRYMODESET | self.displaymode,False,1) #  set the entry mode

        self.clear(0)
        self.clear(1)


    def begin(self, cols, lines):

	if (lines > 1):
		self.numlines = lines
    		self.displayfunction |= self.LCD_2LINE
		self.currline = 0


    def home(self,x):

	self.write4bits(self.LCD_RETURNHOME,False,x) # set cursor position to zero
	self.delayMicroseconds(3000) # this command takes a long time!


    def clear(self,x):

	self.write4bits(self.LCD_CLEARDISPLAY,False,x) # command to clear display
	self.delayMicroseconds(3000)	# 3000 microsecond sleep, clearing the display takes a long time


    def setCursor(self, col, row,x):

	self.row_offsets = [ 0x00, 0x40, 0x14, 0x54 ]

	if ( row > self.numlines ): 
		row = self.numlines - 1 # we count rows starting w/0

	self.write4bits(self.LCD_SETDDRAMADDR | (col + self.row_offsets[row]),False,x)


    def noDisplay(self,x): 
	""" Turn the display off (quickly) """

	self.displaycontrol &= ~self.LCD_DISPLAYON
	self.write4bits(self.LCD_DISPLAYCONTROL | self.displaycontrol,False,x)


    def display(self,x):
	""" Turn the display on (quickly) """

	self.displaycontrol |= self.LCD_DISPLAYON
	self.write4bits(self.LCD_DISPLAYCONTROL | self.displaycontrol,False,x)


    def noCursor(self):
	""" Turns the underline cursor on/off """

	self.displaycontrol &= ~self.LCD_CURSORON
	self.write4bits(self.LCD_DISPLAYCONTROL | self.displaycontrol,False,x)


    def cursor(self,x):
	""" Cursor On """

	self.displaycontrol |= self.LCD_CURSORON
	self.write4bits(self.LCD_DISPLAYCONTROL | self.displaycontrol,False,x)


    def noBlink(self,x):
	""" Turn on and off the blinking cursor """

	self.displaycontrol &= ~self.LCD_BLINKON
	self.write4bits(self.LCD_DISPLAYCONTROL | self.displaycontrol,False,x)


    def noBlink(self,x):
	""" Turn on and off the blinking cursor """

	self.displaycontrol &= ~self.LCD_BLINKON
	self.write4bits(self.LCD_DISPLAYCONTROL | self.displaycontrol,False,x)


    def DisplayLeft(self,x):
	""" These commands scroll the display without changing the RAM """

	self.write4bits(self.LCD_CURSORSHIFT | self.LCD_DISPLAYMOVE | self.LCD_MOVELEFT,False,x)


    def scrollDisplayRight(self,x):
	""" These commands scroll the display without changing the RAM """

	self.write4bits(self.LCD_CURSORSHIFT | self.LCD_DISPLAYMOVE | self.LCD_MOVERIGHT,False,x);


    def leftToRight(self,x):
	""" This is for text that flows Left to Right """

	self.displaymode |= self.LCD_ENTRYLEFT
	self.write4bits(self.LCD_ENTRYMODESET | self.displaymode,False,x);


    def rightToLeft(self,x):
	""" This is for text that flows Right to Left """
	self.displaymode &= ~self.LCD_ENTRYLEFT
	self.write4bits(self.LCD_ENTRYMODESET | self.displaymode,False,x)


    def autoscroll(self,x):
	""" This will 'right justify' text from the cursor """

	self.displaymode |= self.LCD_ENTRYSHIFTINCREMENT
	self.write4bits(self.LCD_ENTRYMODESET | self.displaymode,False,x)


    def noAutoscroll(self,x): 
	""" This will 'left justify' text from the cursor """

	self.displaymode &= ~self.LCD_ENTRYSHIFTINCREMENT
	self.write4bits(self.LCD_ENTRYMODESET | self.displaymode,False,x)


    def write4bits(self, bits, char_mode,x):
        """ Send command to LCD """

	self.delayMicroseconds(1000) # 1000 microsecond sleep

        bits=bin(bits)[2:].zfill(8)

        self.GPIO.output(self.pin_rs, char_mode)

        for pin in self.pins_db:
            self.GPIO.output(pin, False)

        for i in range(4):
            if bits[i] == "1":
                self.GPIO.output(self.pins_db[::-1][i], True)

	self.pulseEnable(x)

        for pin in self.pins_db:
            self.GPIO.output(pin, False)

        for i in range(4,8):
            if bits[i] == "1":
                self.GPIO.output(self.pins_db[::-1][i-4], True)

	self.pulseEnable(x)


    def delayMicroseconds(self, microseconds):
	seconds = microseconds / float(1000000)	# divide microseconds by 1 million for seconds
	sleep(seconds)




    def pulseEnable(self,x):
	
	if x == 0 :
		self.GPIO.output(self.pin_e0, False)
		self.delayMicroseconds(1)		# 1 microsecond pause - enable pulse must be > 450ns 
		self.GPIO.output(self.pin_e0, True)
		self.delayMicroseconds(1)		# 1 microsecond pause - enable pulse must be > 450ns 
		self.GPIO.output(self.pin_e0, False)
		self.delayMicroseconds(1)		# commands need > 37us to settle
	else:
		self.GPIO.output(self.pin_e1, False)
		self.delayMicroseconds(1)		# 1 microsecond pause - enable pulse must be > 450ns 
		self.GPIO.output(self.pin_e1, True)
		self.delayMicroseconds(1)		# 1 microsecond pause - enable pulse must be > 450ns 
		self.GPIO.output(self.pin_e1, False)
		self.delayMicroseconds(1)		# commands need > 37us to settle
	
	

    def message(self, text,x):
        """ Send string to LCD. Newline wraps to second line"""

        for char in text:
            if char == '\n':
                self.write4bits(0xC0,False,x) # next line
            else:
                self.write4bits(ord(char),True,x)


if __name__ == '__main__':

    lcd = Adafruit_CharLCD_Dual()

    lcd.clear()
    lcd.message("  Adafruit 16x2\n  Standard LCD",0)