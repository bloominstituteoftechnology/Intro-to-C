//displaying a pointers value

#include <stdio.h>
#include <ctype.h>

int main(void)
{

int number = 0;
int *pnumber = NULL;

number = 10;
pnumber = &number;
printf("pnumber's value: %p\n", pnumber);

return 0;

}

//pointers occupy 8 bytes and the adresses have 16 hexadecimal digits