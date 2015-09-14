#!/bin/bash
doxygen Doxyfile
cd ./doxygen/latex
make pdf
cd ../../
cp ./doxygen/latex/refman.pdf ./raspisynth-firmware-dokumentaion.pdf
#okular ./raspisynth-dokumentaion.pdf