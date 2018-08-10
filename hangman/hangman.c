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
	int strikes = 0;

	char prev_guesses[] = {};

	int length;
	length = strlen(argv);

	

  return 0;
}