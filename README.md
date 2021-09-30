# 1541-rebuild

Ersetzt den Analogteil einer Floppy 1541 durch ein Micro Controller der Disk Images per SD Karte lesen kann. Mit dieser Hardware ist es möglich ein Board wo der Analogteil defekt ist, durch diese wieder zum laufen zu bringen. Das schreiben ist nun auch schon enthalten. Es wird lediglich die 1541 Platine, diese Hardware und ein 5VDC Netzteil benötigt, oder auch das Originale Netzteil. An der 1541 II Platine muss eine Änderungen vorgenommen werden und zwar die (VIA2 (DC) sockeln.

### [Letzte Offizelle Version findet ihr hier](https://github.com/ThKattanek/1541-rebuild/releases/latest)

### Hardware / Schaltplan
Die Hardware wird mit KiCad entwickelt. Version 5.1.4 unter Ubuntu.

#### letzte Hardware-Version: 1.4.2
- komplett neues PCB layout um I2C Displays nutzen zu können
   - I2C Pins liegen nun am Display-Anschluss an
   - zusätzlicher Kondensator für Spannungsstabilisierung
- aktualisierte BOM & Dokumentation für PCB 1.4.2

### Software
Die Firmware wurde in C entwickelt - kompilierbar mit avr-gcc unter Linux.

#### letzte SW-Version: 1.3.5
- Unterstützung von 16\*2 LCD Displays
- Implementation von I2C (=TWI) Routinen für Displays
   - LCD Displays mit Port Expander PCF8574
   - OLEDs nativ (SSD1306 kompatibel)
- Autodetektion welcher Display-Type verbunden ist
   - LCD per 10pin-Anschluss, LCD per I2C, OLED per I2C

### Bilder
... vom 1.4.2 PCB:
![image5](/doc/fotos/platine_rev_1.4.2/20210911_210521_kl.jpg)

I2C OLED Display

<img src="/doc/fotos/OLED_display/OLED_in_1541-II_Front.jpg" width="300" />

LCD Display via I2C Portexpander PCF8574

<img src="/doc/fotos/platine_rev_1.4.2/20210911_204849_kl.jpg" width="300" />  <img src="/doc/fotos/handwired_rev_1.4.2/I2C_DisplayBack.jpg" width="300" />

... vom 1.4.0 PCB
![image1](/doc/fotos/1541-rebuild_raytraced.png)
![image2](/doc/fotos/platine_rev_1.4.0/IMG_20200430_231529.jpg)
![image3](/doc/fotos/platine_rev_1.4.0/IMG_20200430_232355.jpg) 

### Hier der Thread dazu im Forum64
https://www.forum64.de/index.php?thread/59884-laufwerk-der-1541-emulieren

### Einige Videos von der 1541-rebuild in aktion
https://youtu.be/EGB8lYKcW-g

https://www.youtube.com/watch?v=MlbUPTzcQGI&t=36s

https://www.youtube.com/watch?v=gKM73VpHdTw&t=256s

### Verwendete Libs
LCD Ansteuerung von Mikrokontroller.net: http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung

SD/FAT System von Roland Riegel: http://www.roland-riegel.de/sd-reader/
