// Assign array elements from user input
#include <stdio.h>
int main(void)
{
    int array[3];
    int readValue = 0;
    int cellNumber = 0;
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("Enter a value:");
        scanf("%d", &readValue);
        array[cellNumber] = readValue;
        printf("Cell number %d contains %d\n", cellNumber, array[cellNumber]);
        cellNumber = cellNumber + 1;
    }
    return 0;
}

// Your grandparents gave you a fantastic cooking recipe but you can never remember how much of each ingredient you have to use! There are 10 ingredients in the recipe and the quantities needed for each of them are given as input (in grams). Your program must read 10 integers (the quantities needed for each of the ingredients, in order) and store them in an array. It should then read an integer which represents an ingredient's ID number (between 0 and 9), and output the corresponding quantity.
#include <stdio.h>
int main(void)
{
    int arr[10];
    int ing, i;
    int count = 0;
    for (i = 0; i < 10; i++)
    {
        scanf("%d", &ing);
        arr[count] = ing;
        count += 1;
    }
    scanf("%d", &i);
    printf("%d", arr[i]);
}

// Store doubles in an array
#include <stdio.h>
int main(void)
{
    double array[3];
    double readValue = 0.0;
    int cellNumber = 0;
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        printf("Enter a decimal value:");
        scanf("%lf", &readValue);
        array[cellNumber] = readValue;
        printf("Cell number %d contains %.2lf\n", cellNumber, array[cellNumber]);
        cellNumber = cellNumber + 1;
    }
    return 0;
}

// You are responsible for a rail convoy of goods consisting of several boxcars. You start the train and after a few minutes you realize that some boxcars are overloaded and weigh too heavily on the rails while others are dangerously light. So you decide to stop the train and spread the weight more evenly so that all the boxcars have exactly the same weight (without changing the total weight). For that you write a program which helps you in the distribution of the weight.

// Your program should first read the number of cars to be weighed (integer) followed by the weights of the cars (doubles). Then your program should calculate and display how much weight to add or subtract from each car such that every car has the same weight. The total weight of all of the cars should not change. These additions and subtractions of weights should be displayed with one decimal place.

// You may assume that there are no more than 50 boxcars.
#include <stdio.h>
int main(void)
{
    int i, user_input;
    int arr[50];
    double weight, avg, balance;
    double total = 0.0;
    scanf("%d", &user_input);
    for (i = 0; i < user_input; i++)
    {
        scanf("%lf", &weight);
        arr[i] = weight;
        total += weight;
    }
    avg = total / user_input;
    for (i = 0; i < user_input; i++)
    {
        balance = avg - arr[i];
        printf("%.1lf\n", balance);
    }
    return 0;
}

// Compute with arrays
// #include <stdio.h>
// int main(void)
// {
//     //! showArray(ages, cursors=[i])
//     int ages[10];
//     int i;
//     int ageMax = 0;
//     for (i = 0; i < 10; i++)
//     {
//         scanf("%d", &ages[i]);
//         if (ages[i] > ageMax)
//         {
//             ageMax = ages[i];
//         }
//     }
//     printf("The maximum age is %d.\n", ageMax);
//     printf("Age differences with the eldest person:\n");
//     for (i = 0; i < 10; i++)
//     {
//         printf("%d:%d ", ages[i], ageMax - ages[i]);
//     }
//     return 0;
// }

// You want to determine the number of cities in a given region that have a population strictly greater than 10,000. To do this, you write a program that first reads the number of cities in a region as an integer, and then the populations for each city one by one (also integers).
#include <stdio.h>
int main(void)
{
    int i, qty, population;
    int count = 0;
    scanf("%d", &qty);
    for (i = 0; i < qty; i++)
    {
        scanf("%d", &population);
        if (population > 10000)
        {
            count += 1;
        }
    }
    printf("%d", count);
    return 0;
}
