#include <stdio.h>

char *find_char(char *str, int c)
{
    printf("%d", c);
    while(*str != '\0')
    {
        printf("%d", malloc(*str));
        if (malloc(*str) == str[c])
        {
            return str;
        }
        str++;
    }
    return NULL;
}

void main(void) 
{
    char string[] = "string";
    printf("This is what we found: %s", find_char(string, "g"));
}