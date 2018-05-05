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
Sheet 2 4
Title "1541-rebuid"
Date "2018-05-06"
Rev "1.3.2"
Comp ""
Comment1 "Erstellt: von: Thorsten Kattanek"
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L SD_Card CON1
U 1 1 55F7A1C8
P 5700 3450
F 0 "CON1" H 5050 4000 50  0000 C CNN
F 1 "SD_Card" H 6300 2900 50  0000 C CNN
F 2 "w_conn_misc:sd_socket" H 5900 3800 50  0001 C CNN
F 3 "" H 5700 3450 60  0000 C CNN
	1    5700 3450
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR14
U 1 1 55F7A326
P 4700 3900
F 0 "#PWR14" H 4700 3650 50  0001 C CNN
F 1 "GND" H 4700 3750 50  0000 C CNN
F 2 "" H 4700 3900 60  0000 C CNN
F 3 "" H 4700 3900 60  0000 C CNN
	1    4700 3900
	1    0    0    -1  
$EndComp
$Comp
L D D1
U 1 1 55F7A3CC
P 4450 4050
F 0 "D1" H 4450 4150 50  0000 C CNN
F 1 "1N4148" H 4450 3950 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 4450 4050 60  0001 C CNN
F 3 "" H 4450 4050 60  0000 C CNN
	1    4450 4050
	0    1    1    0   
$EndComp
$Comp
L D D2
U 1 1 55F7A4EB
P 4450 4450
F 0 "D2" H 4450 4550 50  0000 C CNN
F 1 "1N4148" H 4450 4350 50  0000 C CNN
F 2 "Diodes_ThroughHole:Diode_DO-35_SOD27_Horizontal_RM10" H 4450 4450 60  0001 C CNN
F 3 "" H 4450 4450 60  0000 C CNN
	1    4450 4450
	0    1    1    0   
$EndComp
$Comp
L +5V #PWR13
U 1 1 55F7A887
P 4450 4700
F 0 "#PWR13" H 4450 4550 50  0001 C CNN
F 1 "+5V" H 4450 4840 50  0000 C CNN
F 2 "" H 4450 4700 60  0000 C CNN
F 3 "" H 4450 4700 60  0000 C CNN
	1    4450 4700
	-1   0    0    1   
$EndComp
NoConn ~ 4800 3850
NoConn ~ 6600 3550
NoConn ~ 6600 3650
Text HLabel 3250 3750 0    60   Input ~ 0
MISO
Text HLabel 3250 3550 0    60   Input ~ 0
SCK
Text HLabel 3250 3250 0    60   Input ~ 0
MOSI
Text HLabel 3250 3150 0    60   Input ~ 0
SS
NoConn ~ 4800 3050
$Comp
L R R2
U 1 1 55F7B36C
P 3700 3150
F 0 "R2" V 3780 3150 50  0000 C CNN
F 1 "1,8k" V 3700 3150 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3630 3150 30  0001 C CNN
F 3 "" H 3700 3150 30  0000 C CNN
	1    3700 3150
	0    1    1    0   
$EndComp
$Comp
L R R5
U 1 1 55F7B401
P 3900 3250
F 0 "R5" V 3980 3250 50  0000 C CNN
F 1 "1,8k" V 3900 3250 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3830 3250 30  0001 C CNN
F 3 "" H 3900 3250 30  0000 C CNN
	1    3900 3250
	0    1    1    0   
$EndComp
$Comp
L R R3
U 1 1 55F7B48C
P 3700 3550
F 0 "R3" V 3780 3550 50  0000 C CNN
F 1 "1,8k" V 3700 3550 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3630 3550 30  0001 C CNN
F 3 "" H 3700 3550 30  0000 C CNN
	1    3700 3550
	0    1    1    0   
$EndComp
$Comp
L R R4
U 1 1 55F7BA6C
P 3900 2900
F 0 "R4" V 3980 2900 50  0000 C CNN
F 1 "3,3k" V 3900 2900 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 3830 2900 30  0001 C CNN
F 3 "" H 3900 2900 30  0000 C CNN
	1    3900 2900
	1    0    0    -1  
$EndComp
$Comp
L R R6
U 1 1 55F7BC20
P 4100 2900
F 0 "R6" V 4180 2900 50  0000 C CNN
F 1 "3,3k" V 4100 2900 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4030 2900 30  0001 C CNN
F 3 "" H 4100 2900 30  0000 C CNN
	1    4100 2900
	1    0    0    -1  
