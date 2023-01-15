#ifndef SMARTPOINTERS_SMARTPOINTERS_H
#define SMARTPOINTERS_SMARTPOINTERS_H
#include <stddef.h>
#define POINTER_LIMIT 65536
#define DEFAULT_ALLOCATION_LIMIT 1844674407370955161

#define malloc(x) s_malloc(x,__func__,__LINE__)
#define calloc(x,y) s_calloc(x,y,__func__,__LINE__)
#define free(x) s_free(x)
#define realloc(x,y) s_realloc(x,y,__func__,__LINE__)


void *s_malloc(size_t size, const char* func,size_t line);
void *s_realloc(void* mem,size_t size, const char* func,size_t line);
void *s_calloc(size_t numberOfElements,size_t sizeOfElement, const char* func,size_t line);
void s_free(void* adres);

void s_echo(int x);
void s_set_allocation_limit(size_t bytes);
void s_free_all();


#endif //SMARTPOINTERS_SMARTPOINTERS_H
