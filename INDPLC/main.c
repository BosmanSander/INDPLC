/*
 * INDPLC.c
 *
 * Created: 9-3-2018 16:12:44
 * Author : Sander
 */ 

#include <avr/io.h>
#include <stdlib.h>
#include <stdio.h>
#include "mcp2515.h"


void writeChar(char x) {
	
	while(~UCSR0A & (1 << UDRE0));
	UDR0 = x;
}


void writeString(char* test){
	int count = 0;
	while(test[count]){
		writeChar(test[count++]);
	}
}

void initUsart(){
	UCSR0A = 0;
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0);
	UCSR0C |= (1 << UCSZ01) | (1 << UCSZ00 );
	UBRR0H=00;
	UBRR0L=103; //baudrade 9600 bij
	
	UCSR0B |= (1 << RXCIE0);
	
}
int main(void)
{
	initUsart();
	//mcp2515_init();

    /* Replace with your application code */
    while (1) 
    {
			writeString("Hello world\n");
    }
}

	