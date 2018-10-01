#include <stdio.h>
#include <string.h>
char *find_char(char *str, int c)
{
    for (int i = 0; i < strlen(str); i++)
    {
        if (str[i] == c)
        {
            return str + i;
        }
    }
    return NULL;
}

int main(void) 
{
    char *string = "string";
    char *found_char = find_char(string, 'g');
    printf("Found char: %c\n", *found_char);
    return 0;
}