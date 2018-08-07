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
/* create list of words to guess
 use random numbers to select one
 get input from user - sanitize
 scanf - check if input matches any letter in the word
 if yes, then figure out how to display the letter in the correct
    position
 if no, then increment incorrect guess counter by 1
 game continues until user guesses word or incorrect counter = 8
 setup interface
*/
char word[100];
char blanks[100];
length = strlen(word);

//display blanks instead of letters for word
for (int i=0; i < length; i++)
{
    blanks[i] = '_';
    blanks[length] = '\0';
}

for (i = 0; i < length; i++)
{
    printf(" ");
    printf(" %c, blanks[i]");
}

char guessedletter;
printf("Please enter a letter:\n");
scanf(" %c, &guessedletter);

for (i = 0; i < length; i++)
{
    if (word[i] == guessedletter)
    {
        blanks[i] = guessedletter;
        guessedletter = 1;
    }
}


  
  return 0;
}
