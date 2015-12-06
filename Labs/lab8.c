#define F_CPU 16000000UL

#include <avr/io.h>
#include <util/delay.h>

/*
 * Our 6 LED strip occupies ardruino pins 42, 44, 46, 48, 50, 52
 * and Gnd (ground)
 * Pin 42 Port L: bit 7 (PL7)
 * Pin 44 Port L: bit 5 (PL5)
 * Pin 46 Port L: bit 3 (PL3)
 * Pin 48 Port L: bit 1 (PL1)
 * Pin 50 Port B: bit 3 (PB3)
 * Pin 52 Port B: bit 1 (PB1)
*/
int main (void)
{
  /* set PORTL and PORTB for output*/
  DDRL = 0xFF;
  DDRB = 0xFF;
  
  /*
		write your code here according to the following pseudo-code:
		
		turn the frist led on;
		1 second delay;
		while(1)
		{
			turn the current led off, turn the next led on; //wrap around when appropriate
			1 second delay;
		}
  */

	PORTL = 0b10000000;
	PORTB = 0b00000000;
	_delay_ms(1000);

	int i = 0;

	while (1) {
		i = (i+1) % 6;

		PORTL = 0b00000000;
		PORTB = 0b00000000;
		_delay_ms(1000);

		switch (i) {
			case 0:
				PORTL = 0b10000000;
				PORTB = 0b00000000;
				break;
			case 1:
				PORTL = 0b00100000;
				PORTB = 0b00000000;
				break;
			case 2:
				PORTL = 0b00001000;
				PORTB = 0b00000000;
				break;
			case 3:
				PORTL = 0b00000010;
				PORTB = 0b00000000;
				break;
			case 4:
				PORTL = 0b00000000;
				PORTB = 0b00001000;
				break;
			case 5:
				PORTL = 0b00000000;
				PORTB = 0b00000010;
				break;
		}

		_delay_ms(1000);
	}
	return 1;

}
