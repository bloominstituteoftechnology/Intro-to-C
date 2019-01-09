#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "time.h"

#define  MAXNUMWORDS 2048
#define MAXWORDLENGTH 64

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
  char guessWords[MAXNUMWORDS][MAXWORDLENGTH];
	int wordsReadIn = 0;

	// Read the words from the words.txt
	// Open the file and read it
	FILE *pToFile = fopen("words.txt", "r");

	if (pToFile == NULL) {
		printf("Failed To Open File\n");
		return 0;
	}

	char input[64];

	// Get the first string(word) and add to guessWords array
	// The 63 denotes adding 63 spaces to the MAXWORDLENGTH in the array of the
	// 64 char space
	while(fgets(input, 63, pToFile)) {
		sscanf(input, "%s", guessWords[wordsReadIn]);
		// printf("Scanned: input:%s guessWords[%d]:%s\n", input, wordsReadIn, guessWords[wordsReadIn]);
		wordsReadIn++;
	}

	printf("Total words read in:%d\n", wordsReadIn);

	// Close the file
	fclose(pToFile);

	// Index for random word
	int randInd = rand() % wordsReadIn;

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
	// printf("guessWords:%s randomIndex:%d lengthOfWord:%d\n", guessWords[randInd], randInd, lengthOfWord);

	// Main game loop
	while(numCorrect < lengthOfWord) {

		printf("\n\nNew Turn....\nHangman Word: ");
		for (loopInd = 0; loopInd < lengthOfWord; loopInd++) {

			// Print the characters
			if (letterGuessed[loopInd] == 1) {
				printf("%c", guessWords[randInd][loopInd]);
			} else {
				printf("-");
			}
		}

		printf("\n");

		printf("enter a guess letter:");
		fgets(guess, 16, stdin);

		if (strncmp(guess, "quit", 4) == 0) {
			quit = 1;
			break;
		}

		letterEntered = tolower(guess[0]);

		oldCorrect = numCorrect;

		for (loopInd = 0; loopInd < lengthOfWord; loopInd++) {

			// If we already guessed the letter, continue with the loop
			if (letterGuessed[loopInd] == 1) {
				continue;
			}

			// Correct letter guessed
			if (letterEntered == tolower(guessWords[randInd][loopInd])) {
				letterGuessed[loopInd] = 1;
				numCorrect++;
			}
		}

		// Handle lives
		if (oldCorrect == numCorrect) {
			numLives--;
			printf("\nSorry, wrong guess\n");
			if (numLives == 0) {
				break;
			}
		} else {
			printf("\nCorrect guess\n");
		}

	} // End of Main game loop

	if(quit == 1) {
		printf("\nThe user quit early\n");
	} else if (numLives == 0) {
		printf("\nSorry you lose, the word was: <%s>\n", guessWords[randInd]);
	} else {
		printf("\nHangman Word: ");
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
