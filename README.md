### Achtung: Ich bin gerade dabei hier alles zu überarbeiten und zu erneuern. Die neuen Platinen (Rev.: 1.4.0) sind angekommen und ich habe diese auch schon aufgebaut und getestet. Soweit laufen die neuen Platinen gut. Ich muss noch prüfen wie sie auf den 1541 Boards passen. Bin jetzt dabei die Dokumentation auf den neusten Stand zu bringen, und dann geht es weiter mit der Firmware. Bitte wartet mit einem Nachbau bis ein offizelles Release hier online geht !!!
### Stand: 01.05.2020

# 1541-rebuild
Ersetzt den Analogteil einer Floppy 1541 durch ein Micro Controller der Disk Images per SD Karte lesen kann. Mit dieser Hardware ist es möglich ein Board wo der Analogteil defekt ist, durch diese wieder zum laufen zu bringen. Das schreiben ist nun auch schon enthalten. Es wird lediglich die 1541 Platine, diese Hardware und ein 5VDC Netzteil benötigt, oder auch das Originale Netzteil. An der 1541 II Platine müssen einige Änderungen vorgenommen werden (VIA2 (DC) sockeln, >>> 1 PIN vom Gate Arry trennen ...<<< Wird nochmal geprüft) Derzeit ist es möglich aus einem Root Verzeichnis einer SD Karte, D64 sowie G64 Images auszuwählen. Diese werden dann wie eine eingelgte Diskette erkannt und der C64 kann diese lesen. Als Anzeige kommt ein 4-Zeiliges LCD (20x4) zum Einsatz.

### Hardware / Schaltplan
Die Hardware wird mit KiCad entwickelt. Version 5.1.4 unter Ubuntu.


![Screenshot](/doc/fotos/1541-rebuild_raytraced.png)
![image1](/doc/fotos/platine_rev_1.4.0/IMG_20200430_231529.jpg) 

### Einige Videos von der 1541-rebuild in aktion
https://youtu.be/EGB8lYKcW-g

https://www.youtube.com/watch?v=MlbUPTzcQGI&t=36s

https://www.youtube.com/watch?v=gKM73VpHdTw&t=256s

### Verwendete Libs
LCD Ansteuerung von Mikrokontroller.net: http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung

SD/FAT System von Roland Riegel: http://www.roland-riegel.de/sd-reader/
