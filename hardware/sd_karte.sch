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
Sheet 2 2
Title "1541-rebuid"
Date "2015-09-15"
Rev "1.0"
Comp ""
Comment1 "Erstellt: von: Thorsten Kattanek"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SD_Card CON1
U 1 1 55F7A1C8
P 6500 3800
F 0 "CON1" H 5850 4350 50  0000 C CNN
F 1 "SD_Card" H 7100 3250 50  0000 C CNN
F 2 "10067847-001" H 6700 4150 50  0000 C CNN
F 3 "" H 6500 3800 60  0000 C CNN
	1    6500 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR4
U 1 1 55F7A326
P 5500 4250
F 0 "#PWR4" H 5500 4000 50  0001 C CNN
F 1 "GND" H 5500 4100 50  0000 C CNN
F 2 "" H 5500 4250 60  0000 C CNN
F 3 "" H 5500 4250 60  0000 C CNN
	1    5500 4250
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 55F7A3CC
P 5250 4400
F 0 "D1" H 5250 4500 50  0000 C CNN
F 1 "1N4148" H 5250 4300 50  0000 C CNN
F 2 "" H 5250 4400 60  0000 C CNN
F 3 "" H 5250 4400 60  0000 C CNN
	1    5250 4400
	0    1    1    0   
$EndComp
$Comp
L D D2
U 1 1 55F7A4EB
P 5250 4800
F 0 "D2" H 5250 4900 50  0000 C CNN
F 1 "1N4148" H 5250 4700 50  0000 C CNN
F 2 "" H 5250 4800 60  0000 C CNN
F 3 "" H 5250 4800 60  0000 C CNN
	1    5250 4800
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR5
U 1 1 55F7A887
P 5250 5050
F 0 "#PWR5" H 5250 4900 50  0001 C CNN
F 1 "+5V" H 5250 5190 50  0000 C CNN
F 2 "" H 5250 5050 60  0000 C CNN
F 3 "" H 5250 5050 60  0000 C CNN
	1    5250 5050
	-1   0    0    1   
$EndComp
NoConn ~ 5600 4200
NoConn ~ 7400 3600
NoConn ~ 7400 3700
NoConn ~ 7400 3900
NoConn ~ 7400 4000
Text HLabel 4300 4100 0    60   Input ~ 0
MISO
Text HLabel 4300 3900 0    60   Input ~ 0
SCK
Text HLabel 4300 3600 0    60   Input ~ 0
MOSI
Text HLabel 4300 3500 0    60   Input ~ 0
SS
NoConn ~ 5600 3400
$Comp
L R R4
U 1 1 55F7B36C
P 4500 3500
F 0 "R4" V 4580 3500 50  0000 C CNN
F 1 "1,8k" V 4500 3500 50  0000 C CNN
F 2 "" V 4430 3500 30  0000 C CNN
F 3 "" H 4500 3500 30  0000 C CNN
	1    4500 3500
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 55F7B401
P 4700 3600
F 0 "R5" V 4780 3600 50  0000 C CNN
F 1 "1,8k" V 4700 3600 50  0000 C CNN
F 2 "" V 4630 3600 30  0000 C CNN
F 3 "" H 4700 3600 30  0000 C CNN
	1    4700 3600
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 55F7B48C
P 4500 3900
F 0 "R6" V 4580 3900 50  0000 C CNN
F 1 "1,8k" V 4500 3900 50  0000 C CNN
F 2 "" V 4430 3900 30  0000 C CNN
F 3 "" H 4500 3900 30  0000 C CNN
	1    4500 3900
	0    1    1    0   
$EndComp
$Comp
L R R1
U 1 1 55F7BA6C
P 4700 3250
F 0 "R1" V 4780 3250 50  0000 C CNN
F 1 "3,3k" V 4700 3250 50  0000 C CNN
F 2 "" V 4630 3250 30  0000 C CNN
F 3 "" H 4700 3250 30  0000 C CNN
	1    4700 3250
	1    0    0    -1  
$EndComp
$Comp
L R R2
U 1 1 55F7BC20
P 4900 3250
F 0 "R2" V 4980 3250 50  0000 C CNN
F 1 "3,3k" V 4900 3250 50  0000 C CNN
F 2 "" V 4830 3250 30  0000 C CNN
F 3 "" H 4900 3250 30  0000 C CNN
	1    4900 3250
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 55F7BCCD
P 5100 3250
F 0 "R3" V 5180 3250 50  0000 C CNN
F 1 "3,3k" V 5100 3250 50  0000 C CNN
F 2 "" V 5030 3250 30  0000 C CNN
F 3 "" H 5100 3250 30  0000 C CNN
	1    5100 3250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR3
U 1 1 55F7BE30
P 4900 2850
F 0 "#PWR3" H 4900 2600 50  0001 C CNN
F 1 "GND" H 4900 2700 50  0000 C CNN
F 2 "" H 4900 2850 60  0000 C CNN
F 3 "" H 4900 2850 60  0000 C CNN
	1    4900 2850
	-1   0    0    1   
$EndComp
Wire Wire Line
	5250 4650 5250 4550
Wire Wire Line
	5600 3800 5250 3800
Wire Wire Line
	5250 3800 5250 4250
Wire Wire Line
	5250 4950 5250 5050
Wire Wire Line
	5600 4100 4300 4100
Wire Wire Line
	4300 3500 4350 3500
Wire Wire Line
	4650 3500 5600 3500
Wire Wire Line
	4850 3600 5600 3600
Wire Wire Line
	4550 3600 4300 3600
Wire Wire Line
	4300 3900 4350 3900
Wire Wire Line
	4650 3900 5600 3900
Wire Wire Line
	4700 3400 4700 3500
Connection ~ 4700 3500
Wire Wire Line
	4900 3400 4900 3600
Connection ~ 4900 3600
Wire Wire Line
	5100 3400 5100 3900
Connection ~ 5100 3900
Wire Wire Line
	4900 2850 4900 3100
Wire Wire Line
	5100 2950 5100 3100
Wire Wire Line
	4700 2950 5100 2950
Connection ~ 4900 2950
Wire Wire Line
	4700 3100 4700 2950
Wire Wire Line
	5600 3700 5500 3700
Wire Wire Line
	5500 3700 5500 4250
Wire Wire Line
	5600 4000 5500 4000
Connection ~ 5500 4000
$EndSCHEMATC
