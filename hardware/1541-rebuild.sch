EESchema Schematic File Version 2
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:Oscillators
LIBS:1541-rebuild-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 4
Title "1541-rebuild"
Date "2015-09-15"
Rev "1.0"
Comp ""
Comment1 "Erstellt: von: Thorsten Kattanek"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA1284P-P IC1
U 1 1 55F7E447
P 5100 3800
F 0 "IC1" H 4250 5680 40  0000 L BNN
F 1 "ATMEGA1284P-P" H 5500 1850 40  0000 L BNN
F 2 "Housings_DIP:DIP-40_W15.24mm_LongPads" H 5100 3800 30  0000 C CIN
F 3 "" H 5100 3800 60  0000 C CNN
	1    5100 3800
	1    0    0    -1  
$EndComp
Text Notes 650  7450 0    60   ~ 0
Am meiner 1541II Platine (ASSY ???) habe ich folgende modifiktionen durchgeführt:\n- PIN 40 von U10 (Gate Array 251828) von Platine getrennt (BYTE READY)\n- U8 (VIA 6522) ausgelötet und gesockelt\n- Dauerläufer behoben durch trennen einer Leiterbahn (genauer beschreiben)
$Comp
L TCXO3 X1
U 1 1 55F7CB9E
P 2700 3050
F 0 "X1" H 2700 3350 70  0000 C CNN
F 1 "20Mhz" H 2700 3050 70  0000 C CNN
F 2 "Oscillator-Modules:OSCILLATOR_KXO-200_LargePads" H 2700 3050 60  0001 C CNN
F 3 "" H 2700 3050 60  0000 C CNN
	1    2700 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	3400 2900 4100 2900
NoConn ~ 3400 3200
$Comp
L GND #PWR01
U 1 1 55F7D4A6
P 1800 3200
F 0 "#PWR01" H 1800 2950 50  0001 C CNN
F 1 "GND" H 1800 3050 50  0000 C CNN
F 2 "" H 1800 3200 60  0000 C CNN
F 3 "" H 1800 3200 60  0000 C CNN
	1    1800 3200
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR02
U 1 1 55F7D4E4
P 1800 2900
F 0 "#PWR02" H 1800 2750 50  0001 C CNN
F 1 "+5V" H 1800 3040 50  0000 C CNN
F 2 "" H 1800 2900 60  0000 C CNN
F 3 "" H 1800 2900 60  0000 C CNN
	1    1800 2900
	0    -1   -1   0   
$EndComp
$Comp
L C C3
U 1 1 55F7D642
P 1900 3050
F 0 "C3" H 1925 3150 50  0000 L CNN
F 1 "100n" H 1925 2950 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 1938 2900 30  0001 C CNN
F 3 "" H 1900 3050 60  0000 C CNN
	1    1900 3050
	1    0    0    -1  
$EndComp
Wire Wire Line
	1800 2900 2000 2900
Connection ~ 1900 2900
Wire Wire Line
	1800 3200 2000 3200
Connection ~ 1900 3200
NoConn ~ 4100 2500
$Comp
L GND #PWR03
U 1 1 55F7EFD4
P 5000 5950
F 0 "#PWR03" H 5000 5700 50  0001 C CNN
F 1 "GND" H 5000 5800 50  0000 C CNN
F 2 "" H 5000 5950 60  0000 C CNN
F 3 "" H 5000 5950 60  0000 C CNN
	1    5000 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 5800 4900 5900
Wire Wire Line
	4900 5900 5100 5900
Wire Wire Line
	5000 5900 5000 5950
Wire Wire Line
	5100 5900 5100 5800
Connection ~ 5000 5900
$Comp
L +5V #PWR04
U 1 1 55F7F7C2
P 5000 1650
F 0 "#PWR04" H 5000 1500 50  0001 C CNN
F 1 "+5V" H 5000 1790 50  0000 C CNN
F 2 "" H 5000 1650 60  0000 C CNN
F 3 "" H 5000 1650 60  0000 C CNN
	1    5000 1650
	1    0    0    -1  
