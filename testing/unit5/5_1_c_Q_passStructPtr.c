#include <stdio.h>

struct date
{
    int year;
    int month;
    int day;
};

void readDate(struct date *);
void printDate(struct date);

int main(void)
{
    struct date today;
    readDate(&today);
    printDate(today);
    return 0;
}

// Write your readDate() and printDate() functions here
void readDate(struct date *datePtr)
{
    scanf("%d", &(*datePtr).year);
    scanf("%d", &(*datePtr).month);
    scanf("%d", &(*datePtr).day);
}
// void readDate(struct date *nowptr) {
//     scanf("%d%d%d", &((*nowptr).year), &((*nowptr).month), &((*nowptr).day));
// }

void printDate(struct date now)
{
    printf("%02d/%02d/%4d\n", now.month, now.day, now.year);
}