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
$EndSCHEMATC
