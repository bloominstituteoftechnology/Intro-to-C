#include <stdio.h>

void string_copy(char x[123], char *y)
void string_copy(char *x, char *y)

{
    printf('sizeof x %lu\n', sizeofx);
    int z;
    for (z=0; y[z]; z++){
        x[z] = y[z];
    }
}

int main(void)
{
    char *hello = "Hello";
    char buffer[20];

    printf("%lu\n", sizeof buffer);

    string_copy(&buffer[0], hello);
    return 0;
}