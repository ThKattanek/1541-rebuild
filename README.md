## <span style="color:red">Achtung: Ich bin aktuell dabei, das ganze hier aufzuräumen um den aktuellen Stand in ein Release zu gießen, um danach vernünftig weiterzuentwickeln zu können! </span>  
## <span style="color:red">Es kann sein das es zu ungültigen Dateien kommt, also nehmt erstmal Abstand die Daten von hier zu nehmen bis ich ein offizelles Release hier gemacht habe! </span>
## <span style="color:red">Momentan bin ich dabei die Hardware nach KiCad 5.xx zu konvertieren. Ich bin also dran ;) </span>
## <span style="color:red">Stand: 14.04.2020 </span>
# 1541-rebuild
Ersetzt den Analogteil einer Floppy 1541 II durch ein µC der Disk Images per SD Karte lesen kann. Mit dieser Hardware ist es möglich ein Board wo der Analogteil defekt ist, durch diese wieder zum laufen zu bringen. Das schreiben ist nun auch schon enthalten. Es wird lediglich die 1541II Platine, diese Hardware und ein 5VDC Netzteil benötigt. An der 1541 II Platine müssen einige Änderungen vorgenommen werden (VIA2 (DC) sockeln, 1 PIN vom Gate Arry trennen ...).
Derzeit ist es möglich aus einem Root Verzeichnis einer SD Karte, D64 sowie G64 Images auszuwählen. Diese werden dann wie eine eingelgte Diskette erkannt und der C64 kann diese lesen. Als Anzeige kommt ein 4-Zeiliges LCD (20x4) zum Einsatz.

### Hardware / Schaltplan
Die Hardware wurde mit KiCad entwickelt. Version 4.0.7 unter Ubuntu.


![Screenshot](/hardware/1541-rebuild.png)

### Einige Videos von der 1541-rebuild in aktion
https://youtu.be/EGB8lYKcW-g

https://www.youtube.com/watch?v=MlbUPTzcQGI&t=36s

https://www.youtube.com/watch?v=gKM73VpHdTw&t=256s

### Verwendete Libs
LCD Ansteuerung von Mikrokontroller.net: http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung

SD/FAT System von Roland Riegel: http://www.roland-riegel.de/sd-reader/
