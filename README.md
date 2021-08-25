#FORK of 1541-rebuild

done:
- rerouting the PCB to be able to use I2C Displays instead of bitbanging to LCD. opens the world to OLED and even onscreen displays.
- changing of firmware needed (pin assignments)

open:
- implementation of i2c routines for displays

new I2C-Version (1.4.1) of the PCB created:
- all Pin assigns are identical to 1.4.0 (!) -> LCD Displays can still be used!
- I2C Pins share 4 pins with LCD-Display Header -> only Software reconfiguration needed
- adopted Software needed (due to different Atmega-Ports used)

layout prepared in KiCad:

![image4](/doc/fotos/1541-rebuild-141_front.png)
![image5](/doc/fotos/1541-rebuild-141_back.png)

# original Readme.md:

Ersetzt den Analogteil einer Floppy 1541 durch ein Micro Controller der Disk Images per SD Karte lesen kann. Mit dieser Hardware ist es möglich ein Board wo der Analogteil defekt ist, durch diese wieder zum laufen zu bringen. Das schreiben ist nun auch schon enthalten. Es wird lediglich die 1541 Platine, diese Hardware und ein 5VDC Netzteil benötigt, oder auch das Originale Netzteil. An der 1541 II Platine muss eine Änderungen vorgenommen werden und zwar die (VIA2 (DC) sockeln.

### [Letzte Offizelle Version findet ihr hier](https://github.com/ThKattanek/1541-rebuild/releases/latest)

### Hardware / Schaltplan
Die Hardware wird mit KiCad entwickelt. Version 5.1.4 unter Ubuntu.


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
