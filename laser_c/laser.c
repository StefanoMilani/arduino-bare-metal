#include <avr/io.h>
#include <util/delay.h>

#define DELAY 3000

int main(void) {
	// Set pin 2 on PORTB for output
	DDRB |= _BV(DDB2);
	// Set pin 5 on PORTB for output
	DDRB |= _BV(DDB5);
	
	while(1) {
		// Set pin 2 of PORTB to HIGH
		PORTB |= _BV(PORTB2);
		PORTB &= ~_BV(PORTB5);
		_delay_ms(DELAY);
		
		// Set pin 2 of PORTB to LOW
		PORTB &= ~_BV(PORTB2);
		PORTB |= _BV(PORTB5);
		_delay_ms(DELAY);
	}
}

/*************************
 *		DDRB 				->	00 00 00 00
 *		_BV(2) 				->	00 00 00 10
 * 		_BV(5)				->	00 01 00 00
 * 		DDRB |= _BV(2)		->	00 00 00 10
 * 		DDRB |= _BV(5)		->	00 01 00 10
 * 			
 * 		PORTB				-> 	00 00 00 00
 * 		_BV(2) 				->	00 00 00 10
 * 		_BV(5)				->	00 01 00 00
 * 		~_BV(5)				->	~(00 01 00 00)  ->	11 10 11 11
 * 		~_BV(2)				->	~(00 00 00 10)	->	11 11 11 01
 * 		PORTB |= _BV(2)		->	00 00 00 10
 *		PORTB &= ~_BV(5)	->	00 00 00 10
 *		PORTB &= ~_BV(5)
 * 
 * *****************************/
