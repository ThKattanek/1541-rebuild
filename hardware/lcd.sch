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
LIBS:1541-rebuild-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 3 4
Title "1541-rebuid"
Date "2018-05-06"
Rev "1.3.3"
Comp ""
Comment1 "Erstellt: von: Thorsten Kattanek"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L Conn_02x05_Odd_Even J6
U 1 1 5AEE2FA0
P 5050 3600
F 0 "J6" H 5100 3900 50  0000 C CNN
F 1 "LCD Display" H 5100 3300 50  0000 C CNN
F 2 "" H 5050 3600 50  0001 C CNN
F 3 "" H 5050 3600 50  0001 C CNN
	1    5050 3600
	0    1    1    0   
$EndComp
Text Notes 5950 4100 0    60   ~ 0
Steckerbelegung für das LCD Display (20x4)\n\nPIN_01: VDD(2) ... +5V\nPIN_02: VSS(1), R/W(5), LED-/K(16) ... GND\nPIN_03: D4(11)\nPIN_04: D5(12)\nPIN_05: D6(13)\nPIN_06: D7(14)\nPIN_07: E(6)\nPIN_08: RS(4)\nPIN_09: LED+/A(15)\nPIN_10: VO(3)\n
$Comp
L +5V #PWR018
U 1 1 5AEE3573
P 5250 2450
F 0 "#PWR018" H 5250 2300 50  0001 C CNN
F 1 "+5V" H 5250 2590 50  0000 C CNN
F 2 "" H 5250 2450 60  0000 C CNN
F 3 "" H 5250 2450 60  0000 C CNN
	1    5250 2450
	1    0    0    -1  
$EndComp
Text HLabel 5150 2900 1    60   Input ~ 0
D0
Text HLabel 5150 4150 3    60   Input ~ 0
D1
Text HLabel 5050 2900 1    60   Input ~ 0
D2
Text HLabel 5050 4150 3    60   Input ~ 0
D3
Text HLabel 4950 2900 1    60   Input ~ 0
EN
Text HLabel 4950 4150 3    60   Input ~ 0
RS
Wire Wire Line
	5250 2450 5250 3400
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
L R R10
U 1 1 5AEE40E3
P 4850 3100
F 0 "R10" V 4930 3100 50  0000 C CNN
F 1 "150" V 4850 3100 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4780 3100 30  0001 C CNN
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
$Comp
L GND #PWR019
U 1 1 5AEE45C6
P 5250 4750
F 0 "#PWR019" H 5250 4500 50  0001 C CNN
F 1 "GND" H 5250 4600 50  0000 C CNN
F 2 "" H 5250 4750 60  0000 C CNN
F 3 "" H 5250 4750 60  0000 C CNN
	1    5250 4750
	1    0    0    -1  
$EndComp
Wire Wire Line
	5250 3900 5250 4750
$Comp
L POT-RESCUE-1541-rebuild RV1
U 1 1 5AEE481D
P 4850 4550
F 0 "RV1" H 4850 4450 50  0000 C CNN
F 1 "10k" H 4850 4550 50  0000 C CNN
F 2 "Potentiometers:Potentiometer_Bourns_3339P_Angular_ScrewUp" H 4850 4550 60  0001 C CNN
F 3 "" H 4850 4550 60  0000 C CNN
	1    4850 4550
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 4550 5250 4550
Connection ~ 5250 4550
Wire Wire Line
	4850 3900 4850 4400
$Comp
L +5V #PWR020
U 1 1 5AEE4960
P 4350 4550
F 0 "#PWR020" H 4350 4400 50  0001 C CNN
F 1 "+5V" H 4350 4690 50  0000 C CNN
F 2 "" H 4350 4550 60  0000 C CNN
F 3 "" H 4350 4550 60  0000 C CNN
	1    4350 4550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4350 4550 4600 4550
Text Notes 650  7600 0    60   ~ 0
R10 hängt von der Hintergrundbeleuchtung des LCD Displays ab !
$EndSCHEMATC
