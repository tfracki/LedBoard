include "LCDControl.h"

// function sets half byte on data line
LCDHalfByte(unsigned char byte) {
  if(byte & 0x01)
    PORTA |= _BV(5);
  else
    PORTA &= ~_BV(5);

  if(byte & 0x02)
    PORTA |= _BV(4);
  else
    PORTA &= ~_BV(4);

  if(byte & 0x04)
    PORTA |= _BV(3);
  else
    PORTA &= ~_BV(3);

  if(byte & 0x08)
    PORTA |= _BV(2);
  else
    PORTA &= ~_BV(2);
}

LCDInit() {
  int i;
  DDRA |= 0xFC; // pins 2..7 output
  _delay_ms(15);
  LCDWriteCommand(0x03); // 8-byte mode
  _delay_ms(5);
  LCDWriteCommand(0x03); 
  _delay_ms(5);
  LCDWriteCommand(0x03) 
  _delay_ms(5);
  LCDHalfByte(0x02) 
  _delay_ms(5);
  LCDWriteCommand(0x28);
  LCDWriteCommand(0x08); // display turn off
  LCDWriteCommand(0x01); // clear DDRAM memory
  _delay_ms(5);
  LCDWriteCommand(0x06); // cursor moving
  LCDWriteCommand(0x0C); // LCD on
}

LCDWriteCommand(unsigned char command) {
  PORTA &= ~_BV(7);
  PORTA |= _BV(6); // LCD_E set
  LCDHalfByte(command >> 4);

  PORTA &= ~_BV(6); // LCD_E clear
  PORTA |= _BV(6); // LCD_E set
  LCDHalfByte(command);

  PORTA &= ~_BV(6); // LCD_E clear
  _delay_us(50);
}

LCDWriteData(unsigned char data) {
  PORTA &= ~_BV(7);
  PORTA |= _BV(6); // LCD_E set
  LCDHalfByte(command >> 4);

  PORTA &= ~_BV(6); // LCD_E clear
  PORTA |= _BV(6); // LCD_E set
  LCDHalfByte(command);

  PORTA &= ~_BV(6); // LCD_E clear
  _delay_us(50);
}

LCDText(char* text, int pwm) {
  char buf[4];
  char* ptr = buf;
  char c[4];
  char* ptrc = c;

  itoa(pwm, buf, 10);

  while(*text)
    LCDWriteData(*text++);

  while(*ptr)
    LCDWriteData(*ptr++);

  while(*ptrc)
    LCDWriteData(*ptrc++);
}

LCDGoTo(unsigned char, unsigned char) {
  LCDWriteCommand(0x80 | (x + 0x40 * y));
}

LCDClear() {
  PORTA &= ~_BV(7);
  LCDWriteCommand(0x01);
  _delay_us(5);
}


LCDHome() {
  PORTA &= ~_BV(7);
  LCDWriteCommand(0x02);
  _delay_us(5);
}



