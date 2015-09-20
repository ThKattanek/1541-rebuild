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
Sheet 4 4
Title "1541-rebuild"
Date "2015-09-16"
Rev "V1.0"
Comp ""
Comment1 "Erstellt von: Thorsten Kattanek"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L DIL40 P2
U 1 1 55F9CFCC
P 6400 5300
F 0 "P2" H 6400 6350 70  0000 C CNN
F 1 "DIL40" V 6400 5300 60  0000 C CNN
F 2 "Housings_DIP:DIP-40_W15.24mm_LongPads" H 6400 5300 60  0001 C CNN
F 3 "" H 6400 5300 60  0000 C CNN
	1    6400 5300
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X20 P3
U 1 1 55F9DAC3
P 8700 5300
F 0 "P3" H 8700 6350 50  0000 C CNN
F 1 "VIA_PIN_21-40" V 8800 5300 50  0000 C CNN
F 2 "pin_header:pin_header_1x20_smd" H 8700 5300 60  0001 C CNN
F 3 "" H 8700 5300 60  0000 C CNN
	1    8700 5300
	1    0    0    1   
$EndComp
$Comp
L CONN_01X20 P1
U 1 1 55F9DB72
P 3100 5300
F 0 "P1" H 3100 6350 50  0000 C CNN
F 1 "VIA_PIN_1-20" V 3200 5300 50  0000 C CNN
F 2 "pin_header:pin_header_1x20_smd" H 3100 5300 60  0001 C CNN
F 3 "" H 3100 5300 60  0000 C CNN
	1    3100 5300
	-1   0    0    -1  
$EndComp
Text HLabel 5750 2500 0    60   Input ~ 0
PA0
Text HLabel 5750 2400 0    60   Input ~ 0
PA1
Text HLabel 5750 2300 0    60   Input ~ 0
PA2
Text HLabel 5750 2200 0    60   Input ~ 0
PA3
Text HLabel 7550 2500 2    60   Input ~ 0
PA4
Text HLabel 7550 2400 2    60   Input ~ 0
PA5
Text HLabel 7550 2300 2    60   Input ~ 0
PA6
Text HLabel 7550 2200 2    60   Input ~ 0
PA7
Text Label 5700 4450 0    60   ~ 0
PA0
Text Label 5700 4550 0    60   ~ 0
PA1
Text Label 5700 4650 0    60   ~ 0
PA2
Text Label 5700 4750 0    60   ~ 0
PA3
Text Label 5700 4850 0    60   ~ 0
PA4
Text Label 5700 4950 0    60   ~ 0
PA5
Text Label 5700 5050 0    60   ~ 0
PA6
Text Label 5700 5150 0    60   ~ 0
PA7
Text Label 5700 4350 0    60   ~ 0
GND
Text Label 5700 5250 0    60   ~ 0
STP1
Text Label 5700 5350 0    60   ~ 0
STP0
Text Label 5700 5450 0    60   ~ 0
MTR
Text Label 5700 5550 0    60   ~ 0
ACT
Text Label 5700 5650 0    60   ~ 0
WPS
Text Label 5700 5750 0    60   ~ 0
DS0
Text Label 5700 5850 0    60   ~ 0
DS1
Text Label 5700 5950 0    60   ~ 0
SYNC
Text Label 5700 6150 0    60   ~ 0
MODE
Text Label 5700 6050 0    60   ~ 0
NC
Text Label 5700 6250 0    60   ~ 0
VCC
Text Label 6800 4350 0    60   ~ 0
BRDY
Text HLabel 7100 4050 1    60   Input ~ 0
BRDY
$Comp
L GND #PWR015
U 1 1 55F9667E
P 6000 4100
F 0 "#PWR015" H 6000 3850 50  0001 C CNN
F 1 "GND" H 6000 3950 50  0000 C CNN
F 2 "" H 6000 4100 60  0000 C CNN
F 3 "" H 6000 4100 60  0000 C CNN
	1    6000 4100
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR016
U 1 1 55F96755
P 6000 6450
F 0 "#PWR016" H 6000 6300 50  0001 C CNN
F 1 "+5V" H 6000 6590 50  0000 C CNN
F 2 "" H 6000 6450 60  0000 C CNN
F 3 "" H 6000 6450 60  0000 C CNN
	1    6000 6450
	-1   0    0    1   
