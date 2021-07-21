# avr pamokos

sukurtos viešoji įstaiga "Robotikos mokykla" kursui

2021 m.

https://www.microchip.com/wwwproducts/en/ATMEGA328P

https://people.ece.cornell.edu/land/courses/ece4760/AtmelStuff/AVRinstr2002.PDF

https://en.wikipedia.org/wiki/Atmel_AVR_instruction_set

https://en.wikipedia.org/wiki/Intel_HEX

avr-gcc -mmcu=atmega328p -DF_CPU=8000000 -nostartfiles blink.S

avr-objcopy -O ihex a.out main.hex

avrdude -p m328p -c usbasp -U flash:w:main.hex

avr-objdump -S a.out
