#include <avr/io.h>
#include <util/delay.h>

int main() {
  uint8_t i;
  uint8_t data[] = "Labas Pasauli! ";
  UBRR0H = 0x00;
  UBRR0L = 0x08; // baud rate 115200
  UCSR0C = 0x06; // frame format: 8data, 1stop bit
  UCSR0B = (1 << TXEN0);

  for(;;) {
    for(i = 0; data[i] != 0; i++) {
      while (!(UCSR0A & (1 << UDRE0))); // wait for empty tx buffer
      UDR0 = data[i];
    }
    _delay_ms(500);
  }
}

