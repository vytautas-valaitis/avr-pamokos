#include <avr/io.h>

  ldi r16, 0b00100000
  sts DDRB, r16
start:
  sts PINB,r16
  ldi r26,10
loop3:
  ldi r25,255
loop2:
  ldi r24,255
loop1:
  dec r24
  brne loop1
  dec r25
  brne loop2
  dec r26
  brne loop3
  rjmp start
