#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char HANG_STATES[7][10 * 9] = 
{
	"             +         +----     +----     +----     +----     +----     +----     +----  ",
	"             |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
	"             |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
	"             |         |         |         |   |     |   |     |   |     |   |     |   |  ",
	"             |         |         |         |         |         |         |  /      |  / \\ ",
	"             |         |         |         |         |         |         |         |      ",
	"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "
};

void printGameState(char *correctLetters, int correct, char *incorrectLetters, int incorrect)
{
	printf("Correct guesses: ");
	for (int i = 0; i < correct; i++)
	{
		putchar(correctLetters[i]);
	}

	printf("\tStrikes: ");
	for (int i = 0; i < incorrect; i++)
	{
		putchar(incorrectLetters[i]);
	}

	for (int i = 0; i < 7; i++)
	{
		putchar('\n');
		for (int j = incorrect * 10; j < (incorrect + 1) * 10; j++)
		{
			putchar(HANG_STATES[i][j]);
		}
	}
}

void checkGuess(char *correctLetters, int correct, char *incorrectLetters, int incorrect, char *guess, char *word)
{
	int contained = 0;
	switch (strlen(guess)) 
	{
		case 0:
			printf("No guess entered - exiting");
			exit(0);
		case 1:
			for (int i = 0; i < strlen(word); i++) 
			{
				if (guess[0] == word[i]) 
				{
					printf("Letter %c found in word!\n", guess[0]);
					contained = 1;
					correctLetters[correct] = guess[0];
					correct++;
				}
			}
			if (contained == 0) 
			{
				puts("Letter not found in word");
				incorrectLetters[incorrect] = guess[0];
				incorrect++;
			}
			break;
		default:
			if (strcmp(word, guess) != 0)
			{
				puts("Incorrect full word guess");
				incorrect++;
			}
	}
}

int main(int argc, char *argv[]) {

	char *word = "word";
	char guess[20];
	char correctLetters[10];
	char incorrectLetters[8];
	int correct = 0;
	int incorrect = 0;

	while(strcmp(word, guess) != 0) 
	{
		if (incorrect == 9)
		{
			puts("Sorry, you lose\n");
			return 0;
		}

		printGameState(correctLetters, correct, incorrectLetters, incorrect);

		printf("\nEnter your guess: ");
		gets(guess);

		checkGuess(correctLetters, correct, incorrectLetters, incorrect, guess, word);
	}
	puts("You win!");
	return 0;
}