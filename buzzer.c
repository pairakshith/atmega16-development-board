#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>//it has delay function
int main(void)
{
DDRB=0b00000001;
while(1)
{
PORTB=0b00000001;
_delay_ms(1000); //so that LED and buzzer would remain in ON state for 1 sec and then turns off for 1 sec.
PORTB=0b00000000;
_delay_ms(1000);
}
}