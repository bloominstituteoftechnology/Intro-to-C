#include <stdio.h>
#include <ctype.h>

int main(void)
{
char *str ="Hello world!";
printf("%c\n", *str);
printf("%c\n", *(str+1));
printf("%c\n", *str);
return 0;
}