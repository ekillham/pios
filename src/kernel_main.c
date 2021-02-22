#include <stdio.h>
#include <stdlib.h>
#include "list.h"

int global;
extern long __bss_start;
extern long __bss_end;
unsigned int *gpset1 = 0xFE200020;
unsigned int *gpclr1 = 0xFE20002C;
unsigned int *gpsel4 = 0xFE200010;

//HW1 Office Hours 2/1 w/ Jack
void clear_bss()

{
	int x = 0;
	while ((&__bss_start)+x != &__bss_end){
		(&__bss_start)[x] = 0;
		x++;
		}
}



//hw4
void led_init(){
	unsigned int mask_number = 0xFFFFFE3F;
	*gpsel4 = *gpsel4 & mask_number;
	*gpsel4 = *gpsel4 | (1 << 6);
	return;
}

void led_on(){
	*gpset1 = (1 << 10);
}

void led_off(){
	*gpclr1 = (1 << 10);
}

void delay (unsigned int d){  //Neil's Delay from class
	unsigned int i, x;

	for(i = 0; i < 0x7f; i++) {
		for (x = 0; x < d; x++){
			asm("nop");
		}
	}

}


void kernel_main(){
	//clear_bss();
    led_init();

	while(1){
		led_on();
		delay(1000);
		led_off();
		delay(1000);
	}
}



