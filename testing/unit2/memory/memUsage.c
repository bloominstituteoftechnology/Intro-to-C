// Your program should read a character that identifies the data type ('i' for int, 's' for short, 'c' for char, 'd' for double). Next it should read an integer that indicates how many variables of the given type you wish to store.
// Your program should then calculate the amount of memory required to store the given variables.
#include <stdio.h>
int main(void)
{
    int num;
    int result = 0;
    char type;
    scanf("%c %d", &type, &num);
    if (type == 'i')
    {
        result = num * sizeof(int);
    }
    else if (type == 'c')
    {
        result = num * sizeof(char);
    }
    else if (type == 'd')
    {
        result = num * sizeof(double);
    }
    else if (type == 's')
    {
        result = num * sizeof(short);
    }

    int mega = result / 1000000;
    int kilo = (result - mega * 1000000) / 1000;
    int byte = result - mega * 1000000 - kilo * 1000;

    if (mega > 0)
    {
        printf("%d MB and %d KB and %d B\n", mega, kilo, byte);
    }
    else if (kilo > 0)
    {
        printf("%d KB and %d B\n", kilo, byte);
    }
    else
    {
        printf("%d B\n", byte);
    }
    return 0;
}

// solution
// #include <stdio.h>

// int main(void){
//     char c;
//     int num;
//     int spacePer;
//     int memory;
//     int mega, kilo, byte;

//     scanf("%c", &c);
//     scanf("%d", &num);

//     if (c=='c') spacePer = sizeof(char);
//     else if (c=='s') spacePer = sizeof(short);
//     else if (c=='i') spacePer = sizeof(int);
//     else spacePer = sizeof(double);

//     memory = spacePer*num;
//     mega = memory/1000000;
//     kilo = (memory-mega*1000000)/1000;
//     byte = memory-mega*1000000-kilo*1000;

//     if (mega>0){
//         printf("%d MB and %d KB and %d B", mega, kilo, byte);
//     } else if (kilo>0){
//         printf("%d KB and %d B", kilo, byte);
//     } else{
//         printf("%d B", byte);
//     }

//     return 0;
// }