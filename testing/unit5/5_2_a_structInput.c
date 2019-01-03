#include <stdio.h>
struct point
{
    int x;
    int y;
    char o[5];
};
void printPoint(struct point pt);
void readPoint(struct point *ptr);
int main(void)
{
    //! showMemory(start=65520)
    struct point z;
    readPoint(&z);
    printPoint(z);
    return 0;
}

void readPoint(struct point *ptr)
{
    printf("\nEnter a new point: \n");
    printf("x-coordinate: ");
    scanf("%d", &ptr->x);
    printf("y-coordinate: ");
    scanf("%d", &ptr->y);
    printf("label: ");
    scanf("%s", ptr->o);
}

void printPoint(struct point pt)
{
    printf("(%d, %d, %s)\n", pt.x, pt.y, pt.o);
}