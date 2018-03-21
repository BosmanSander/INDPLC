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
#include "Canbus.h"
#include "global.h"
#include "defaults.h"



void writeChar(char x) {
	
	while(~UCSR0A & (1 << UDRE0));
	UDR0 = x;
}


void writeString(char* test){
	int count = 0;
	while(test[count]){
		writeChar(test[count++]);
	}
	writeChar('\n');
	writeChar('\r');
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
	
	bool connected = false;
	
	if(Canbus.init(CANSPEED_250)){  //Initialise MCP2515 CAN controller at the specified speed
		writeString("CAN Init ok");
		connected = true;
	}else{
		writeString("Can't init CAN");
	}
	
	//mcp2515_init(3);
	uint8_t test = 0;
    /* Replace with your application code */
    while (1) 
    {
			
			if(connected){
				writeString("connected\n\r");
			}else{
				writeString("not connected\r\n");
			}
			
			/*
			if(mcp2515_check_message()){
				writeString("Got amessage!!!\r\n");
			}else{
				writeString("got no message\r\n");
			}
			*/
			
			//test =  mcp2515_read_status(uint8_t type);

			//writeString("Hello world\n");
    }
}

	