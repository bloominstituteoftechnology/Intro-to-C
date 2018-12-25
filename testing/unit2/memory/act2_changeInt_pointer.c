// anyone who is at least 21 years old becomes ten years younger. However, the elixir does not work on anyone twenty years old or younger - when these people try the elixir, they actually double in age!
#include <stdio.h>

//Write your function prototype here
void elixir(int *);
int main(void)
{
    //! showMemory(start=65520)
    int age;
    int *ageAddr = &age;
    scanf("%d", ageAddr);
    printf("Your current age is %d.\n", age);

    //Write your function call here
    elixir(&age);
    printf("Your new age will be %d!\n", age);
    return 0;
}
//Write your function here
void elixir(int *a)
{
    if (*a < 21)
    {
        *a = *a * 2;
    }
    else
    {
        *a = *a - 10;
    }
}

// solution
#include <stdio.h>

void elixir(int *);

int main(void)
{
    int age;
    int *ageAddr = &age;
    scanf("%d", ageAddr);
    printf("Your current age is %d.\n", age);

    elixir(ageAddr);

    printf("Your new age will be %d!\n", age);
    return 0;
}

void elixir(int *age)
{
    if (*age > 20)
    {
        *age -= 10;
    }
    else
    {
        *age *= 2;
    }
}
