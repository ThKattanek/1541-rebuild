EESchema Schematic File Version 4
LIBS:1541-rebuild-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 3
Title "1541-rebuid"
Date "2020-04-14"
Rev "1.4.0"
Comp ""
Comment1 "Erstellt von: Thorsten Kattanek"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Connector_Generic:Conn_01x20 P2
U 1 1 55F9DAC3
P 8950 3700
F 0 "P2" H 8950 4750 50  0000 C CNN
F 1 "VIA_PIN_21-40" V 9050 3700 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 8950 3700 60  0001 C CNN
F 3 "" H 8950 3700 60  0000 C CNN
	1    8950 3700
	1    0    0    1   
$EndComp
$Comp
L Connector_Generic:Conn_01x20 P1
U 1 1 55F9DB72
P 2900 3600
F 0 "P1" H 2900 4650 50  0000 C CNN
F 1 "VIA_PIN_1-20" V 3000 3600 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x20_P2.54mm_Vertical" H 2900 3600 60  0001 C CNN
F 3 "" H 2900 3600 60  0000 C CNN
	1    2900 3600
	-1   0    0    -1  
$EndComp
Text HLabel 3950 2200 1    60   Input ~ 0
PA0
Text HLabel 3850 2200 1    60   Input ~ 0
PA1
Text HLabel 3750 2200 1    60   Input ~ 0
PA2
Text HLabel 3650 2200 1    60   Input ~ 0
PA3
Text HLabel 3550 2200 1    60   Input ~ 0
PA4
Text HLabel 3450 2200 1    60   Input ~ 0
PA5
Text HLabel 3350 2200 1    60   Input ~ 0
PA6
Text HLabel 3250 2200 1    60   Input ~ 0
PA7
Text Label 5500 2800 0    60   ~ 0
PA0
Text Label 5500 2900 0    60   ~ 0
PA1
Text Label 5500 3000 0    60   ~ 0
PA2
Text Label 5500 3100 0    60   ~ 0
PA3
Text Label 5500 3200 0    60   ~ 0
PA4
Text Label 5500 3300 0    60   ~ 0
PA5
Text Label 5500 3400 0    60   ~ 0
PA6
Text Label 5500 3500 0    60   ~ 0
PA7
Text Label 5500 2700 0    60   ~ 0
GND
Text Label 5500 3600 0    60   ~ 0
STP1
Text Label 5500 3700 0    60   ~ 0
STP0
Text Label 5500 3800 0    60   ~ 0
MTR
Text Label 5500 3900 0    60   ~ 0
ACT
Text Label 5500 4000 0    60   ~ 0
WPS
Text Label 5500 4100 0    60   ~ 0
DS0
Text Label 5500 4200 0    60   ~ 0
DS1
Text Label 5500 4300 0    60   ~ 0
SYNC
Text Label 5500 4500 0    60   ~ 0
MODE
Text Label 5500 4400 0    60   ~ 0
NC
Text Label 5500 4600 0    60   ~ 0
VCC
Text Label 7050 2700 0    60   ~ 0
BRDY
Text HLabel 7350 2400 1    60   Input ~ 0
BRDY
$Comp
L power:+5V #PWR025
U 1 1 55F96755
P 5800 4800
F 0 "#PWR025" H 5800 4650 50  0001 C CNN
F 1 "+5V" H 5800 4940 50  0000 C CNN
F 2 "" H 5800 4800 60  0000 C CNN
F 3 "" H 5800 4800 60  0000 C CNN
	1    5800 4800
	-1   0    0    1   
$EndComp
Text HLabel 4650 2450 1    60   Input ~ 0
SPT0
Text HLabel 4750 2450 1    60   Input ~ 0
STP1
Text HLabel 5300 2450 1    60   Input ~ 0
SYNC
Text HLabel 5400 2450 1    60   Input ~ 0
OE
Text HLabel 7450 2400 1    60   Input ~ 0
SOE
Text HLabel 4950 2450 1    60   Input ~ 0
MTR
Wire Wire Line
	3100 2700 5800 2700
Wire Wire Line
	3100 2800 3950 2800
Wire Wire Line
	3100 3000 3750 3000
Wire Wire Line
	3100 3100 3650 3100
Wire Wire Line
	3100 3200 3550 3200
Wire Wire Line
	3100 3300 3450 3300
Wire Wire Line
	3100 3400 3350 3400
Wire Wire Line
	3100 3500 3250 3500
Wire Wire Line
	3100 3600 4750 3600
Wire Wire Line
	3100 3700 4650 3700
Wire Wire Line
	3100 3800 4950 3800
Wire Wire Line
	3100 3900 5850 3900
Wire Wire Line
	5850 4000 5050 4000
Wire Wire Line
	3100 4100 5850 4100
Wire Wire Line
	5850 4200 3100 4200
Wire Wire Line
	3100 4300 5300 4300
Wire Wire Line
	5850 4400 3100 4400
Wire Wire Line
	3100 4500 5400 4500
Wire Wire Line
	3100 4600 5800 4600
Wire Wire Line
	7000 2700 7350 2700
Wire Wire Line
	7000 2800 7450 2800
