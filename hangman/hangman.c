#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char HANG_STAGES[7][10 * 9] = 
{
	"         +        +----    +----    +----    +----    +----    +----    +----  ",
	"         |        |        |   O    |   O    |   O    |   O    |   O    |   O  ",
	"         |        |        |        |   +    | --+    | --+--  | --+--  | --+--",
	"         |        |        |        |   |    |   |    |   |    |   |    |   |  ",
	"         |        |        |        |        |        |        |  /     |  / \\ ",
	"         |        |        |        |        |        |        |        |       ",
	"/*****\\  /*****\\  /*****\\  /*****\\  /*****\\  /*****\\  /*****\\  /*****\\  /*****\\"
};

// Display Hang States
void display_stage(int stage) {
	int start = 9 * stage;
	int end = start + 9;
	printf("\n");
	for(int i = 0; i < 7; i++) {
		for (int j = start; j < end; j++) {
			printf("%c", HANG_STAGES[i][j]);
		}
		printf("\n");
	}
}


int main(int argc, char *argv[]) {
  /* Your code here */
	if (argv[1] != NULL) {
	char *word = argv[1];
	char guess[40];
	char guesses[27]; // Guesses only needs space for each character in the alphabet.
	guesses[0] = '\0';

	int position = 0;
	int stage = 0;
	int match = 0;
	int guess_length = 0;
	int word_length = 0;
	int guesses_count = 0;
	int correct_guesses = 0;

	// Convert Word to Lowercase and Store its Length
	for (int i = 0 ; word[i]; i++) { 
		word[i] = tolower(word[i]);
		word_length++;
	}

	// Set Blanks
	char blanks[word_length];
	for (int i = 0; i < word_length; i++) {
			blanks[i] = '_';
			blanks[i + 1] = '\0';
	}
	
	// Main Loop
	while (1) {

		// ** Display **

		// Display Hanging Stage
		display_stage(stage);

		// Display Blanks
		printf("\nWord: ");
		for (int i = 0; i < word_length; i++) {
			printf("%c ", blanks[i]);
		}

		printf("\n");

		// Display Guessed Letters
		printf("\nGuesses: ");
		for (int i = 0; i < guesses_count; i++) {
			printf("%c ", guesses[i]);
		}

		printf("\n\n");

		// ** End Game **

		// Loss Handling
		if (stage == 8) {
			printf("\n----\nHANGED!\n----\n");
			break;
		}

		// Win Handling
		if (correct_guesses == word_length) {
			printf("\n----\nCORRECT! YOU LIVE ANOTHER DAY!\n----\n");
			break;
		}
		
		// ** Guessing **

		// User Input
		printf("Enter your guess. You may guess one character, or the whole word (enter _q to quit):\n");
		scanf("%s", guess);

		// Convert to Lowercase and Keep track of length
		for (int i = 0; guess[i]; i++) {
			guess[i] = tolower(guess[i]); 
			guess_length++;
		}

		// Quit Command Handling
		if (guess[0] == '_' & guess[1] == 'q') {
			printf("\nQuit command received.\n");
			break;
		}

		// If guess is multiple characters
		if (guess_length > 1) {
			for (int i = 0; word[i]; i++) {

				if (word[i] != guess[i]) {
					stage++;
					break;
				}
				
				if (i == word_length - 1) {
					correct_guesses = word_length;
					for (int i = 0; i < word_length; i++) blanks[i] = word[i];
					break;
				}
			}

		} else {

			// If guess is only one character
			if (guess_length == 1) {

				// Iterate through word and check for matches
				for (int i = 0; i < word_length; i++){
					if (word[i] == guess[0]) {
						match = 1;
						blanks[i] = word[i];
					}
				}

			} else {
				// If no input given
				printf("Waste of a turn! Make sure you provide an input.\n");
			}

			// Check for match (including duplicates)
			int dup = 0;
			if (match == 1) {
			printf("That's a match!\n");
			for (int i = 0; guesses[i]; i++){
				if (guesses[i] == guess[0]) {
					dup = 1;
					break;
				}
			}

			if (dup == 0) {
				correct_guesses++;
			}

			} else {
				stage++;
			}

			// Check for duplicates before adding guess to guesses array
			dup = 0;
			for (position = 0; guesses[position]; position++){
				if (guesses[position] == guess[0]) {
					dup = 1;
				}
			}

			if (dup == 0) {
			guesses[position] = guess[0];
			guesses_count++;
			}
		}
			match = 0;
			guess_length = 0;
	}

	} else {
		printf("You must provide a word to guess!\n");
	}
  return 0;
}