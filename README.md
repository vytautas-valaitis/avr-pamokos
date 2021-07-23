# avr pamokos
viešoji įstaiga "Robotikos mokykla" kursui  
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
# 3. programos įkėlimas (iš 2 arba 3 žingsnių)
`avr-objcopy -O ihex a.out main.hex`  
`avrdude -p m328p -c usbasp -U flash:w:main.hex` (naudojant USBASP)  
`avrdude -p m328p -c avrisp -P /dev/ttyACM0 -b 19200 -U flash:w:main.hex` (naudojant Arduino kaip programatorių)  
# 4. papildoma informacija apie programą
`avr-objdump -S a.out`  
`avr-size a.out`  
