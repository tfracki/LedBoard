#include <avr/io.h>
#include <avr/interrupt.h>

#include <util/delay.h>
#include "LedBoard.h"

#define F_CPU 1000000

static int i=0;

ISR (INT0_vect)
{
  PORTC ^= GREEN;
  PORTD ^= RED; 
  i++;
  _delay_ms(200);
}

//ISR (BADISR_vect) {}

// board first configuration
void configuration() {
  DDRB = 0xFF; 
  DDRC = 0xFF; // 0011 1111
  DDRD = 0xFA; // 1111 1010

  PORTB = 0x00;
  PORTC = 0x00; //0000 0000
  PORTD = 0x07; //0000 0111

  GICR = _BV(INT0);
  MCUCR = _BV(ISC01);
  sei();
  GICR |= 0x40;
  MCUCR |= 0x02;
}

// led color switching interrupt
void checkColorSwitch () {
  if(bit_is_clear(PIND, 2) {
    PORTC ^= GREEN;
    PORTD ^= RED; 
    _delay_ms(300);
  }
}

// switching led displaying mode interrupt
void checkModeSwitch () {
  if(bit_is_clear(PIND, 0) {
    i++;
    _delay_ms(300);
  }
}

void mode1() {
  PORTB = 0x00;
  PORTC &= 0xE0; // 1110 0000
  PORTD &= 0x07; // 0000 0111
  checkModeSwitch();
  checkColorSwitch();
}

void mode2() {
  PORTB = 0xFF;
  PORTC |= 0x1F;
  PORTD |= 0xF8;	
  PORTB &= ~D;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();
	
  PORTB &= ~L1;
  PORTB &= ~P1;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~L2;
  PORTD &= ~P2;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~L3;
  PORTD &= ~P3;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~L4;
  PORTD &= ~P4;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~L5;
  PORTB &= ~P5;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~L6;
  PORTB &= ~P6;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~L7;
  PORTD &= ~P7;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~L8;
  PORTD &= ~P8;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~G;
  _delay_ms(1000);
  checkModeSwitch();
  checkColorSwitch();

  PORTC |= G;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTC |= L8;
  PORTD |= P8;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTC |= L7;
  PORTD |= P7;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTC |= L6;
  PORTB |= P6;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTC |= L5;
  PORTB |= P5;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTB |= L4;
  PORTD |= P4;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTB |= L3;
  PORTD |= P3;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTB |= L2;
  PORTD |= P2;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();

  PORTB |= L1;
   PORTB |= P1;
  _delay_ms(250);
  checkModeSwitch();
  checkColorSwitch();
  PORTB |= D;
}

void mode3() {
  PORTB = 0xFF;
  PORTC = 0x1F;
  PORTD = 0xF8;
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB |= _BV(1);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~_BV(1);
  PORTB |= _BV(2);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~_BV(2);
  PORTB |= _BV(3);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~_BV(3);
  PORTB |= _BV(4);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~_BV(4);
  PORTB |= _BV(5);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~_BV(5);
  PORTC |= _BV(0);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~_BV(0);
  PORTC |= _BV(1);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~_BV(1);
  PORTC |= _BV(2);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~_BV(2);
  PORTC |= _BV(3);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~_BV(3);
  PORTC |= _BV(4);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTC &= ~_BV(4);
  PORTB |= _BV(0);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~_BV(0);
  PORTD |= _BV(7);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTD &= ~_BV(7);
  PORTD |= _BV(6);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTD &= ~_BV(6);
  PORTD |= _BV(5);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTD &= ~_BV(5);
  PORTB |= _BV(7);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~_BV(7);
  PORTB |= _BV(6);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~_BV(6);
  PORTD |= _BV(4);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTD &= ~_BV(4);
  PORTD |= _BV(3);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTD &= ~_BV(3);
  PORTD |= _BV(4);
  _delay_ms(120);
  checkModeSwitch();
  checkColorSwitch();

  PORTB &= ~_BV(6);
  PORTD |= _BV(4);
}

int main(void)
{
  configuration();

  for(;;)
  {
    switch(i) {
    case 0:	
      mode1();
      break;

    case 1:
      mode2();
      break;

    case 2:
      mode3();
      break;	

    default : 
      i=0;
    }
  }
  return 0;
}