$EndComp
Wire Wire Line
	4900 1800 4900 1700
Wire Wire Line
	4900 1700 5100 1700
Wire Wire Line
	5000 1700 5000 1650
Wire Wire Line
	5100 1700 5100 1800
Connection ~ 5000 1700
NoConn ~ 4100 3300
$Comp
L R R1
U 1 1 55F7EA97
P 3850 2100
F 0 "R1" V 3930 2100 50  0000 C CNN
F 1 "10k" V 3850 2100 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3780 2100 30  0001 C CNN
F 3 "" H 3850 2100 30  0000 C CNN
	1    3850 2100
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR05
U 1 1 55F7ED10
P 3600 2100
F 0 "#PWR05" H 3600 1950 50  0001 C CNN
F 1 "+5V" H 3600 2240 50  0000 C CNN
F 2 "" H 3600 2100 60  0000 C CNN
F 3 "" H 3600 2100 60  0000 C CNN
	1    3600 2100
	0    -1   -1   0   
$EndComp
Wire Wire Line
	3700 2100 3600 2100
Wire Wire Line
	4000 2100 4100 2100
$Comp
L C C1
U 1 1 55F7F83D
P 1350 1250
F 0 "C1" H 1375 1350 50  0000 L CNN
F 1 "100n" H 1375 1150 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 1388 1100 30  0001 C CNN
F 3 "" H 1350 1250 60  0000 C CNN
	1    1350 1250
	0    1    1    0   
$EndComp
$Comp
L C C2
U 1 1 55F7FBA4
P 1350 1550
F 0 "C2" H 1375 1650 50  0000 L CNN
F 1 "100n" H 1375 1450 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Disc_D6_P5" H 1388 1400 30  0001 C CNN
F 3 "" H 1350 1550 60  0000 C CNN
	1    1350 1550
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR06
U 1 1 55F800FF
P 1500 1050
F 0 "#PWR06" H 1500 900 50  0001 C CNN
F 1 "+5V" H 1500 1190 50  0000 C CNN
F 2 "" H 1500 1050 60  0000 C CNN
F 3 "" H 1500 1050 60  0000 C CNN
	1    1500 1050
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 55F80221
P 1200 1050
F 0 "#PWR07" H 1200 800 50  0001 C CNN
F 1 "GND" H 1200 900 50  0000 C CNN
F 2 "" H 1200 1050 60  0000 C CNN
F 3 "" H 1200 1050 60  0000 C CNN
	1    1200 1050
	-1   0    0    1   
$EndComp
Wire Wire Line
	1200 1050 1200 1550
Connection ~ 1200 1250
Wire Wire Line
	1500 1050 1500 1550
Connection ~ 1500 1250
Text Notes 650  750  0    60   ~ 0
Stützkondensatoren für IC1
Wire Wire Line
	6100 3400 8800 3400
Wire Wire Line
	6100 3500 8800 3500
Wire Wire Line
	6100 3600 8800 3600
Wire Wire Line
	6100 3700 8800 3700
$Sheet
S 8800 3300 850  500 
U 55F7A0F9
F0 "SD Karte" 60
F1 "sd_karte.sch" 60
F2 "MISO" I L 8800 3600 60 
F3 "SCK" I L 8800 3700 60 
F4 "MOSI" I L 8800 3500 60 
F5 "SS" I L 8800 3400 60 
$EndSheet
$Comp
L CONN_01X06 P1
U 1 1 55F8E45C
P 7500 1700
F 0 "P1" H 7500 2050 50  0000 C CNN
F 1 "1541_CN3" V 7600 1700 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x06" H 7500 1700 60  0001 C CNN
F 3 "" H 7500 1700 60  0000 C CNN
	1    7500 1700
	0    -1   -1   0   
$EndComp
Wire Wire Line
	7450 1900 7450 3000
Wire Wire Line
	7450 3000 6100 3000
