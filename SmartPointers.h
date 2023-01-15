#ifndef SMARTPOINTERS_SMARTPOINTERS_H
#define SMARTPOINTERS_SMARTPOINTERS_H

#include <stddef.h>

#define POINTER_LIMIT 65536
#define DEFAULT_ALLOCATION_LIMIT 1844674407370955161

#define malloc(size) s_malloc(size,__func__,__LINE__)
#define calloc(numberOfElements, sizeOfElement) s_calloc(numberOfElements,sizeOfElement,__func__,__LINE__)
#define free(adres) s_free(adres,__func__,__LINE__)
#define realloc(memory, newSize) s_realloc(memory,newSize,__func__,__LINE__)


void *s_malloc(size_t size, const char *func, size_t line);
void *s_realloc(void *mem, size_t size, const char *func, size_t line);
void *s_calloc(size_t numberOfElements, size_t sizeOfElement, const char *func, size_t line);
void s_free(void *adres,const char *func, size_t line);


void s_echo(int x);
void s_set_allocation_limit(size_t bytes);
void s_free_all();
void s_show_blocks();
void s_status_of_allocation();


#endif //SMARTPOINTERS_SMARTPOINTERS_H
