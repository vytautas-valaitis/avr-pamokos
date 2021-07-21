#include <avr/io.h>

  ldi r16, 0b00100000
  sts DDRB, r16
  sts PINB, r16

loop:
  rjmp loop
