#define TRIGPOINT 128

#include <avr/io.h>
#include <util/delay.h>

int main(void)
{
	// Configure PORT B bit 5 to output
	DDRB |= _BV(DDB5);

	// Configure PORT C bit 0 to an input
	
	DDRC &= ~_BV(DDC0);

	// Configure ADC to be left justified, use AVCC as reference, and select ADC0 as ADC input
	ADMUX = 0b01100000;

	// Enable the ADC and set the prescaler to max value (128)
	ADCSRA = 0b10000111;



	// Main program loop
    while (1) 
    {
		// Start an ADC conversion by setting ADSC bit (bit 6)
		ADCSRA = ADCSRA | (1 << ADSC);
		
		// Wait until the ADSC bit has been cleared
		while(ADCSRA & (1 << ADSC));

		if(ADCH > TRIGPOINT)
		{
			// Turn LED on
			PORTB |= _BV(PORTB5);
		}
		else
		{
			// Turn LED off
			PORTB &= ~_BV(PORTB5);
		}
	}
}
