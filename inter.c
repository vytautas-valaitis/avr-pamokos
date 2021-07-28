#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

volatile uint8_t flag_led = 0;

ISR(INT0_vect) {
  flag_led = 1;
}

int main() {
  DDRB |= (1 << PB5); // led

  DDRD &= ~(1 << PD2); // int0
  PORTD |= (1 << PD2);

  EIMSK |= (1 << INT0);
  EICRA = 0x00;
  
  sei();

  for(;;) {
    if(flag_led) {
      PINB |= (1 << PB5); // led
      _delay_ms(20);
      flag_led = 0;
    }
  }
}

