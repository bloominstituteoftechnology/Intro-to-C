#include <stdio.h>

int main(void)
{
    char *str = "Hello World";
    while(*str != '\0')
    {
        printf("%c", *str);
        *str++;
    }
}

