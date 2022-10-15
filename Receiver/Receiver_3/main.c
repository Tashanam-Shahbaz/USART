/*
 * Receiver_3.c
 *
 * Created: 7/26/2022 11:25:25 AM
 * Author : hp
 */ 
#include <avr/io.h>
#define F_CPU 1000000UL
#include<util/delay.h>
#include <string.h>

int main(void)
{
	   char Original_Password_Receiver[4] = {'1','2','3','4'}; //Original Password defined 
		int index=0;
		
		DDRB&=~(1<<PB2); // for bridging
		DDRB|=(1<<PB3); //  for bridging
		DDRA = 0xFF; // declaring as input
		DDRC=0xFF;
		
		//Setting Baud Rate
		UBRR1H=0x00;
		UBRR1L=0x05;
		
		//Enabling Receiver.
		UCSR1B=(1<<RXEN1);
		
		//Setting Frame Format.
		UCSR1C = (1<<URSEL1)|(3<<UCSZ10)|(1<<USBS1);
		
		
		unsigned char digit;
		
		//Making Fast DC MOTOR initially stop.
		PORTA=0b00111111;
		_delay_ms(1000);
		
    while (1) 
    {
		//getting data from Transmitter	
		
		//UCSR1A store speed of transmission of bit. For me.
		while(!(UCSR1A&(1<<RXC1)));

		digit=UDR1;
		
		if(digit=='*'){
		PORTA=0b00000101;
		_delay_ms(1000);
		
		}
		
		
		if(digit==Original_Password_Receiver[index]){
		index++;
		}
		
		if (index==4)
		{
			PORTA=0b00000110; // Fast DC Motor rotate 	
			_delay_ms(1000);
			index=0;
			
		}
		if(index!=4)
		{
			PORTA=0b00000111;  // Fast DC Motor Stop
 		}
				
    }
}

