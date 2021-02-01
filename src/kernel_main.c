#include <stdio.h>
#include "list.h"

extern long __bss_start;
extern long __bss_end;

void clear_bss();

 


struct list_element* list = 0;

void kernel_main() {
    clear_bss();

//still troubleshooting/bug fixing not entierly functional yet
    list_add(&list, 5);
    list_add(&list, 1);
    list_add(&list, 4);
    list_add(&list, 3);

    list_remove(&list, 5);
    list_remove(&list, 3);
    list_remove(&list, 1);

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

