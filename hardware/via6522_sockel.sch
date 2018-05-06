EESchema Schematic File Version 2
LIBS:1541-rebuild-rescue
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
LIBS:w_analog
LIBS:w_connectors
LIBS:w_device
LIBS:w_logic
LIBS:w_memory
LIBS:w_microcontrollers
LIBS:w_opto
LIBS:w_relay
LIBS:w_rtx
LIBS:w_transistor
LIBS:w_vacuum
LIBS:kattanek
LIBS:1541-rebuild-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 4
Title "1541-rebuid"
Date "2018-05-06"
Rev "1.3.3"
Comp ""
Comment1 "Erstellt von: Thorsten Kattanek"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L DIL40 P2
U 1 1 55F9CFCC
P 6400 3850
F 0 "P2" H 6400 4900 70  0000 C CNN
F 1 "VIA-6522" V 6400 3850 60  0000 C CNN
F 2 "w_pth_circuits:dil_40-600_socket" H 6400 3850 60  0001 C CNN
F 3 "" H 6400 3850 60  0000 C CNN
	1    6400 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X20 P3
U 1 1 55F9DAC3
P 8700 3850
F 0 "P3" H 8700 4900 50  0000 C CNN
F 1 "VIA_PIN_21-40" V 8800 3850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x20_Pitch2.54mm" H 8700 3850 60  0001 C CNN
F 3 "" H 8700 3850 60  0000 C CNN
	1    8700 3850
	1    0    0    1   
$EndComp
$Comp
L CONN_01X20 P1
U 1 1 55F9DB72
P 3100 3850
F 0 "P1" H 3100 4900 50  0000 C CNN
F 1 "VIA_PIN_1-20" V 3200 3850 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x20_Pitch2.54mm" H 3100 3850 60  0001 C CNN
F 3 "" H 3100 3850 60  0000 C CNN
	1    3100 3850
	-1   0    0    -1  
$EndComp
Text HLabel 4150 2400 1    60   Input ~ 0
PA0
Text HLabel 4050 2400 1    60   Input ~ 0
PA1
Text HLabel 3950 2400 1    60   Input ~ 0
PA2
Text HLabel 3850 2400 1    60   Input ~ 0
PA3
Text HLabel 3750 2400 1    60   Input ~ 0
PA4
Text HLabel 3650 2400 1    60   Input ~ 0
PA5
Text HLabel 3550 2400 1    60   Input ~ 0
PA6
Text HLabel 3450 2400 1    60   Input ~ 0
PA7
Text Label 5700 3000 0    60   ~ 0
PA0
Text Label 5700 3100 0    60   ~ 0
PA1
Text Label 5700 3200 0    60   ~ 0
PA2
Text Label 5700 3300 0    60   ~ 0
PA3
Text Label 5700 3400 0    60   ~ 0
PA4
Text Label 5700 3500 0    60   ~ 0
PA5
Text Label 5700 3600 0    60   ~ 0
PA6
Text Label 5700 3700 0    60   ~ 0
PA7
Text Label 5700 2900 0    60   ~ 0
GND
Text Label 5700 3800 0    60   ~ 0
STP1
Text Label 5700 3900 0    60   ~ 0
STP0
Text Label 5700 4000 0    60   ~ 0
MTR
Text Label 5700 4100 0    60   ~ 0
ACT
Text Label 5700 4200 0    60   ~ 0
WPS
Text Label 5700 4300 0    60   ~ 0
DS0
Text Label 5700 4400 0    60   ~ 0
DS1
Text Label 5700 4500 0    60   ~ 0
SYNC
Text Label 5700 4700 0    60   ~ 0
MODE
Text Label 5700 4600 0    60   ~ 0
NC
Text Label 5700 4800 0    60   ~ 0
VCC
Text Label 6800 2900 0    60   ~ 0
BRDY
Text HLabel 7100 2600 1    60   Input ~ 0
BRDY
$Comp
L GND #PWR021
U 1 1 55F9667E
P 6000 2650
F 0 "#PWR021" H 6000 2400 50  0001 C CNN
F 1 "GND" H 6000 2500 50  0000 C CNN
F 2 "" H 6000 2650 60  0000 C CNN
F 3 "" H 6000 2650 60  0000 C CNN
	1    6000 2650
	-1   0    0    1   
$EndComp
$Comp
L +5V #PWR022
U 1 1 55F96755
P 6000 5000
F 0 "#PWR022" H 6000 4850 50  0001 C CNN
F 1 "+5V" H 6000 5140 50  0000 C CNN
F 2 "" H 6000 5000 60  0000 C CNN
F 3 "" H 6000 5000 60  0000 C CNN
	1    6000 5000
	-1   0    0    1   