$EndComp
$Comp
L R R7
U 1 1 55F7BCCD
P 4300 2900
F 0 "R7" V 4380 2900 50  0000 C CNN
F 1 "3,3k" V 4300 2900 50  0000 C CNN
F 2 "Resistors_ThroughHole:Resistor_Horizontal_RM10mm" V 4230 2900 30  0001 C CNN
F 3 "" H 4300 2900 30  0000 C CNN
	1    4300 2900
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR12
U 1 1 55F7BE30
P 4100 2500
F 0 "#PWR12" H 4100 2250 50  0001 C CNN
F 1 "GND" H 4100 2350 50  0000 C CNN
F 2 "" H 4100 2500 60  0000 C CNN
F 3 "" H 4100 2500 60  0000 C CNN
	1    4100 2500
	-1   0    0    1   
$EndComp
Wire Wire Line
	4450 4300 4450 4200
Wire Wire Line
	4800 3450 4450 3450
Wire Wire Line
	4450 3450 4450 3900
Wire Wire Line
	4450 4600 4450 4700
Wire Wire Line
	4800 3750 3250 3750
Wire Wire Line
	3250 3150 3550 3150
Wire Wire Line
	3850 3150 4800 3150
Wire Wire Line
	4050 3250 4800 3250
Wire Wire Line
	3750 3250 3250 3250
Wire Wire Line
	3250 3550 3550 3550
Wire Wire Line
	3850 3550 4800 3550
Wire Wire Line
	3900 3050 3900 3150
Connection ~ 3900 3150
Wire Wire Line
	4100 3050 4100 3250
Connection ~ 4100 3250
Wire Wire Line
	4300 3050 4300 3550
Connection ~ 4300 3550
Wire Wire Line
	4100 2500 4100 2750
Wire Wire Line
	4300 2600 4300 2750
Wire Wire Line
	3900 2600 4300 2600
Connection ~ 4100 2600
Wire Wire Line
	3900 2750 3900 2600
Wire Wire Line
	4800 3350 4700 3350
Wire Wire Line
	4700 3350 4700 3900
Wire Wire Line
	4800 3650 4700 3650
Connection ~ 4700 3650
$Comp
L R R8
U 1 1 5ADB73A5
P 6750 2950
F 0 "R8" V 6830 2950 50  0000 C CNN
F 1 "47k" V 6750 2950 50  0000 C CNN
F 2 "" V 6680 2950 50  0001 C CNN
F 3 "" H 6750 2950 50  0001 C CNN
	1    6750 2950
	1    0    0    -1  
$EndComp
$Comp
L R R9
U 1 1 5ADB753C
P 7000 2950
F 0 "R9" V 7080 2950 50  0000 C CNN
F 1 "47kR" V 7000 2950 50  0000 C CNN
F 2 "" V 6930 2950 50  0001 C CNN
F 3 "" H 7000 2950 50  0001 C CNN
	1    7000 2950
	1    0    0    -1  
$EndComp
$Comp
L +5V #PWR15
U 1 1 5ADB75CA
P 6750 2600
F 0 "#PWR15" H 6750 2450 50  0001 C CNN
F 1 "+5V" H 6750 2740 50  0000 C CNN
F 2 "" H 6750 2600 60  0000 C CNN
F 3 "" H 6750 2600 60  0000 C CNN
	1    6750 2600
	1    0    0    -1  
$EndComp
Wire Wire Line
	6750 2600 6750 2800
Wire Wire Line
	6750 2700 7000 2700
Wire Wire Line
	7000 2700 7000 2800
Connection ~ 6750 2700
Text HLabel 7250 3250 2    60   Input ~ 0
SD_DETECT
Text HLabel 7250 3350 2    60   Input ~ 0
SD_WP
Wire Wire Line
	6600 3250 7250 3250
Wire Wire Line
	7250 3350 6600 3350
Wire Wire Line
	6750 3100 6750 3250
Connection ~ 6750 3250
Wire Wire Line
	7000 3100 7000 3350
Connection ~ 7000 3350
Text Notes 7300 3050 0    60   ~ 0
SD_DETECT ist LO wenn eine Karte eingestekt ist\nSD_WP ist LO wenn Schreibschutz aktiv\n(SD_WB muss HI sein damit man schreiben kann)
$EndSCHEMATC
