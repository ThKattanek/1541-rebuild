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
L DIL40 P4
U 1 1 55F9CFCC
P 5800 3650
F 0 "P4" H 5800 4700 70  0000 C CNN
F 1 "DIL40" V 5800 3650 60  0000 C CNN
F 2 "Housings_DIP:DIP-40_W15.24mm_LongPads" H 5800 3650 60  0001 C CNN
F 3 "" H 5800 3650 60  0000 C CNN
	1    5800 3650
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X20 P5
U 1 1 55F9DAC3
P 8100 3650
F 0 "P5" H 8100 4700 50  0000 C CNN
F 1 "VIA_PIN_21-40" V 8200 3650 50  0000 C CNN
F 2 "pin_header:pin_header_1x20_smd" H 8100 3650 60  0001 C CNN
F 3 "" H 8100 3650 60  0000 C CNN
	1    8100 3650
	1    0    0    1   
$EndComp
$Comp
L CONN_01X20 P3
U 1 1 55F9DB72
P 3600 3650
F 0 "P3" H 3600 4700 50  0000 C CNN
F 1 "VIA_PIN_1-20" V 3700 3650 50  0000 C CNN
F 2 "pin_header:pin_header_1x20_smd" H 3600 3650 60  0001 C CNN
F 3 "" H 3600 3650 60  0000 C CNN
	1    3600 3650
	-1   0    0    -1  
$EndComp
Text HLabel 4600 2450 1    60   Input ~ 0
PA0
Text HLabel 4500 2450 1    60   Input ~ 0
PA1
Text HLabel 4400 2450 1    60   Input ~ 0
PA2
Text HLabel 4300 2450 1    60   Input ~ 0
PA3
Text HLabel 4200 2450 1    60   Input ~ 0
PA4
Text HLabel 4100 2450 1    60   Input ~ 0
PA5
Text HLabel 4000 2450 1    60   Input ~ 0
PA6
Text HLabel 3900 2450 1    60   Input ~ 0
PA7
Text Label 5100 2800 0    60   ~ 0
PA0
Text Label 5100 2900 0    60   ~ 0
PA1
Text Label 5100 3000 0    60   ~ 0
PA2
Text Label 5100 3100 0    60   ~ 0
PA3
Text Label 5100 3200 0    60   ~ 0
PA4
Text Label 5100 3300 0    60   ~ 0
PA5
Text Label 5100 3400 0    60   ~ 0
PA6
Text Label 5100 3500 0    60   ~ 0
PA7
Wire Wire Line
	3800 2700 5450 2700
Wire Wire Line
	3800 2800 5450 2800
Wire Wire Line
	3800 2900 5450 2900
Wire Wire Line
	3800 3000 5450 3000
Wire Wire Line
	3800 3100 5450 3100
Wire Wire Line
	3800 3200 5450 3200
Wire Wire Line
	3800 3300 5450 3300
Wire Wire Line
	3800 3400 5450 3400
Wire Wire Line
	3800 3500 5450 3500
Wire Wire Line
	3800 3600 5450 3600
Wire Wire Line
	3800 3700 5450 3700
Wire Wire Line
	5450 3800 3800 3800
Wire Wire Line
	3800 3900 5450 3900
Wire Wire Line
	5450 4000 3800 4000
Wire Wire Line
	3800 4100 5450 4100
Wire Wire Line
	5450 4200 3800 4200
Wire Wire Line
	3800 4300 5450 4300
Wire Wire Line
	5450 4400 3800 4400
Wire Wire Line
	3800 4500 5450 4500
Wire Wire Line
	3800 4600 5450 4600
Wire Wire Line
	6150 2700 7900 2700
Wire Wire Line
	7900 2800 6150 2800
Wire Wire Line
	6150 2900 7900 2900
Wire Wire Line
	7900 3000 6150 3000
Wire Wire Line
	6150 3100 7900 3100
Wire Wire Line
	7900 3200 6150 3200
Wire Wire Line
	6150 3300 7900 3300
Wire Wire Line
	7900 3400 6150 3400
Wire Wire Line
	6150 3500 7900 3500
