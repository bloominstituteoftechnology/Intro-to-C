// Repeat using a while loop
// #include <stdio.h>
// int main(void) {
//     int diceValue = 0;
//     int nbThrows = 0;
//     scanf("%d", &diceValue);
//     while(diceValue != 6){
//         scanf("%d", &diceValue);
//         nbThrows = nbThrows + 1;
//     }
//     printf("We needed %d throws to get the value 6\n", nbThrows+1);
//     return 0;
// }

// Your program will have to read a sequence of positive integers and display their sum. We do not know how many integers there will be, but the sequence always ends with the value -1 (which is not an expense, just an end marker).
#include <stdio.h>
int main(void)
{
    int n = 0;
    int total = 0;
    scanf("%d", &n);
    while (n != (-1))
    {
        total += n;
        scanf("%d", &n);
    }
    printf("%d", total);
    return 0;
}

// Check a logic statement to continue looping
#include <stdio.h>
int main(void)
{
    int signaturesNeeded = 1000;
    int day = 0;
    int newSignatures = 3;
    int totalSignatures = 3;
    while (totalSignatures < 1000)
    {
        day++;
        newSignatures = 2 * newSignatures;
        printf("Day %d: %d new signatures! ", day, newSignatures);
        totalSignatures = totalSignatures + newSignatures;
        printf("Total: %d\n", totalSignatures);
    }
    return 0;
}

// Your program should first read an integer representing the total population of the area. Knowing that a person was infected on day 1 and that each infected person contaminates two new people every day, you must calculate the day at which the entire population of the area will be infected.
#include <stdio.h>
int main(void)
{
    int pop;
    int infected = 1;
    int day = 0;
    scanf("%d", &pop);
    while (infected < pop)
    {
        day += 1;
        infected = infected * 2;
    }
    printf("%d", day);
    return 0;
}

// Your program must first read an integer indicating the number that the child will have to find during the game. Next the program should repeatedly read the player's guesses and display the text "it is more" if the child has submitted a smaller number or "it is less" if they have submitted a larger number. Once the correct number is reached, the program should print "Number of tries needed:" followed by a new line and the integer number of tries that it took the guesser.
#include <stdio.h>
int main(void)
{
    int user_i;
    int guess = 0;
    int tries = 0;
    scanf("%d", &user_i);
    while (guess != user_i)
    {
        scanf("%d", &guess);
        if (guess < user_i)
        {
            printf("it is more\n");
        }
        else if (guess > user_i)
        {
            printf("it is less\n");
        }
        tries += 1;
    }
    printf("Number of tries needed:\n%d", tries);
    return 0;
}