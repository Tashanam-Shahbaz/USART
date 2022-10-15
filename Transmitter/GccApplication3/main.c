/*
 * lab08.c
 *
 * Created: 07/09/2021 09:46:27
 * Author : hp
 */ 

#include <avr/io.h>
#define F_CPU 1000000UL
#include<util/delay.h>
#include <string.h>


// Initializing the function for getting keys which are Pressed on keypad
int GetKeyPressed(void);

// Main function
int main(void)
{
	//use for accessing character of password.
	int index = 0;
	
	//Original Password defined at transmitter end.
	char Original_Password_Transmitter[4] = {'1','2','3','4'};  
	
	// Initializing Keys of Keypad
	char digit[20]=
		{
		'7','8','9','/',
		'4','5','6','*',
		'1','2','3','-',
		'A','0','=','+','\0'
		}; 
		
	//LSBs are input of Port D		
	DDRD=0xF0;	//For Keypad
	DDRA=0xFF;  //For Showing Output at 7-Segment.
	DDRC=0x00;  //data available declaring pc0 as input
	DDRB=0x02;	// output enable
	
	//Setting Baud Rate
	UBRR1L=0x05;
	UBRR1H=0x00;
	
	//Enable Transmitter
	UCSR1B|=(1<<TXEN1);
	
	//Set Frame Format
	UCSR1C = (1<<URSEL1)|(3<<UCSZ10);
	
	//use for accessing character of keypad.
	int Key;
	
	//Initializing for push button. Use for reseting 7-segment.
	char push_button; 
	
	// 7-segment will show C which means Close	
	PORTA=0b11000110;  
	_delay_ms(1000);
	
	while(1)
	{	
		//push button placed on PB0
		push_button = PINB&00000001; 
		
		// Calling GetKeyPressed function
		Key = GetKeyPressed(); 
		
		//When we get input from keypad.
		if (Key!=16){
			
			if(digit[Key]==Original_Password_Transmitter[index]){
				
				index++; // incrementing index
			}
			//Sending input keypad's character to Receiver. 
			UDR1=digit[Key];
		}
		
	    if (push_button==1){
			index=0;
			//If Push button is Pressed the DC motor rotate in opposite direction for again Locking the Door.
			UDR1='*';
			
			// If Push button is Pressed then 7-segment will change from Open(O) to Close(C)
			PORTA=0b11000110;  
			_delay_ms(1000);
		}
			
 		if (index==4)
		 {
			PORTA=0b11000000; //7-segment will show O which means Open
		}
	
		if(index!=4)
		{
			PORTA=0b11000110;  // 7-segment will show C which means Close
		}	
	}
	
}
	
// GetKeyPressed Function
int GetKeyPressed(void){
	char x;
	PORTB=0x00; //active low enable
	int data;
	x=PINC;
	if(x==0x01)
	{
		data=(PIND&0x0F);
		return data;
	}
	return 16; //Nothing is Pressed.
	}