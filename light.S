#define __SFR_OFFSET 0
#include <avr/io.h>

  ldi r16, 0b00100000
  out DDRB, r16
  out PINB, r16

loop:
  rjmp loop
