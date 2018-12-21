// You are planning a car trip so you post on a carpooling website in order to share the cost of the trip.

// If you have 0 passengers the carpool site does not charge anything and you alone pay the
//  full cost of the trip. If you have 1 or more passengers the carpool site adds a $1 fee
// to the cost of the trip and evenly divides the total cost ($1 fee + gas) among the passengers
//  and you. You want to write a program that calculates the cost you have to pay.
// The program should read the number of passengers (an integer) and the cost of gas for the trip
// (a decimal number). The program should then print the cost that you have to pay
// (a decimal number) with 2 digits after the decimal point.

#include <stdio.h>
int main(void)
{
    int pass;
    double cost;
    scanf("%d %lf", &pass, &cost);
    if (pass == 0)
    {
        printf("%.2lf", cost);
    }
    else if (pass > 0)
    {
        printf("%.2lf", (cost + 1) / (pass + 1));
    }
    return 0;
}

// The hostel in which you plan to spend the night tonight offers very interesting rates, as long as you do not arrive too late. Housekeeping finishes preparing rooms by noon, and the sooner guests arrive after noon, the less they have to pay. You are trying to build a C program that calculates your price to pay based on your arrival time.
// Your program will read an integer (between 0 and 12) indicating the number of hours past noon of your arrival. For example, 0 indicates a noon arrival, 1 a 1pm arrival, 12 a midnight arrival, etc. The base price is 10 dollars, and 5 dollars are added for every hour after noon. Thankfully the total is capped at 53 dollars, so you'll never have to pay more than that. Your program should print the price (an integer) you have to pay, given the input arrival time.
#include <stdio.h>
int main(void)
{
    int time;
    scanf("%d", &time);
    if ((time * 5) + 10 >= 53)
    {
        printf("%d", 53);
    }
    else
    {
        printf("%d", (time * 5) + 10);
    }
    return 0;
}
// #include <stdio.h>
// int main() {
//     int arrivalHour = 0;
//     scanf("%d", &arrivalHour);
//     int total = 10+5*arrivalHour;
//     int totalExceeds53 = total > 53;
//     if(totalExceeds53){
//         printf("53");
//     }else{
//         printf("%d", total);
//     }
//     return 0;
// }

#include <stdio.h>
int main(void)
{
    // + - * / % : arithmetic operations
    // <  >  <=  >=  !=  ==  :  comparison operations
    double a = 5.000000000001;
    double b = 5.000000000000;
    int result;
    printf("Check: Is a == b ?\n");
    result = a == b;
    printf("result is %d\n", result);
    if (result)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
    return 0;
}

// You arrive in front of a bridge that you must cross to reach a village before dark. Crossing the bridge is not free - the bridgekeeper asks you to roll two dice to determine the cost. You decide to write a program to verify that he is charging the right price.
// Your program should read two integers, between 1 and 6, representing the values of each die. If the sum is greater than or equal to 10, then you must pay a special fee (36 coins). Otherwise, you pay twice the sum of the values of the two dice. Your program must then display the text "Special tax" or "Regular tax" followed by the amount you have to pay on the next line.
#include <stdio.h>
int main(void)
{
    int first, second;
    scanf("%d %d", &first, &second);
    if (first + second >= 10)
    {
        printf("Special tax\n%d", 36);
    }
    else
    {
        printf("Regular tax\n%d", (first + second) * 2);
    }
    return 0;
}
// #include <stdio.h>
// int main(void) {
//     int totalExceedsOrEquals10;
//     int total;
//     int dice1 = 0;
//     int dice2 = 0;

//     scanf("%d %d", &dice1, &dice2);
//     total = dice1+dice2;
//     totalExceedsOrEquals10 = total >= 10;

//     if(totalExceedsOrEquals10){
//         printf("Special tax\n");
//         printf("36");
//     }else{
//         printf("Regular Tax\n");
//         printf("%d", total*2);
//     }

//     return 0;
// }

// #include <stdio.h>
// int main() {
//     int i;
//     int nbMembers = 0;
//     int totalWeightTeam1 = 0;
//     int totalWeightTeam2 = 0;
//     int weightRead = 0;
//     scanf("%d", &nbMembers);
//     for(i=0; i<nbMembers; i++){
//         scanf("%d", &weightRead);
//         totalWeightTeam1 = totalWeightTeam1 + weightRead;
//         scanf("%d", &weightRead);
//         totalWeightTeam2 = totalWeightTeam2 + weightRead;
//     }
//     int advantageTeam1 = totalWeightTeam1 > totalWeightTeam2;
//     if(advantageTeam1){
//         printf("Team 1 has an advantage\n");
//     }else{
//         printf("Team 2 has an advantage\n");
//     }
//     printf("Total weight for team 1: %d\n", totalWeightTeam1);
//     printf("Total weight for team 2: %d\n", totalWeightTeam2);
//     return 0;
// }

// or
// #include <stdio.h>
// int main(void) {
//     int sunny = 0;
//     int vacation = 0;
//     int sunORvacation = sunny || vacation;
//     //1||1:1 1||0:1 0||1:1 0||0:0
//     if(sunORvacation){
//         printf("Going well: it is sunny OR I am on vacation OR both!\n");
//     }else{
//         printf("Not going well: it is NEITHER sunny NOR am I on vacation!\n");
//     }
//     return 0;
// }

// The hostel in which you stop for the night changes its prices according to the age of the customer and the weight of their luggage. The rules are not very clear, so you decide to write a small program that will easily allow you and your travel companions to know the price of one night.

// One room costs nothing if you are 60 (the age of the innkeeper), or 5 dollars if you are less than 10 years old. For everyone else, the cost is 30 dollars plus an additional 10 dollars if you bring more than 20 pounds of luggage. Your program should read the customer's age first, then the weight of their luggage, then output the price they have to pay.

#include <stdio.h>

int main()
{
    int is60, isLessThan10, luggageMoreThan20;
    int age = 0;
    int luggageWeight = 0;

    scanf("%d %d", &age, &luggageWeight);

    is60 = age == 60;
    isLessThan10 = age < 10;
    luggageMoreThan20 = luggageWeight > 20;

    if (is60)
    {
        printf("0");
    }
    else
    {
        if (isLessThan10)
        {
            printf("5");
        }
        else
        {
            if (luggageMoreThan20)
            {
                printf("40");
            }
            else
            {
                printf("30");
            }
        }
    }
    return 0;
}
