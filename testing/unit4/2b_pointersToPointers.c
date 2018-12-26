// Use pointers to pointers and dereference
#include <stdio.h>
void setToZero(short **);
int main()
{
    //! showMemory(cursors=[t, t[0], t[1]],start=65520)
    short a[3] = {1245, 1924, 234};
    short b[2] = {24, 256};
    short *z[2] = {a, b};
    setToZero(z);
    return 0;
}
void setToZero(short **t)
{
    printf("%p\n", t);        // 0xffee - address of z[0]
    printf("%p\n", *t);       // 0xfffa - address of z[0][0]
    printf("%p\n", *t + 1);   // 0xfffc - address of z[0][1]
    printf("%p\n", (t + 1));  // 0xfff2 - address of z[1]
    printf("%p\n", *(t + 1)); // 0xfff6 - address of z[1][0]
    *(*t) = 0;                //t[0][0]  OR  *(t[0] + 0)
    *((*t) + 1) = 0;          //t[0][1]  OR *(t[0] + 1)
    *((*t) + 2) = 0;          //t[0][2]  OR *(t[0] + 2)
    *(*(t + 1)) = 0;          //t[1][0]  OR *(t[1] + 0)
    *(*(t + 1) + 1) = 0;      //t[1][1]  OR *(t[1] + 1)
}