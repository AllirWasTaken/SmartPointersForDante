#include "SmartPointers.h"


#include <stdio.h>
#include <memory.h>
#include <string.h>

#undef malloc
#undef free
#undef calloc
#undef realloc
#include <stdlib.h>

struct singlePointer {
    void *pointer;
    size_t size;
    char funcName[100];
    size_t line;
};

struct pointer_manager_t {
    int echo;
    size_t maxSize;
    size_t currentSize;
    struct singlePointer tab[POINTER_LIMIT];
} pointerManager;


void __attribute__((constructor)) pointerInnit(void) {
    pointerManager.echo=1;
    pointerManager.maxSize = DEFAULT_ALLOCATION_LIMIT;
    pointerManager.currentSize = 0;
    for (int i = 0; i < POINTER_LIMIT; i++) {
        (pointerManager.tab+i)->pointer = NULL;
        (pointerManager.tab+i)->size = 0;
    }
}

void s_set_allocation_limit(size_t bytes) {
    pointerManager.maxSize=bytes;
}

void __attribute__((destructor)) pointerDestr(void) {
    if(pointerManager.echo)printf("\n##TEST_ALOKACJI##\n");
    int found = 0;
    for (int i = 0; i < POINTER_LIMIT; i++) {
        if ((pointerManager.tab+i)->pointer != NULL) {
            if (!found) {
                found = 1;
                if(pointerManager.echo)printf("ZNALEZIONE NIEZWOLNIONE BLOKI:\n");
            }
            if(pointerManager.echo)printf("ADRES: 0x%p\nROZMIAR:%llu bajt\nZAALOKOWANY PRZEZ FUNKCJE: %s()\nW LINI: %llu\n",
                   (pointerManager.tab+i)->pointer, (pointerManager.tab+i)->size,(pointerManager.tab+i)->funcName,(pointerManager.tab+i)->line);
            free((pointerManager.tab+i)->pointer);
            (pointerManager.tab+i)->pointer=NULL;
        }
    }
    if (!found)if(pointerManager.echo)printf("WSZYSTKO ZOSTALO ZWOLNIONE\n");
    if(pointerManager.echo)printf("##TEST_ALOKACJI_END##\n");
}

struct singlePointer *FindFreePointer() {
    for (int i = 0; i < POINTER_LIMIT; i++) {
        if ((pointerManager.tab+i)->pointer == NULL) {
            return pointerManager.tab+i;
        }
    }

    if(pointerManager.echo)printf("\nSmartPointers are out of pointers, consider modifying POINTER_LIMIT in SmartPointers.h\n");
    return NULL;
}

void *s_malloc(size_t size, const char* func,size_t line){
    if(size==0)return NULL;
    if (size + pointerManager.currentSize > pointerManager.maxSize) {
        return NULL;
    }
    void *temp = malloc(size);
    struct singlePointer *pointer = FindFreePointer();
    if (pointer) {
        pointer->pointer = temp;
        pointer->size = size;
        pointer->line=line;
        strcpy(pointer->funcName,func);
    }
    pointerManager.currentSize+=size;
    return temp;
}

void *s_calloc(size_t numberOfElements, size_t sizeOfElement, const char* func,size_t line) {
    if(sizeOfElement==0||numberOfElements==0)return NULL;
    void *temp = s_malloc(numberOfElements * sizeOfElement,func,line);
    if(!temp)return NULL;
    memset(temp,0,sizeOfElement*numberOfElements);
    return temp;
}

void s_free(void *adres){
    int found=0;
    for (int i = 0; i < POINTER_LIMIT; i++) {
        if ((pointerManager.tab+i)->pointer == adres) {
            free(adres);
            (pointerManager.tab+i)->pointer=NULL;
            pointerManager.currentSize-=(pointerManager.tab+i)->size;
            (pointerManager.tab+i)->size=0;
            found=1;
            break;
        }
    }
    if(!found){
        if(pointerManager.echo)printf("\nSmartPointers free SIGSEGV, nie ma pamieci o takim adresie\n");
        return;
    }
}

void *s_realloc(void* mem,size_t size, const char* func,size_t line){
    if(size==0)return NULL;

    if(mem==NULL)return s_malloc(size,func,line);

    struct singlePointer* oldMem=NULL;

    for (int i = 0; i < POINTER_LIMIT; i++) {
        if ((pointerManager.tab+i)->pointer == mem) {
            oldMem=pointerManager.tab+i;
            break;
        }
    }
    if(!oldMem){
        if(pointerManager.echo)printf("\nSmartPointers realloc SIGSEGV, nie ma pamieci o takim adresie\n");
        return NULL;
    }

    if(oldMem->size>=size){
        oldMem->size=size;
        return mem;
    }

    if(size-oldMem->size+pointerManager.currentSize>pointerManager.maxSize){
        return NULL;
    }


    void *temp=malloc(oldMem->size);
    memcpy(temp,oldMem->pointer,oldMem->size);
    s_free(mem);
    void *result= realloc(temp,size);

    {
        struct singlePointer *tempPointer=FindFreePointer();
        if(tempPointer){
            tempPointer->pointer=result;
            tempPointer->size=size;
            tempPointer->line=line;
            strcpy(tempPointer->funcName,func);
        }
    }

    return result;
}

void s_echo(int x){
    pointerManager.echo=x;
}

void s_free_all(){
    int temp=pointerManager.echo;
    s_echo(0);
    pointerDestr();
    s_echo(temp);
}