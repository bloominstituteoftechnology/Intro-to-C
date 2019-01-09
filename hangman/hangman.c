#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"

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

int main(int argc, char *argv[]) {

	// Change random's seed
	srand(time(NULL));

	// Words to guess
  char guessWords[][16] = {
		"green",
		"yellow",
		"purple",
		"windows",
		"linux",
		"apple"
	};

	// Index for random word
	int randInd = rand() % 6;

	int numLives = 8;
	int numCorrect = 0;
	int oldCorrect = 0;

	// Length of the word
	int lengthOfWord = strlen(guessWords[randInd]);
	int letterGuessed[8] = { 0, 0, 0, 0, 0, 0, 0, 0};

	int quit = 0;

	int loopInd = 0;

	char guess[16];
	char letterEntered;

	// Testing purposes
	printf("guessWords:%s randomIndex:%d lengthOfWord:%d\n", guessWords[randInd], randInd, lengthOfWord);

	// Main game loop
	while(numCorrect < lengthOfWord) {

		printf("\n\nNew Turn....\nHangman Word:");
		for (loopInd = 0; loopInd < lengthOfWord; loopInd++) {

			// Print the characters
			if (letterGuessed[loopInd] == 1) {
				printf("%c", guessWords[randInd][loopInd]);
			} else {
				printf("-");
			}
		}

		printf("\n");

		printf("Number correct so far:%d\n", numCorrect);
		printf("enter a guess letter:");
		fgets(guess, 16, stdin);

		if (strncmp(guess, "quit", 4) == 0) {
			quit = 1;
			break;
		}

		letterEntered = guess[0];

		printf("letterEntered:%c\n", letterEntered);

		oldCorrect = numCorrect;

		for (loopInd = 0; loopInd < lengthOfWord; loopInd++) {

			// If we already guessed the letter, continue with the loop
			if (letterGuessed[loopInd] == 1) {
				continue;
			}

			// Correct letter guessed
			if (letterEntered == guessWords[randInd][loopInd]) {
				letterGuessed[loopInd] = 1;
				numCorrect++;
			}
		}

		// Handle lives
		if (oldCorrect == numCorrect) {
			numLives--;
			printf("Sorry, wrong guess\n");
			if (numLives == 0) {
				break;
			}
		} else {
			printf("Correct guess\n");
		}

	} // End of Main game loop

	if(quit == 1) {
		printf("\nThe user quit early\n");
	} else if (numLives == 0) {
		printf("\nSorry you lose, the word was: <%s>\n", guessWords[randInd]);
	} else {
		printf("\nHangman Word:");
		for (loopInd = 0; loopInd < lengthOfWord; loopInd++) {

			// Print the characters
			if (letterGuessed[loopInd] == 1) {
				printf("%c", guessWords[randInd][loopInd]);
			} else {
				printf("-");
			}
		}

		printf("\nYou won!\n");
	}

  return 0;
}
