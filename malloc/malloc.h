#ifndef malloc_h
#define malloc_h

char *string_dup(char *src);

void *mem_copy(void *x, const void *y, int n);

void *resize_memory(void *ptr, int old_size, int new_size);

#endif