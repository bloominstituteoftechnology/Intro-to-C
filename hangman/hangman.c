#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

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
  char *solution = argv[1];
  int len = string_length(solution);
  int hang_state = 0;
  int playing = 1;

  char guess;
  printf("\nPlease guess a letter: \n");
  guess = getchar();
  printf("\nYour Guess: %c\n", guess);


  return 0;
}





// printf("You wrote: %s\n\n", solution);
//
// for(int i = 0; i < 7; i++)
// {
  //   printf("%.10s\n", &HANG_STATES[i][hang_state*10]);
  // }
