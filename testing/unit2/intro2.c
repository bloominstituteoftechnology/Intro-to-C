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