Wire Wire Line
	6100 3100 7650 3100
Wire Wire Line
	7650 3100 7650 1900
Wire Wire Line
	6100 3200 7550 3200
Wire Wire Line
	7550 3200 7550 1900
Wire Wire Line
	6100 3300 7750 3300
Wire Wire Line
	7750 3300 7750 1900
$Sheet
S 6400 1400 600  500 
U 55F9179B
F0 "LCD Display" 60
F1 "lcd.sch" 60
F2 "D0" I B 6450 1900 60 
F3 "D1" I B 6550 1900 60 
F4 "D2" I B 6650 1900 60 
F5 "D3" I B 6750 1900 60 
F6 "RS" I B 6850 1900 60 
F7 "EN" I B 6950 1900 60 
$EndSheet
Wire Wire Line
	6450 1900 6450 2100
Wire Wire Line
	6450 2100 6100 2100
Wire Wire Line
	6550 1900 6550 2200
Wire Wire Line
	6550 2200 6100 2200
Wire Wire Line
	6650 1900 6650 2300
Wire Wire Line
	6650 2300 6100 2300
Wire Wire Line
	6750 1900 6750 2400
Wire Wire Line
	6750 2400 6100 2400
Wire Wire Line
	6850 1900 6850 2500
Wire Wire Line
	6850 2500 6100 2500
Wire Wire Line
	6950 1900 6950 2600
Wire Wire Line
	6950 2600 6100 2600
NoConn ~ 7250 1900
NoConn ~ 7350 1900
NoConn ~ 6100 2700
NoConn ~ 6100 2800
NoConn ~ 6100 4200
NoConn ~ 6100 4300
NoConn ~ 6100 4400
NoConn ~ 6100 4600
$Sheet
S 6600 4250 1100 1300
U 55F9B22C
F0 "VIA 6522 Sockel" 60
F1 "via6522_sockel.sch" 60
F2 "PA0" I L 6600 4800 60 
F3 "PA1" I L 6600 4900 60 
F4 "PA2" I L 6600 5000 60 
F5 "PA3" I L 6600 5100 60 
F6 "PA4" I L 6600 5200 60 
F7 "PA5" I L 6600 5300 60 
F8 "PA6" I L 6600 5400 60 
F9 "PA7" I L 6600 5500 60 
F10 "BRDY" I L 6600 4300 60 
F11 "SPT0" I R 7700 4350 60 
F12 "STP1" I R 7700 4450 60 
F13 "SYNC" I L 6600 4400 60 
F14 "OE" I R 7700 4550 60 
F15 "SOE" I L 6600 4500 60 
$EndSheet
Wire Wire Line
	6100 4800 6600 4800
Wire Wire Line
	6100 4900 6600 4900
Wire Wire Line
	6100 5000 6600 5000
Wire Wire Line
	6100 5100 6600 5100
Wire Wire Line
	6100 5200 6600 5200
Wire Wire Line
	6100 5300 6600 5300
Wire Wire Line
	6100 5400 6600 5400
Wire Wire Line
	6100 5500 6600 5500
Wire Wire Line
	6100 4500 6600 4500
Wire Wire Line
	6100 4000 6300 4000
Wire Wire Line
	6300 4000 6300 4400
Wire Wire Line
	6300 4400 6600 4400
Wire Wire Line
	6100 3900 6400 3900
Wire Wire Line
	6400 3900 6400 4300
Wire Wire Line
	6400 4300 6600 4300
$Comp
L CONN_01X01 P2
U 1 1 55F9A2C7
P 8050 3850
F 0 "P2" H 8050 3950 50  0000 C CNN
F 1 "1541_CN4_PIN7_[MOTOR]" V 8150 3850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x01" H 8050 3850 60  0001 C CNN
F 3 "" H 8050 3850 60  0000 C CNN
	1    8050 3850
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6100 4100 8050 4100
Wire Wire Line
	8050 4100 8050 4050
$EndSCHEMATC
