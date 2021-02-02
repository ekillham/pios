#include <stdio.h>
#include "list.h"

extern long __bss_start;
extern long __bss_end;

//Office Hours 2/1 w/ Jack
void clear_bss()

{
	int x = 0;
	while ((&__bss_start)+x != &__bss_end){
		(&__bss_start)[x] = 0;
		x++;
		}
}


struct list_element a = {NULL,NULL,7};
struct list_element* list = &a;


void kernel_main() {
     clear_bss();


    list_add(&list, 3);
    list_add(&list, 9);
    list_add(&list, 1);

    list_remove(&list, 7);
    list_remove(&list, 9);
    list_remove(&list, 3);
    list_remove(&list, 1);

    while(1){
    }
}