$EndComp
Text HLabel 4850 2650 1    60   Input ~ 0
SPT0
Text HLabel 4950 2650 1    60   Input ~ 0
STP1
Text HLabel 5500 2650 1    60   Input ~ 0
SYNC
Text HLabel 5600 2650 1    60   Input ~ 0
OE
Text HLabel 7200 2600 1    60   Input ~ 0
SOE
Text HLabel 5150 2650 1    60   Input ~ 0
MTR
Wire Wire Line
	3300 2900 6050 2900
Wire Wire Line
	3300 3000 6050 3000
Wire Wire Line
	3300 3200 6050 3200
Wire Wire Line
	3300 3300 6050 3300
Wire Wire Line
	3300 3400 6050 3400
Wire Wire Line
	3300 3500 6050 3500
Wire Wire Line
	3300 3600 6050 3600
Wire Wire Line
	3300 3700 6050 3700
Wire Wire Line
	3300 3800 6050 3800
Wire Wire Line
	3300 3900 6050 3900
Wire Wire Line
	3300 4000 6050 4000
Wire Wire Line
	3300 4100 6050 4100
Wire Wire Line
	6050 4200 3300 4200
Wire Wire Line
	3300 4300 6050 4300
Wire Wire Line
	6050 4400 3300 4400
Wire Wire Line
	3300 4500 6050 4500
Wire Wire Line
	6050 4600 3300 4600
Wire Wire Line
	3300 4700 6050 4700
Wire Wire Line
	3300 4800 6050 4800
Wire Wire Line
	6750 2900 8500 2900
Wire Wire Line
	6750 3000 8500 3000
Wire Wire Line
	6750 3100 8500 3100
Wire Wire Line
	8500 3200 6750 3200
Wire Wire Line
	6750 3300 8500 3300
Wire Wire Line
	8500 3400 6750 3400
Wire Wire Line
	6750 3500 8500 3500
Wire Wire Line
	8500 3600 6750 3600
Wire Wire Line
	6750 3700 8500 3700
Wire Wire Line
	8500 3800 6750 3800
Wire Wire Line
	8500 3900 6750 3900
Wire Wire Line
	6750 4000 8500 4000
Wire Wire Line
	8500 4100 6750 4100
Wire Wire Line
	6750 4200 8500 4200
Wire Wire Line
	8500 4300 6750 4300
Wire Wire Line
	6750 4400 8500 4400
Wire Wire Line
	6750 4500 8500 4500
Wire Wire Line
	8500 4600 6750 4600
Wire Wire Line
	6750 4700 8500 4700
Wire Wire Line
	8500 4800 6750 4800
Connection ~ 4150 3000
Connection ~ 4050 3100
Connection ~ 3950 3200
Connection ~ 3850 3300
Connection ~ 3750 3400
Connection ~ 3650 3500
Connection ~ 3550 3600
Connection ~ 3450 3700
Wire Wire Line
	7100 2600 7100 2900
Connection ~ 7100 2900
Wire Wire Line
	6000 5000 6000 4800
Connection ~ 6000 4800
Wire Wire Line
	6000 2650 6000 2900
Connection ~ 6000 2900
Wire Wire Line
	4850 2650 4850 3900
Connection ~ 4850 3900
Wire Wire Line
	4950 2650 4950 3800
Connection ~ 4950 3800
Wire Wire Line
	5500 2650 5500 4500
Connection ~ 5500 4500
Wire Wire Line
	5600 2650 5600 4700
Connection ~ 5600 4700
Wire Wire Line
	7200 2600 7200 3000
Connection ~ 7200 3000
Wire Wire Line
	5150 2650 5150 4000
Connection ~ 5150 4000
Wire Wire Line
	3300 3100 6050 3100
Wire Wire Line
	4150 2400 4150 3000
Wire Wire Line
	4050 2400 4050 3100
Wire Wire Line
	3450 2400 3450 3700
Wire Wire Line
	3550 2400 3550 3600
Wire Wire Line
	3650 2400 3650 3500
Wire Wire Line
	3750 2400 3750 3400
Wire Wire Line
	3850 2400 3850 3300
Wire Wire Line
	3950 2400 3950 3200
Text HLabel 5250 2650 1    60   Input ~ 0
WPS
Wire Wire Line
	5250 2650 5250 4200
Connection ~ 5250 4200
Text HLabel 7350 2600 1    60   Input ~ 0
~RESET
Wire Wire Line
	7350 2600 7350 3500
Connection ~ 7350 3500
Text Label 6800 3000 0    60   ~ 0
SOE
Text Label 6800 3500 0    60   ~ 0
~RESET
$EndSCHEMATC