Wire Wire Line
	7000 2900 8750 2900
Wire Wire Line
	8750 3000 7000 3000
Wire Wire Line
	7000 3100 8750 3100
Wire Wire Line
	8750 3200 7000 3200
Wire Wire Line
	7000 3300 7600 3300
Wire Wire Line
	8750 3400 7000 3400
Wire Wire Line
	7000 3500 8750 3500
Wire Wire Line
	8750 3600 7000 3600
Wire Wire Line
	8750 3700 7000 3700
Wire Wire Line
	7000 3800 8750 3800
Wire Wire Line
	8750 3900 7000 3900
Wire Wire Line
	7000 4000 8750 4000
Wire Wire Line
	8750 4100 7000 4100
Wire Wire Line
	7000 4200 8750 4200
Wire Wire Line
	7000 4300 8750 4300
Wire Wire Line
	8750 4400 7000 4400
Wire Wire Line
	7000 4500 8750 4500
Wire Wire Line
	8750 4600 7000 4600
Connection ~ 3950 2800
Connection ~ 3850 2900
Connection ~ 3750 3000
Connection ~ 3650 3100
Connection ~ 3550 3200
Connection ~ 3450 3300
Connection ~ 3350 3400
Connection ~ 3250 3500
Wire Wire Line
	7350 2400 7350 2700
Connection ~ 7350 2700
Wire Wire Line
	5800 4800 5800 4600
Connection ~ 5800 4600
Wire Wire Line
	5800 2450 5800 2700
Connection ~ 5800 2700
Wire Wire Line
	4650 2450 4650 3700
Connection ~ 4650 3700
Wire Wire Line
	4750 2450 4750 3600
Connection ~ 4750 3600
Wire Wire Line
	5300 2450 5300 4300
Connection ~ 5300 4300
Wire Wire Line
	5400 2450 5400 4500
Connection ~ 5400 4500
Wire Wire Line
	7450 2400 7450 2800
Connection ~ 7450 2800
Wire Wire Line
	4950 2450 4950 3800
Connection ~ 4950 3800
Wire Wire Line
	3100 2900 3850 2900
Wire Wire Line
	3950 2200 3950 2800
Wire Wire Line
	3850 2200 3850 2900
Wire Wire Line
	3250 2200 3250 3500
Wire Wire Line
	3350 2200 3350 3400
Wire Wire Line
	3450 2200 3450 3300
Wire Wire Line
	3550 2200 3550 3200
Wire Wire Line
	3650 2200 3650 3100
Wire Wire Line
	3750 2200 3750 3000
Text HLabel 5050 2450 1    60   Input ~ 0
WPS
Wire Wire Line
	5050 2450 5050 4000
Connection ~ 5050 4000
Text HLabel 7600 2400 1    60   Input ~ 0
~RESET
Wire Wire Line
	7600 2400 7600 3300
Connection ~ 7600 3300
Text Label 7050 2800 0    60   ~ 0
SOE
Text Label 7050 3300 0    60   ~ 0
~RESET
$Comp
L power:GND #PWR024
U 1 1 5AF0D624
P 5800 2450
F 0 "#PWR024" H 5800 2200 50  0001 C CNN
F 1 "GND" H 5800 2300 50  0000 C CNN
F 2 "" H 5800 2450 50  0001 C CNN
F 3 "" H 5800 2450 50  0001 C CNN
	1    5800 2450
	-1   0    0    1   
$EndComp
Wire Wire Line
	3950 2800 5850 2800
Wire Wire Line
	3850 2900 5850 2900
Wire Wire Line
	3750 3000 5850 3000
Wire Wire Line
	3650 3100 5850 3100
Wire Wire Line
	3550 3200 5850 3200
Wire Wire Line
	3450 3300 5850 3300
Wire Wire Line
	3350 3400 5850 3400
Wire Wire Line
	3250 3500 5850 3500
Wire Wire Line
	7350 2700 8750 2700
Wire Wire Line
	5800 4600 5850 4600
Wire Wire Line
	5800 2700 5850 2700
Wire Wire Line
	4650 3700 5850 3700
Wire Wire Line
	4750 3600 5850 3600
Wire Wire Line
	5300 4300 5850 4300
Wire Wire Line
	5400 4500 5850 4500
Wire Wire Line
	7450 2800 8750 2800
Wire Wire Line
	4950 3800 5850 3800
Wire Wire Line
	5050 4000 3100 4000
Wire Wire Line
	7600 3300 8750 3300
$Comp
L floppy1541_tk:VIA6522 IC2
U 1 1 5E9FB04A
P 6450 3650
F 0 "IC2" H 6425 4887 60  0000 C CNN
F 1 "VIA6522" H 6425 4781 60  0000 C CNN
F 2 "Package_DIP:DIP-40_W15.24mm_Socket_LongPads" H 7850 3650 60  0001 C CNN
F 3 "${TK_DATASHEETS}/mos_6522_preliminary_nov_1977.pdf" H 7850 3650 60  0001 C CNN
	1    6450 3650
	1    0    0    -1  
$EndComp
$EndSCHEMATC
