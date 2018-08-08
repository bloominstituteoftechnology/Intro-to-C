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
		"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "};

int main(int argc, char *argv[])
{
	/* Your code here */
	int lost = 0;
	int lives = 10;
	char word[50];
	//char *used[50];
	printf("Please insert a word to be guessed!\n");
	scanf("%s", word);
	printf("%s\n", word);

	while (lost == 0)
	{
		char guess[1];
		int correct = 0;
		printf("\nPlease insert your next guess\n");
		getchar();
		guess[0] = getchar();
		for (int i = 0; i < strlen(word); i++)
		{
			if (guess[0] == word[i])
			{
				correct = 1;
				break;
			}
		}
		if (correct == 0)
		{
			lives--;
			printf("Only %d lives remaining!\n", lives);
		}
		if (lives == 0)
		{
			printf("u ded!\n");
			lost = 1;
		}
	}
	return 0;
}