#include <stdio.h>
// #include "list.h"

extern long __bss_start;
extern long __bss_end;

void clear_bss();

 
/* Still a bit confused here 
struct list_element b = {NULL,NULL, 1};
struct list_element a = {NULL,NULL, 5};
struct list_element c = {NULL,NULL, 2};
struct list_element *head = &a;
*/

void kernel_main() {

    clear_bss();
    while(1){
    }
}

void clear_bss(){
    (&__bss_start)[0] = 0x0c;
    int i=0;
    while ((&__bss_start)+i != &__bss_end){
    	(&__bss_start)[i] = 0;
    	i++;
    	}
}

