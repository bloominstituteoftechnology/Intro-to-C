#include <stdio.h>
int main()
{
    int a = 1025;
    int *p;
    p = &a;

    printf("size of integer is %d\n", sizeof(int));
    printf("Address = %d, value = %d\n", p, *p);
    printf("Address at (p+1) = %d, value at *(p+1) = %d\n", p + 1, *(p + 1));
    // we can add or substract an integer constant from/to pointer variable
    // 'p+1' will skip four bytes and move pointer four bytes ahead
    // value is a garbage number, as we didn't assign any value to this address

    char *p0;
    p0 = (char *)p; // typecasting
    printf("size of char is %d bytes\n", sizeof(char));
    printf("Address = %d, value = %d\n", p0, *p0);
    // address is the same as 'a's, value is 1
    // 1025 = 00000000 00000000 00000100 00000001
    // typecasting is trying to store the address of 'p' in 'p0'
    // then the address of this particular byte - rightmost byte is stored in 'p0'
    // but when we dereference 'p0', and because 'p0' is a pointer to char and char is only 1 byte the machine
    //  it is going to look at only one byte
    // so this rightmost byte is 00000001 => 1, that is why this value is 1

    printf("Address at (p0+1) = %d, value at *(p0 +1) = %d\n", p0 + 1, *(p0 + 1));
    // size of char is 1 byte, so the address is +1 to the previous one, and value is 4
    // because the byte at this address is 00000100 => 4
}

// #include <stdio.h>
// int main()
// {
//     int a = 1025;
//     int *p;
//     p = &a;

//     printf("size of integer is %d\n", sizeof(int));
//     printf("Address = %d, value = %d\n", p, *p);
//     // Void pointer - Generic pointer
//     void *p0;
//     p0 = p; // (p0 points to address p)
//     // this pointer type is not mapped to a particular datatype, so we cannot dereference this pointer variable (*p0)
//     printf("address = %d", p0);
// }