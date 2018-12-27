// Deallocate memory in the heap using free

#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    //! showMemory(start=438, cursors=[a,b,c])
    int *a, *b, *c;
    a = (int *)malloc(sizeof(int));
    *a = 1;
    printf("I stored %d at memory location %p.\n", *a, a);
    b = (int *)malloc(sizeof(int));
    *b = 2;
    free(a);
    c = (int *)malloc(sizeof(int));
    *c = 3;
    printf("Can I still access a?\n");
    printf("I stored %d at memory location %p.\n", *a, a);
    free(b);
    free(c);
    return 0;
}