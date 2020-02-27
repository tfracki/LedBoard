// initialize lcd display
LCDInit();

// write command to lcd memory 
LCDWriteCommand(unsigned char command);

// write data to lcd memory
LCDWriteData(unsigned char data);

// print text on lcd display
LCDText(char* text, int pwm);

// set coordinates on lcd display
LCDGoTo(unsigned char, unsigned char);

// Clear lcd display
LCDClear();

// restore default coordinates
LCDHome();