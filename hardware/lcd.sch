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
Sheet 3 4
Title "1541-rebuild"
Date "2015-09-16"
Rev "1.0"
Comp ""
Comment1 "Erstellt von: Thorsten Kattanek"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4700 4000 0    60   Input ~ 0
D0
Text HLabel 4700 4100 0    60   Input ~ 0
D1
Text HLabel 4700 4200 0    60   Input ~ 0
D2
Text HLabel 4700 4300 0    60   Input ~ 0
D3
Text HLabel 4700 3800 0    60   Input ~ 0
RS
Text HLabel 4700 3900 0    60   Input ~ 0
EN
NoConn ~ 5950 3350
NoConn ~ 6050 3350
NoConn ~ 6150 3350
NoConn ~ 6250 3350
Wire Wire Line
	4700 4000 6350 4000
Wire Wire Line
	6350 4000 6350 3350
Wire Wire Line
	4700 4100 6450 4100
Wire Wire Line
	6450 4100 6450 3350
Wire Wire Line
	4700 4200 6550 4200
Wire Wire Line
	6550 4200 6550 3350
Wire Wire Line
	4700 4300 6650 4300
Wire Wire Line
	6650 4300 6650 3350
Wire Wire Line
	4700 3900 5850 3900
Wire Wire Line
	5850 3900 5850 3350
Wire Wire Line
	4700 3800 5650 3800
Wire Wire Line
	5650 3800 5650 3350
Wire Wire Line
	5750 3350 5750 3400
Wire Wire Line
	5250 3400 6850 3400
Wire Wire Line
	6850 3350 6850 3500
$Comp
L GND #PWR011
U 1 1 55F9D0E8
P 6850 3500
F 0 "#PWR011" H 6850 3250 50  0001 C CNN
F 1 "GND" H 6850 3350 50  0000 C CNN
F 2 "" H 6850 3500 60  0000 C CNN
F 3 "" H 6850 3500 60  0000 C CNN
	1    6850 3500
	1    0    0    -1  
$EndComp
Connection ~ 6850 3400
$Comp
L LCD16X2 DS1
U 1 1 55F9CFCD
P 6100 2850
F 0 "DS1" H 5300 3250 40  0000 C CNN
F 1 "LCD16X2" H 6800 3250 40  0000 C CNN
F 2 "Display:WC1602A" H 6100 2800 35  0000 C CIN
F 3 "" H 6100 2850 60  0000 C CNN
	1    6100 2850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5350 3350 5350 3400
Connection ~ 5750 3400
$Comp
L +5V #PWR012
U 1 1 55F9F555
P 5450 3500
F 0 "#PWR012" H 5450 3350 50  0001 C CNN
F 1 "+5V" H 5450 3640 50  0000 C CNN
F 2 "" H 5450 3500 60  0000 C CNN
F 3 "" H 5450 3500 60  0000 C CNN
	1    5450 3500
	-1   0    0    1   
$EndComp
Wire Wire Line
	5450 3350 5450 3500
$Comp
L POT RV1
U 1 1 55F9F8C0
P 5000 3400
F 0 "RV1" H 5000 3300 50  0000 C CNN
F 1 "10k" H 5000 3400 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_3339P_Angular_ScrewUp" H 5000 3400 60  0001 C CNN
F 3 "" H 5000 3400 60  0000 C CNN
	1    5000 3400
	-1   0    0    1   
$EndComp
Connection ~ 5350 3400
Wire Wire Line
	5000 3550 5000 3750
Wire Wire Line
	5000 3750 5550 3750
Wire Wire Line
	5550 3750 5550 3350
$Comp
L +5V #PWR013
U 1 1 55F9F9A0
P 4650 3400
F 0 "#PWR013" H 4650 3250 50  0001 C CNN
F 1 "+5V" H 4650 3540 50  0000 C CNN
F 2 "" H 4650 3400 60  0000 C CNN
F 3 "" H 4650 3400 60  0000 C CNN
	1    4650 3400
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4650 3400 4750 3400
$Comp
L R R8
U 1 1 55F9FBFA
P 6750 3850
F 0 "R8" V 6830 3850 50  0000 C CNN
F 1 "150" V 6750 3850 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 6680 3850 30  0001 C CNN
F 3 "" H 6750 3850 30  0000 C CNN
	1    6750 3850
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR014
U 1 1 55F9FC92
P 6750 4100
F 0 "#PWR014" H 6750 3950 50  0001 C CNN
F 1 "+5V" H 6750 4240 50  0000 C CNN
F 2 "" H 6750 4100 60  0000 C CNN
F 3 "" H 6750 4100 60  0000 C CNN
	1    6750 4100
	-1   0    0    1   
$EndComp
Wire Wire Line
	6750 3350 6750 3700
Wire Wire Line
	6750 4000 6750 4100
$EndSCHEMATC
