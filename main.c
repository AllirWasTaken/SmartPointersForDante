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

   // free(tab);

    test();





    return 0;
}
