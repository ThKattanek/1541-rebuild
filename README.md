### Achtung: Ich bin gerade dabei hier alles zu überarbeiten und zu erneuern. Gerade habe ich die Platine neu layoutet damit sie in allen 1541 Versionen passen sollte. Bitte warten für einen Nachbau auf ein fertiges offizelles Release hier. Ich werde in den nächsten Tagen Platinen fertigen lassen und sie dann selber testen und auch testen lassen.
### Stand: 18.04.2020

# 1541-rebuild
Ersetzt den Analogteil einer Floppy 1541 durch ein Micro Controller der Disk Images per SD Karte lesen kann. Mit dieser Hardware ist es möglich ein Board wo der Analogteil defekt ist, durch diese wieder zum laufen zu bringen. Das schreiben ist nun auch schon enthalten. Es wird lediglich die 1541 Platine, diese Hardware und ein 5VDC Netzteil benötigt, oder auch das Originale Netzteil. An der 1541 II Platine müssen einige Änderungen vorgenommen werden (VIA2 (DC) sockeln, >>> 1 PIN vom Gate Arry trennen ...<<< Wird nochmal geprüft) Derzeit ist es möglich aus einem Root Verzeichnis einer SD Karte, D64 sowie G64 Images auszuwählen. Diese werden dann wie eine eingelgte Diskette erkannt und der C64 kann diese lesen. Als Anzeige kommt ein 4-Zeiliges LCD (20x4) zum Einsatz.

### Hardware / Schaltplan
Die Hardware wird mit KiCad entwickelt. Version 5.1.4 unter Ubuntu.


![Screenshot](/doc/fotos/1541-rebuild_raytraced.png)

### Einige Videos von der 1541-rebuild in aktion
https://youtu.be/EGB8lYKcW-g

https://www.youtube.com/watch?v=MlbUPTzcQGI&t=36s

https://www.youtube.com/watch?v=gKM73VpHdTw&t=256s

### Verwendete Libs
LCD Ansteuerung von Mikrokontroller.net: http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung

SD/FAT System von Roland Riegel: http://www.roland-riegel.de/sd-reader/
