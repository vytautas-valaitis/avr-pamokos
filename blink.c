#include <avr/io.h>
#include <util/delay.h>

int main() {
  DDRB = 0b00100000;
  for(;;) {
    PINB = 0b00100000;
    _delay_ms(500);
  }
}