$EndComp
Text HLabel 4850 4100 1    60   Input ~ 0
SPT0
Text HLabel 4950 4100 1    60   Input ~ 0
STP1
Text HLabel 5500 4100 1    60   Input ~ 0
SYNC
Text HLabel 5600 4100 1    60   Input ~ 0
OE
Text HLabel 7200 4050 1    60   Input ~ 0
SOE
Text HLabel 5150 4100 1    60   Input ~ 0
MTR
$Comp
L 74LS244 U1
U 1 1 55FE6C3C
P 6650 2000
F 0 "U1" H 6700 1800 60  0000 C CNN
F 1 "74LS244" H 6750 1600 60  0000 C CNN
F 2 "" H 6650 2000 60  0000 C CNN
F 3 "" H 6650 2000 60  0000 C CNN
	1    6650 2000
	-1   0    0    1   
$EndComp
Entry Wire Line
	5650 1700 5750 1800
Entry Wire Line
	5650 1800 5750 1900
Entry Wire Line
	5650 1900 5750 2000
Entry Wire Line
	5650 2000 5750 2100
Entry Wire Line
	7750 2100 7850 2200
Entry Wire Line
	7750 1800 7850 1900
Entry Wire Line
	7750 1900 7850 2000
Entry Wire Line
	7750 2000 7850 2100
$Comp
L GND #PWR017
U 1 1 55FE7C1F
P 7400 1450
F 0 "#PWR017" H 7400 1200 50  0001 C CNN
F 1 "GND" H 7400 1300 50  0000 C CNN
F 2 "" H 7400 1450 60  0000 C CNN
F 3 "" H 7400 1450 60  0000 C CNN
	1    7400 1450
	-1   0    0    1   
$EndComp
Entry Wire Line
	4050 3750 4150 3850
Entry Wire Line
	3950 3750 4050 3850
Entry Wire Line
	3850 3750 3950 3850
Entry Wire Line
	3750 3750 3850 3850
Entry Wire Line
	3650 3750 3750 3850
Entry Wire Line
	3550 3750 3650 3850
Entry Wire Line
	3450 3750 3550 3850
Entry Wire Line
	3350 3750 3450 3850
Text Label 4150 4050 1    60   ~ 0
D0
Text Label 4050 4050 1    60   ~ 0
D1
Text Label 3950 4050 1    60   ~ 0
D2
Text Label 3850 4050 1    60   ~ 0
D3
Text Label 3750 4050 1    60   ~ 0
D4
Text Label 3650 4050 1    60   ~ 0
D5
Text Label 3550 4050 1    60   ~ 0
D6
Text Label 3450 4050 1    60   ~ 0
D7
Wire Wire Line
	3300 4350 6050 4350
Wire Wire Line
	3300 4450 6050 4450
Wire Wire Line
	3300 4650 6050 4650
Wire Wire Line
	3300 4750 6050 4750
Wire Wire Line
	3300 4850 6050 4850
Wire Wire Line
	3300 4950 6050 4950
Wire Wire Line
	3300 5050 6050 5050
Wire Wire Line
	3300 5150 6050 5150
Wire Wire Line
	3300 5250 6050 5250
Wire Wire Line
	3300 5350 6050 5350
Wire Wire Line
	3300 5450 6050 5450
Wire Wire Line
	3300 5550 6050 5550
Wire Wire Line
	6050 5650 3300 5650
Wire Wire Line
	3300 5750 6050 5750
Wire Wire Line
	6050 5850 3300 5850
Wire Wire Line
	3300 5950 6050 5950
Wire Wire Line
	6050 6050 3300 6050
Wire Wire Line
	3300 6150 6050 6150
Wire Wire Line
	3300 6250 6050 6250
Wire Wire Line
	6750 4350 8500 4350
Wire Wire Line
	6750 4450 8500 4450
Wire Wire Line
	6750 4550 8500 4550
Wire Wire Line
	8500 4650 6750 4650
Wire Wire Line
	6750 4750 8500 4750
Wire Wire Line
	8500 4850 6750 4850
