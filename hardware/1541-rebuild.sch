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
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ATMEGA1284P-P IC?
U 1 1 55F6F7E1
P 3150 3850
F 0 "IC?" H 2300 5730 40  0000 L BNN
F 1 "ATMEGA1284P-P" H 3550 1900 40  0000 L BNN
F 2 "DIL40" H 3150 3850 30  0000 C CIN
F 3 "" H 3150 3850 60  0000 C CNN
	1    3150 3850
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR?
U 1 1 55F6F9CF
P 3050 5950
F 0 "#PWR?" H 3050 5700 50  0001 C CNN
F 1 "GND" H 3050 5800 50  0000 C CNN
F 2 "" H 3050 5950 60  0000 C CNN
F 3 "" H 3050 5950 60  0000 C CNN
	1    3050 5950
	1    0    0    -1  
$EndComp
Wire Wire Line
	2950 5850 2950 5950
Wire Wire Line
	2950 5950 3050 5950
Wire Wire Line
	3050 5950 3150 5950
Wire Wire Line
	3150 5950 3150 5850
Connection ~ 3050 5950
$EndSCHEMATC