Wire Wire Line
	7900 3600 6150 3600
Wire Wire Line
	7900 3700 6150 3700
Wire Wire Line
	6150 3800 7900 3800
Wire Wire Line
	7900 3900 6150 3900
Wire Wire Line
	6150 4000 7900 4000
Wire Wire Line
	7900 4100 6150 4100
Wire Wire Line
	6150 4200 7900 4200
Wire Wire Line
	6150 4300 7900 4300
Wire Wire Line
	7900 4400 6150 4400
Wire Wire Line
	6150 4500 7900 4500
Wire Wire Line
	7900 4600 6150 4600
Wire Wire Line
	4600 2450 4600 2800
Connection ~ 4600 2800
Wire Wire Line
	4500 2450 4500 2900
Connection ~ 4500 2900
Wire Wire Line
	4400 2450 4400 3000
Connection ~ 4400 3000
Wire Wire Line
	4300 2450 4300 3100
Connection ~ 4300 3100
Wire Wire Line
	4200 2450 4200 3200
Connection ~ 4200 3200
Wire Wire Line
	4100 2450 4100 3300
Connection ~ 4100 3300
Wire Wire Line
	4000 2450 4000 3400
Connection ~ 4000 3400
Wire Wire Line
	3900 2450 3900 3500
Connection ~ 3900 3500
Text Label 5100 2700 0    60   ~ 0
GND
Text Label 5100 3600 0    60   ~ 0
STP1
Text Label 5100 3700 0    60   ~ 0
STP0
Text Label 5100 3800 0    60   ~ 0
MTR
Text Label 5100 3900 0    60   ~ 0
ACT
Text Label 5100 4000 0    60   ~ 0
WPS
Text Label 5100 4100 0    60   ~ 0
DS0
Text Label 5100 4200 0    60   ~ 0
DS1
Text Label 5100 4300 0    60   ~ 0
SYNC
Text Label 5100 4500 0    60   ~ 0
MODE
Text Label 5100 4400 0    60   ~ 0
NC
Text Label 5100 4600 0    60   ~ 0
VCC
Text Label 6200 2700 0    60   ~ 0
BRDY
Text HLabel 6500 2400 1    60   Input ~ 0
BRDY
Wire Wire Line
	6500 2400 6500 2700
Connection ~ 6500 2700
$Comp
L GND #PWR015
U 1 1 55F9667E
P 5400 2450
F 0 "#PWR015" H 5400 2200 50  0001 C CNN
F 1 "GND" H 5400 2300 50  0000 C CNN
F 2 "" H 5400 2450 60  0000 C CNN
F 3 "" H 5400 2450 60  0000 C CNN
	1    5400 2450
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR016
U 1 1 55F96755
P 5400 4800
F 0 "#PWR016" H 5400 4650 50  0001 C CNN
F 1 "+5V" H 5400 4940 50  0000 C CNN
F 2 "" H 5400 4800 60  0000 C CNN
F 3 "" H 5400 4800 60  0000 C CNN
	1    5400 4800
	-1   0    0    1   
$EndComp
Wire Wire Line
	5400 4800 5400 4600
Connection ~ 5400 4600
Wire Wire Line
	5400 2450 5400 2700
Connection ~ 5400 2700
Text HLabel 4700 2450 1    60   Input ~ 0
SPT0
Text HLabel 4800 2450 1    60   Input ~ 0
STP1
Wire Wire Line
	4700 2450 4700 3700
Connection ~ 4700 3700
Wire Wire Line
	4800 2450 4800 3600
Connection ~ 4800 3600
Text HLabel 4900 2450 1    60   Input ~ 0
SYNC
Text HLabel 5000 2450 1    60   Input ~ 0
OE
Wire Wire Line
	4900 2450 4900 4300
Connection ~ 4900 4300
Wire Wire Line
	5000 2450 5000 4500
Connection ~ 5000 4500
Text HLabel 6600 2400 1    60   Input ~ 0
SOE
Wire Wire Line
	6600 2400 6600 2800
Connection ~ 6600 2800
$EndSCHEMATC
