# avr pamokos
viešoji įstaiga "Robotikos mokykla"  
2021 m.  
# 0. Nuorodos
https://circuitscheme.com/wp-content/uploads/2011/06/arduino-uno-schematic.jpg  
https://www.microchip.com/wwwproducts/en/ATMEGA328P  
https://people.ece.cornell.edu/land/courses/ece4760/AtmelStuff/AVRinstr2002.PDF  
https://en.wikipedia.org/wiki/Atmel_AVR_instruction_set  
https://en.wikipedia.org/wiki/Intel_HEX  
# 1. ASM programavimas (\*.S failams)
`avr-gcc -mmcu=atmega328p -nostartfiles blink.S`  
# 2. C programavimas (\*.c failams)
`avr-gcc -mmcu=atmega328p -Os -DF_CPU=16000000 blink.c`  
# 3. programos įkėlimas (iš 1 arba 2 žingsnių)
`avr-objcopy -O ihex a.out main.hex`  
`avrdude -p m328p -c usbasp -U flash:w:main.hex` (naudojant USBASP)  
`avrdude -p m328p -c avrisp -P /dev/ttyACM0 -b 19200 -U flash:w:main.hex` (naudojant Arduino kaip programatorių)  
# 4. papildoma informacija apie programą
`avr-objdump -S a.out`  
`avr-size a.out`  
# 5. jei kompiuteris nemato programatoriaus
windows sistemoms reikia draiverio https://www.fischl.de/usbasp/  
mac'ams https://formulae.brew.sh/formula/avrdude  
linux reikia sutvarkyti udev taisykles, sukurti failą (betkokiu pavadinimu), kataloge:  
`/etc/udev/rules.d/`  
faile įrašyti:  
`SUBSYSTEMS=="usb", ATTRS{idVendor}=="16c0", ATTRS{idProduct}=="05dc", GROUP="users", MODE="0666"`  
`GROUP` pasirenkant grupę, kurioje yra ir naudotojas  
`idVendor`, `idProduct` turi būti tokie patys, bet galima patikrinti su komanda `dmesg`, įkišus USB įrenginį  
