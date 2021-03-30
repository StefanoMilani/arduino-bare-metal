#include <avr/io.h>


int main(void) {
	/* Set the seventh bit of DDRD to zero
	 * Set pin 7 of the Arduino Board to input mode */
	DDRD &= ~_BV(DDD7);
	// PORTD |= _BV(PORTD7);
	/* Set the fifth bit of DDRB to one
	 * Set pin 13 of the Arduino Board to output mode */
	DDRB |= _BV(DDB5);
	
	
	while(1) {
		/* Read value of the seventh bit of PIND
		 * Read value on pin 7 of Arduino Uno */
		 
		if(bit_is_clear(PIND, PIND7)) {	/* 	Check if value is LOW 	*/
			/* The value of pin 7 is LOW 
			 * turn off the led */
			PORTB &= ~_BV(PORTB5);
		}
		if(bit_is_set(PIND, PIND7)) {		/* 	Check if value is HIGH 	*/
			/* The value is HIGH
			 * Turn on the led */
			PORTB |= _BV(PORTB5);
		}
	}
	
}

/*
 * #define bit_is_clear(sfr, bit) (!(_SFR_BYTE(sfr) & _BV(bit)))
 * _SFR_BYTE(sfr) returns a byte of date at the specified address
 * #define _SFR_BYTE(sfr) _MMIO_BYTE(_SFR_ADDR(sfr))
 * _SFR_ADDR is a macro the returns the address,
 * _MMIO_BYTE is a macro the return the byte of data
 */ 
