//displaying a pointers value

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

int main(void)
{

int number = 0;
int *pnumber = NULL;

number = 10;

printf("pnumber's address: %p\n", &number);
printf("pnumber's value: %d\n\n", number);

pnumber = &number;

printf("pnumber's address: %p\n", (void*) &pnumber);
printf("pnumber's size: %ld bytes\n", sizeof(pnumber));
printf("pnumber's value: %p\n", pnumber);
printf("value pointed to: %d\n", *pnumber);

return 0;

}

//pointers occupy 8 bytes and the adresses have 16 hexadecimal digits
//a memory address on my mashine is 64 bits

//this exersize prints:
//pnumber's address: 0x7fffd6728fbc
//pnumber's value: 10

//pnumber's address: 0x7fffd6728fc0
//pnumber's size: 8 bytes
//pnumber's value: 0x7fffd6728fbc
//value pointed to: 10