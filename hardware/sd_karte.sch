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
Sheet 2 4
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
P 6700 3700
F 0 "CON1" H 6050 4250 50  0000 C CNN
F 1 "SD_Card" H 7300 3150 50  0000 C CNN
F 2 "Connect:SD_Card_Receptacle" H 6900 4050 50  0001 C CNN
F 3 "" H 6700 3700 60  0000 C CNN
	1    6700 3700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR08
U 1 1 55F7A326
P 5700 4150
F 0 "#PWR08" H 5700 3900 50  0001 C CNN
F 1 "GND" H 5700 4000 50  0000 C CNN
F 2 "" H 5700 4150 60  0000 C CNN
F 3 "" H 5700 4150 60  0000 C CNN
	1    5700 4150
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 55F7A3CC
P 5450 4300
F 0 "D1" H 5450 4400 50  0000 C CNN
F 1 "1N4148" H 5450 4200 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 5450 4300 60  0001 C CNN
F 3 "" H 5450 4300 60  0000 C CNN
	1    5450 4300
	0    1    1    0   
$EndComp
$Comp
L D D2
U 1 1 55F7A4EB
P 5450 4700
F 0 "D2" H 5450 4800 50  0000 C CNN
F 1 "1N4148" H 5450 4600 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 5450 4700 60  0001 C CNN
F 3 "" H 5450 4700 60  0000 C CNN
	1    5450 4700
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR09
U 1 1 55F7A887
P 5450 4950
F 0 "#PWR09" H 5450 4800 50  0001 C CNN
F 1 "+5V" H 5450 5090 50  0000 C CNN
F 2 "" H 5450 4950 60  0000 C CNN
F 3 "" H 5450 4950 60  0000 C CNN
	1    5450 4950
	-1   0    0    1   
$EndComp
NoConn ~ 5800 4100
NoConn ~ 7600 3500
NoConn ~ 7600 3600
NoConn ~ 7600 3800
NoConn ~ 7600 3900
Text HLabel 4250 4000 0    60   Input ~ 0
MISO
Text HLabel 4250 3800 0    60   Input ~ 0
SCK
Text HLabel 4250 3500 0    60   Input ~ 0
MOSI
Text HLabel 4250 3400 0    60   Input ~ 0
SS
NoConn ~ 5800 3300
$Comp
L R R5
U 1 1 55F7B36C
P 4700 3400
F 0 "R5" V 4780 3400 50  0000 C CNN
F 1 "1,8k" V 4700 3400 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4630 3400 30  0001 C CNN
F 3 "" H 4700 3400 30  0000 C CNN
	1    4700 3400
	0    1    1    0   
$EndComp
$Comp
L R R6
U 1 1 55F7B401
P 4900 3500
F 0 "R6" V 4980 3500 50  0000 C CNN
F 1 "1,8k" V 4900 3500 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4830 3500 30  0001 C CNN
F 3 "" H 4900 3500 30  0000 C CNN
	1    4900 3500
	0    1    1    0   
$EndComp
$Comp
L R R7
U 1 1 55F7B48C
P 4700 3800
F 0 "R7" V 4780 3800 50  0000 C CNN
F 1 "1,8k" V 4700 3800 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4630 3800 30  0001 C CNN
F 3 "" H 4700 3800 30  0000 C CNN
	1    4700 3800
	0    1    1    0   
$EndComp
$Comp
L R R2
U 1 1 55F7BA6C
P 4900 3150
F 0 "R2" V 4980 3150 50  0000 C CNN
F 1 "3,3k" V 4900 3150 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4830 3150 30  0001 C CNN
F 3 "" H 4900 3150 30  0000 C CNN
	1    4900 3150
	1    0    0    -1  
$EndComp
$Comp
L R R3
U 1 1 55F7BC20
P 5100 3150
F 0 "R3" V 5180 3150 50  0000 C CNN
F 1 "3,3k" V 5100 3150 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 5030 3150 30  0001 C CNN
F 3 "" H 5100 3150 30  0000 C CNN
	1    5100 3150
	1    0    0    -1  
$EndComp
$Comp
L R R4
U 1 1 55F7BCCD
P 5300 3150
F 0 "R4" V 5380 3150 50  0000 C CNN
F 1 "3,3k" V 5300 3150 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 5230 3150 30  0001 C CNN
F 3 "" H 5300 3150 30  0000 C CNN
	1    5300 3150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR010
U 1 1 55F7BE30
P 5100 2750
F 0 "#PWR010" H 5100 2500 50  0001 C CNN
F 1 "GND" H 5100 2600 50  0000 C CNN
F 2 "" H 5100 2750 60  0000 C CNN
F 3 "" H 5100 2750 60  0000 C CNN
	1    5100 2750
	-1   0    0    1   
$EndComp
Wire Wire Line
	5450 4550 5450 4450
Wire Wire Line
	5800 3700 5450 3700
Wire Wire Line
	5450 3700 5450 4150
Wire Wire Line
	5450 4850 5450 4950
Wire Wire Line
	5800 4000 4250 4000
Wire Wire Line
	4250 3400 4550 3400
Wire Wire Line
	4850 3400 5800 3400
Wire Wire Line
	5050 3500 5800 3500
Wire Wire Line
	4750 3500 4250 3500
Wire Wire Line
	4250 3800 4550 3800
Wire Wire Line
	4850 3800 5800 3800
Wire Wire Line
	4900 3300 4900 3400
Connection ~ 4900 3400
Wire Wire Line
	5100 3300 5100 3500
Connection ~ 5100 3500
Wire Wire Line
	5300 3300 5300 3800
Connection ~ 5300 3800
Wire Wire Line
	5100 2750 5100 3000
Wire Wire Line
	5300 2850 5300 3000
Wire Wire Line
	4900 2850 5300 2850
Connection ~ 5100 2850
Wire Wire Line
	4900 3000 4900 2850
Wire Wire Line
	5800 3600 5700 3600
Wire Wire Line
	5700 3600 5700 4150
Wire Wire Line
	5800 3900 5700 3900
Connection ~ 5700 3900
$EndSCHEMATC
