#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Used this Tutorial Series: "Hangman for Beginners" --> https://www.youtube.com/watch?v=sitn00wQMrg

char HANG_STATES[7][10 * 9] =
	{
		"             +         +----     +----     +----     +----     +----     +----     +----  ",
		"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
		"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
		"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
		"             |         |         |         |         |         |         |  /      |  / \\ ",
		"             |         |         |         |         |         |         |         |      ",
		"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

// int argc, char *argv[]
int main()
{
	srand(time(NULL)); // New calc of random numbers each time

	char guessWords[][16] = {
		"green",
		"yellow",
		"purple",
		"windows",
		"linux",
		"apple"};

	// Used to calculate a random index to select one of the above words for the game.
	int randomIndex = rand() % 6; // returns 0 to 5

	int numLives = 5;
	int numCorrect = 0;
	int oldCorrect = 0;

	int lengthOfWord = strlen(guessWords[randomIndex]);

	// For each letter input guessed, that letter will be looped and compared.
	//						0  1  2  3  4  5
	// 						p  u  r  p  l  e
	//  letterGuessed[8] = {0, 0, 1, 0, 1, 0, 0, 0};
	int letterGuessed[8] = {0, 0, 0, 0, 0, 0, 0, 0};

	int quit = 0;

	int loopIndex = 0;

	char guess[16]; // The guess the user makes.
	char letterEntered;

	printf("guessWords: %s randomIndex: %d lengthOfWord: %d\n", guessWords[randomIndex], randomIndex, lengthOfWord);

	// game loop
	while (numCorrect < lengthOfWord)
	{
		printf("\n\nYour Turn:\nHangman Word:  ");

		// loops through entire guessWords word
		for (loopIndex = 0; loopIndex < lengthOfWord; loopIndex++)
		{
			// if value at loopIndex is already 1, then just keep going
			if (letterGuessed[loopIndex] == 1)
			{
				printf("%c", guessWords[randomIndex][loopIndex]);
			}
			else
			{
				printf("-");
			}
		}

		printf("\n");

		printf("Number Correct so far:%d\n", numCorrect);
		printf("\nEnter a guess letter:");
		fgets(guess, 16, stdin); // up to 16 characters
		if (strncmp(guess, "quit", 4) == 0)
		{
			quit = 1;
			break;
		};

		letterEntered = guess[0];

		printf("letterEntered: %c\n", letterEntered);

		oldCorrect = numCorrect;

		for (loopIndex = 0; loopIndex < lengthOfWord; loopIndex++)
		{
			// if value at loopIndex is already 1, then just keep going
			if (letterGuessed[loopIndex] == 1)
			{
				continue;
			}

			if (letterEntered == guessWords[randomIndex][loopIndex])
			{
				letterGuessed[loopIndex] = 1;

				numCorrect++;
			}
		}

		if (oldCorrect == numCorrect)
		{
			numLives--;
			// printf("Sorry, wrong guess!\n %s", HANG_STATES[oldCorrect]);
			printf("\nSorry, wrong guess!\n");

			// #QUESTION: HOW TO PRINT HANG_STATES IMG PROPERLY???
			// for (int i = 0; i < oldCorrect; i++)
			// {
			// printf("oldCorrect: %d, %s", oldCorrect, HANG_STATES[oldCorrect]);
			// }
			if (numLives == 0)
			{
				break;
			}
		}
		else
		{
			printf("\nCorrect! :)\n");
		}
	}

	if (quit == 1)
	{
		printf("\nUSER Quit Early\n");
	}
	else if (numLives == 0)
	{
		printf("\nSORRY! YOU LOSE! :(\nTHE CORRECT WORD WAS: %s\n", guessWords[randomIndex]);
	}
	else
	{
		printf("\nCONGRATULATIONS! YOU WIN!\nExiting Hangman...\n\n");
	}

	return 0;
}