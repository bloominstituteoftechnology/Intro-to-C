// 0x8 = 0
// 1x8 = 8
// ...
// 10x8 = 80

#include <stdio.h>
int main(void)
{
    int result = 0;
    int num = 0;
    int i;
    for (i = 0; i < 11; i++)
    {
        printf("%dx8 = %d\n", num, result);
        num = num + 1;
        result = num * 8;
    }
    return 0;
}

// Read integer user input using scanf()
#include <stdio.h>
int main()
{
    int age; //DECLARE
    printf("How old are you ?\n");
    scanf("%d", &age);
    printf("You are %d years old\n", age); //USE
    return 0;
}

// Read multiple integers using one scanf() statement
#include <stdio.h>
int main(void)
{
    int first, second, third;
    printf("Please enter three integers, separated by commas: ");
    scanf("%d,%d,%d", &first, &second, &third);
    printf("You entered: %d for first, %d for second, %d for third.\n", first, second, third);

    return 0;
}

// read an integer and print the corresponding multiplication table
#include <stdio.h>
int main(void)
{
    int user_num = 0;
    int num = 0;
    int result = 0;
    printf("Enter a number: ");
    scanf("%d", &user_num);
    for (int i = 0; i < 10; i++)
    {
        printf("%dx%d = %d\n", num, user_num, result);
        num = num + 1;
        result = num * user_num;
    }
    return 0;
}