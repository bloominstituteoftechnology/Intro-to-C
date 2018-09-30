#include <stdio.h>

char *find_char(char *str, int c)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
        {
            return str + i;
        }
    }
}

void main(void) 
{
    char string[] = "string";
    printf("This is what we found: %s", find_char(string, "g"));
}