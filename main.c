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

    int**tob;
    tob=malloc(sizeof(int*)*5);
    for(int i=0;i<5;i++){
        tob[i]=malloc(sizeof(int)*5);
    }

    for(int y=0;y<5;y++){
        for(int x=0;x<5;x++){
            tob[y][x]=x*y;
        }
    }

    for(int y=0;y<5;y++){
        for(int x=0;x<5;x++){
            printf("%d ",tob[y][x]);
        }
    }

    malloc(sizeof(int)*60);

    free(0x564);
    free(NULL);
    realloc(0x325235,100);


    return 0;
}
