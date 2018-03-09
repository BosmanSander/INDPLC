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

int main(void)
{
	
	mcp2515_init();

    /* Replace with your application code */
    while (1) 
    {
			printf("test");
    }
}

	