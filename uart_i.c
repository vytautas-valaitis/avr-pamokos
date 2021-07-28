#include <avr/io.h>
#include <avr/interrupt.h>

volatile uint8_t data_rx;
volatile uint8_t flag_rx = 0;

ISR(USART_RX_vect) {
  data_rx = UDR0;
  flag_rx = 1;
}

int main() {
  uint8_t i;
  UBRR0H = 0x00;
  UBRR0L = 0x67; // baud rate 9600
  UCSR0C = 0x06; // frame format: 8data, 1stop bit
  UCSR0B = (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);

  sei();

  for(;;) {
    if(flag_rx) {

    while (!(UCSR0A & (1 << UDRE0))); // wait for empty tx buffer
    UDR0 = '>';

    while (!(UCSR0A & (1 << UDRE0))); // wait for empty tx buffer
    UDR0 = data_rx;

    flag_rx = 0;
    }
  }
}

