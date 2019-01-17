#include <avr/io.h>
#define F_CPU 8000000
#include <util/delay.h>

//_delay_ms(2);

const uint8_t rouge = 0x02;
const uint8_t vert = 0x01;
const uint8_t eteint = 0x10;
const uint8_t entree = 0x00;
const uint8_t sortie = 0xff;
const uint8_t pese = 0x04;
 
//bool debounce()
	//{
		//if (PIND & pese)
		//{
			//_delay_ms(10);
			//while ( PIND & pese )
			//return true;
			//return false;
		//}
		//else
			//return false;
	//}
	
int main ()
{
 
 DDRB = sortie;
 DDRD = entree;

		enum Etats { init, E1, E2};
		Etats i = init;
		
for(;;)
{
		switch (i) 
		{
			case init:
						PORTB = rouge;
						while ( debounce() )
						{	
						PORTB = vert; _delay_ms(10);
						PORTB = rouge; _delay_ms(1);
						i = E1;
						}		
						break;
				
			case E1:
					PORTB = vert;
					while ( debounce() )
						{	
						PORTB = rouge;
						i = E2;
						}		
						break;	
								
			case E2:
					PORTB = eteint;
					while ( debounce() )
						{	
						PORTB = vert;
						i = init;
						}		
						break;	
							
		}
				

}
 return 0;
}