Wire Wire Line
	6750 4950 8500 4950
Wire Wire Line
	8500 5050 6750 5050
Wire Wire Line
	6750 5150 8500 5150
Wire Wire Line
	8500 5250 6750 5250
Wire Wire Line
	8500 5350 6750 5350
Wire Wire Line
	6750 5450 8500 5450
Wire Wire Line
	8500 5550 6750 5550
Wire Wire Line
	6750 5650 8500 5650
Wire Wire Line
	8500 5750 6750 5750
Wire Wire Line
	6750 5850 8500 5850
Wire Wire Line
	6750 5950 8500 5950
Wire Wire Line
	8500 6050 6750 6050
Wire Wire Line
	6750 6150 8500 6150
Wire Wire Line
	8500 6250 6750 6250
Connection ~ 4150 4450
Connection ~ 4050 4550
Connection ~ 3950 4650
Connection ~ 3850 4750
Connection ~ 3750 4850
Connection ~ 3650 4950
Connection ~ 3550 5050
Connection ~ 3450 5150
Wire Wire Line
	7100 4050 7100 4350
Connection ~ 7100 4350
Wire Wire Line
	6000 6450 6000 6250
Connection ~ 6000 6250
Wire Wire Line
	6000 4100 6000 4350
Connection ~ 6000 4350
Wire Wire Line
	4850 4100 4850 5350
Connection ~ 4850 5350
Wire Wire Line
	4950 4100 4950 5250
Connection ~ 4950 5250
Wire Wire Line
	5500 4100 5500 5950
Connection ~ 5500 5950
Wire Wire Line
	5600 4100 5600 6150
Connection ~ 5600 6150
Wire Wire Line
	7200 4050 7200 4450
Connection ~ 7200 4450
Wire Wire Line
	5150 4100 5150 5450
Connection ~ 5150 5450
Wire Wire Line
	3300 4550 6050 4550
Wire Wire Line
	4150 3850 4150 4450
Wire Wire Line
	4050 3850 4050 4550
Wire Wire Line
	3450 3850 3450 5150
Wire Wire Line
	3550 3850 3550 5050
Wire Wire Line
	3650 3850 3650 4950
Wire Wire Line
	3750 3850 3750 4850
Wire Wire Line
	3850 3850 3850 4750
Wire Wire Line
	3950 3850 3950 4650
Wire Bus Line
	5650 1100 5650 2100
Wire Bus Line
	5650 1100 7850 1100
Wire Bus Line
	7850 1100 7850 2250
Wire Wire Line
	5750 2200 5950 2200
Wire Wire Line
	5750 2300 5950 2300
Wire Wire Line
	5750 2400 5950 2400
Wire Wire Line
	5750 2500 5950 2500
Wire Wire Line
	7350 2200 7550 2200
Wire Wire Line
	7350 2300 7550 2300
Wire Wire Line
	7350 2400 7550 2400
Wire Wire Line
	7350 2500 7550 2500
Wire Wire Line
	5750 1800 5950 1800
Wire Wire Line
	5750 2000 5950 2000
Wire Wire Line
	7400 1450 7400 1600
Wire Wire Line
	7400 1500 7350 1500
Wire Wire Line
	7750 1800 7350 1800
Wire Wire Line
	7750 1900 7350 1900
Wire Wire Line
	7750 2000 7350 2000
Wire Wire Line
	7350 2100 7750 2100
Wire Bus Line
	3300 3750 4100 3750
Wire Wire Line
	5750 1900 5950 1900
Wire Wire Line
	5950 2100 5750 2100
Text Label 5800 2100 0    60   ~ 0
D0
Text Label 5800 2000 0    60   ~ 0
D1
Text Label 5800 1900 0    60   ~ 0
D2
Text Label 5800 1800 0    60   ~ 0
D3
Text Label 7400 2100 0    60   ~ 0
D4
Text Label 7400 2000 0    60   ~ 0
D5
Text Label 7400 1900 0    60   ~ 0
D6
Text Label 7400 1800 0    60   ~ 0
D7
Wire Wire Line
	7400 1600 7350 1600
Connection ~ 7400 1500
$EndSCHEMATC
