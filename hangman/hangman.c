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

int main(int argc, char *argv[]) {
  /* Your code here */
	
	// parse the word input
	// store the word input into a string in memory

	// ask for a user's letter guess
	// parse the guess and ensure it is valid (i.e. a single character, checking for upper/lowercase)
	// keep track of all letters that have been guessed

	// compare the guess with each char in the string
	// if correct, append the guess to the word guess display for each instance of the letter (e.g. guess is A, word is hangman, display is *A***A*)
	// if incorrect, append the guess to the 'guessed letters' display, and add a limb to the hangman

	// if the user makes 8 mistakes, the game is lost and is over

	// if the user completes the word before 8 mistakes, the game is won


  return 0;
}