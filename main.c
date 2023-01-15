#include <stdio.h>
#include "SmartPointers.h"


void test(){
    calloc(30,10);
}


int main() {

    //showcase

    malloc(50);
    int *tab= realloc(NULL,30);

    free(tab);

    test();


    s_free_all();


    return 0;
}
