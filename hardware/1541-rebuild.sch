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
Sheet 1 2
Title "1541-rebuild"
Date "2015-09-15"
Rev "1.0"
Comp ""
Comment1 "Erstellt: von: Thorsten Kattanek"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Sheet
S 1500 850  850  500 
U 55F7A0F9
F0 "SD Karte" 60
F1 "sd_karte.sch" 60
F2 "MISO" I R 2350 950 60 
F3 "SCK" I R 2350 1050 60 
F4 "MOSI" I R 2350 1150 60 
F5 "SS" I R 2350 1250 60 
$EndSheet
$Comp
L ATMEGA1284P-P IC1
U 1 1 55F7E447
P 6850 4000
F 0 "IC1" H 6000 5880 40  0000 L BNN
F 1 "ATMEGA1284P-P" H 7250 2050 40  0000 L BNN
F 2 "DIL40" H 6850 4000 30  0000 C CIN
F 3 "" H 6850 4000 60  0000 C CNN
	1    6850 4000
	1    0    0    -1  
$EndComp
Wire Bus Line
	2750 950  2750 1400
Wire Bus Line
	2750 1400 8200 1400
Wire Bus Line
	8200 1400 8200 4050
Entry Wire Line
	2650 950  2750 1050
Entry Wire Line
	2650 1050 2750 1150
Entry Wire Line
	2650 1150 2750 1250
Entry Wire Line
	2650 1250 2750 1350
Wire Wire Line
	2650 950  2350 950 
Wire Wire Line
	2650 1050 2350 1050
Wire Wire Line
	2650 1150 2350 1150
Wire Wire Line
	2650 1250 2350 1250
Text Label 2400 950  0    60   ~ 0
MISO
Text Label 2400 1050 0    60   ~ 0
SCK
Text Label 2400 1150 0    60   ~ 0
MOSI
Text Label 2450 1250 0    60   ~ 0
SS
Entry Wire Line
	8100 3600 8200 3700
Entry Wire Line
	8100 3700 8200 3800
Entry Wire Line
	8100 3800 8200 3900
Entry Wire Line
	8100 3900 8200 4000
Wire Wire Line
	7850 3600 8100 3600
Wire Wire Line
	7850 3700 8100 3700
Wire Wire Line
	7850 3800 8100 3800
Wire Wire Line
	7850 3900 8100 3900
Text Label 7850 3600 0    60   ~ 0
SS
Text Label 7850 3700 0    60   ~ 0
MOSI
Text Label 7850 3800 0    60   ~ 0
MISO
Text Label 7850 3900 0    60   ~ 0
SCK
Text Notes 650  7450 0    60   ~ 0
Am meinem 1541II Board sind folgende modifiktionen durchgeführt worden:\n- PIN 40 von U10 (Gate Array 251828) von Platine getrennt (BYTE READY)\n- U8 (VIA 6522) ausgelötet und gesockelt\n- Dauerläufer behoben durch trennen einer Leiterbahn (genauer beschreiben)
$Comp
L TCXO3 X1
U 1 1 55F7CB9E
P 4450 3250
F 0 "X1" H 4450 3550 70  0000 C CNN
F 1 "20Mhz" H 4450 3250 70  0000 C CNN
F 2 "" H 4450 3250 60  0000 C CNN
F 3 "" H 4450 3250 60  0000 C CNN
	1    4450 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	5150 3100 5850 3100
NoConn ~ 5150 3400
$Comp
L GND #PWR2
U 1 1 55F7D4A6
P 3550 3400
F 0 "#PWR2" H 3550 3150 50  0001 C CNN
F 1 "GND" H 3550 3250 50  0000 C CNN
F 2 "" H 3550 3400 60  0000 C CNN
F 3 "" H 3550 3400 60  0000 C CNN
	1    3550 3400
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR1
U 1 1 55F7D4E4
P 3550 3100
F 0 "#PWR1" H 3550 2950 50  0001 C CNN
F 1 "+5V" H 3550 3240 50  0000 C CNN
F 2 "" H 3550 3100 60  0000 C CNN
F 3 "" H 3550 3100 60  0000 C CNN
	1    3550 3100
	0    -1   -1   0   
$EndComp
$Comp
L C C1
U 1 1 55F7D642
P 3650 3250
F 0 "C1" H 3675 3350 50  0000 L CNN
F 1 "100n" H 3675 3150 50  0000 L CNN
F 2 "" H 3688 3100 30  0000 C CNN
F 3 "" H 3650 3250 60  0000 C CNN
	1    3650 3250
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3100 3750 3100
Connection ~ 3650 3100
Wire Wire Line
	3550 3400 3750 3400
Connection ~ 3650 3400
NoConn ~ 5850 2700
$Comp
L GND #PWR?
U 1 1 55F7EFD4
P 6750 6150
F 0 "#PWR?" H 6750 5900 50  0001 C CNN
F 1 "GND" H 6750 6000 50  0000 C CNN
F 2 "" H 6750 6150 60  0000 C CNN
F 3 "" H 6750 6150 60  0000 C CNN
	1    6750 6150
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 6000 6650 6100
Wire Wire Line
	6650 6100 6850 6100
Wire Wire Line
	6750 6100 6750 6150
Wire Wire Line
	6850 6100 6850 6000
Connection ~ 6750 6100
$Comp
L +5V #PWR?
U 1 1 55F7F7C2
P 6750 1850
F 0 "#PWR?" H 6750 1700 50  0001 C CNN
F 1 "+5V" H 6750 1990 50  0000 C CNN
F 2 "" H 6750 1850 60  0000 C CNN
F 3 "" H 6750 1850 60  0000 C CNN
	1    6750 1850
	1    0    0    -1  
$EndComp
Wire Wire Line
	6650 2000 6650 1900
Wire Wire Line
	6650 1900 6850 1900
Wire Wire Line
	6750 1900 6750 1850
Wire Wire Line
	6850 1900 6850 2000
Connection ~ 6750 1900
$EndSCHEMATC
