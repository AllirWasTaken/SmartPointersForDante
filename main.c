#include <stdio.h>
#include "SmartPointers.h"


void test(){
    calloc(30,10);
}


int main() {

    //showcase

    s_set_allocation_limit(500);

    malloc(50);
    int *tab= realloc(NULL,30);

    free(tab);

    test();

    s_status_of_allocation();

    s_show_blocks();

    s_free_all();

    s_show_blocks();



    malloc(sizeof(int)*60);

    free(0x564);
    free(NULL);
    realloc(0x325235,100);


    return 0;
}
