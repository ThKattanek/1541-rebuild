EESchema Schematic File Version 4
LIBS:1541-rebuild-cache
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 3
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
L Connector_Generic:Conn_02x05_Odd_Even J6
U 1 1 5AEE2FA0
P 5050 3600
F 0 "J6" H 5100 3900 50  0000 C CNN
F 1 "LCD Display" H 5100 3300 50  0000 C CNN
F 2 "Connector_IDC:IDC-Header_2x05_P2.54mm_Vertical" H 5050 3600 50  0001 C CNN
F 3 "" H 5050 3600 50  0001 C CNN
	1    5050 3600
	0    1    1    0   
$EndComp
Text Notes 5950 4100 0    60   ~ 0
Steckerbelegung für das LCD Display (20x4)\n\nPIN_01: VDD(2) ... +5V\nPIN_02: VSS(1), R/W(5), LED-/K(16) ... GND\nPIN_03: D4(11)\nPIN_04: D5(12)\nPIN_05: D6(13)\nPIN_06: D7(14)\nPIN_07: E(6)\nPIN_08: RS(4)\nPIN_09: LED+/A(15)\nPIN_10: VO(3)\n
$Comp
L power:+5V #PWR0102
U 1 1 5AEE3573
P 5250 2450
F 0 "#PWR0102" H 5250 2300 50  0001 C CNN
F 1 "+5V" H 5250 2590 50  0000 C CNN
F 2 "" H 5250 2450 60  0000 C CNN
F 3 "" H 5250 2450 60  0000 C CNN
	1    5250 2450
	1    0    0    -1  
$EndComp
Text HLabel 5150 2900 1    60   Input ~ 0
D4
Text HLabel 5150 4150 3    60   Input ~ 0
D5
Text HLabel 5050 2900 1    60   Input ~ 0
D6
Text HLabel 5050 4150 3    60   Input ~ 0
D7
Text HLabel 4950 2900 1    60   Input ~ 0
EN
Text HLabel 4950 4150 3    60   Input ~ 0
RS
Wire Wire Line
	5250 2450 5250 2550
Wire Wire Line
	5150 2900 5150 3400
Wire Wire Line
	5150 3900 5150 4150
Wire Wire Line
	5050 3400 5050 2900
Wire Wire Line
	5050 3900 5050 4150
Wire Wire Line
	4950 2900 4950 3400
Wire Wire Line
	4950 3900 4950 4150
$Comp
L Device:R R10
U 1 1 5AEE40E3
P 4850 3100
F 0 "R10" V 4930 3100 50  0000 C CNN
F 1 "150" V 4850 3100 50  0000 C CNN
F 2 "Resistor_THT:R_Axial_DIN0207_L6.3mm_D2.5mm_P10.16mm_Horizontal" V 4780 3100 30  0001 C CNN
F 3 "" H 4850 3100 30  0000 C CNN
	1    4850 3100
	-1   0    0    1   
$EndComp
Wire Wire Line
	4850 2950 4850 2550
Wire Wire Line
	4850 2550 5250 2550
Connection ~ 5250 2550
Wire Wire Line
	4850 3250 4850 3400
Wire Wire Line
	5250 3900 5250 4550
$Comp
L Device:R_POT RV1
U 1 1 5AEE481D
P 4850 4550
F 0 "RV1" V 4750 4550 50  0000 C CNN
F 1 "10k" V 4850 4550 50  0000 C CNN
F 2 "Potentiometer_THT:Potentiometer_Bourns_3296W_Vertical" H 4850 4550 60  0001 C CNN
F 3 "" H 4850 4550 60  0000 C CNN
	1    4850 4550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5000 4550 5250 4550
Connection ~ 5250 4550
Wire Wire Line
	4850 3900 4850 4400
$Comp
L power:+5V #PWR0103
U 1 1 5AEE4960
P 4350 4550
F 0 "#PWR0103" H 4350 4400 50  0001 C CNN
F 1 "+5V" H 4350 4690 50  0000 C CNN
F 2 "" H 4350 4550 60  0000 C CNN
F 3 "" H 4350 4550 60  0000 C CNN
	1    4350 4550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4350 4550 4700 4550
Text Notes 650  7600 0    60   ~ 0
R10 hängt von der Hintergrundbeleuchtung des LCD Displays ab !
$Comp
L power:GND #PWR0104
U 1 1 5AF0CC1F
P 5250 4750
F 0 "#PWR0104" H 5250 4500 50  0001 C CNN
F 1 "GND" H 5250 4600 50  0000 C CNN
F 2 "" H 5250 4750 50  0001 C CNN
F 3 "" H 5250 4750 50  0001 C CNN
	1    5250 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 2550 5250 3400
Wire Wire Line
	5250 4550 5250 4750
$EndSCHEMATC
