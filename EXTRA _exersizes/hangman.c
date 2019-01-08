#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


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

struct word {
	size_t length;
	char * text;
};

struct wordlist {
	size_t count;
	struct word * list[90000];
	size_t maxlen;
} * words;

void load(char * path) {
	char temp[30];
	size_t index = 0;

	words = malloc(sizeof(struct wordlist));
	words->maxlen = 1;

	FILE * pFileWords;
	pFileWords = fopen(path, "r");
	if (pFileWords == NULL) {
		printf("\nno wordlist found at %s\n", path);
		exit(1);
	}
	while (fscanf(pFileWords, "%s", temp) != EOF) {
		size_t length = strlen(temp);
		if (words->maxlen < length) {
			words->maxlen = length;
		}
		words->list[index] = malloc(sizeof(struct word));
		words->list[index]->text = (char *)malloc(length*sizeof(char)+1);
		strcpy(words->list[index]->text, temp);
		words->list[index]->length = length;
		index++;
	}
	words->count = index;
}

int play(int minlen) {
	printf("\n");

	srand(time(NULL));
	do {
		struct word * word;
		do {
			word = words->list[rand()%words->count];
		} while (word->length < minlen);

		int guess;
		int chances = 5;
		char wrong[30] = "";
		char found[word->length+1];
		memset(found, '\0', word->length+1);
		memset(found, '_', word->length);

		printf("solved %s | chances %i | wrong '%s'  ", found, chances, wrong);
		do {
			guess = getchar();
			if (guess == '\n') {
				printf("solved %s | chances %i | wrong '%s'  ", found, chances, wrong);
				continue;
			}
			else if (guess == EOF) {
				printf("\n");
				return 0;
			}
			else if (guess < 97 || guess > 122) {
				continue;
			}
			else {
				int i;
				for (i = 0; i < strlen(found); i++) {
					if (word->text[i] == guess) {
						found[i] = guess;
					}
				}
				if (strchr(found, guess) == NULL && strchr(wrong, guess) == NULL) {
					strncat(wrong, (char *)&guess, 30);
					chances--;
				}
			}
		} while (strchr(found, '_') != NULL && chances > 0);
		printf("solved %s | chances %i | wrong '%s'\n", word->text, chances, wrong);
		if (chances > 0) {
			printf("VICTORY!\n\n");
		} else {
			printf("DEFEAT!\n\n");
		}
		while (getchar() != '\n') { /* do nothing */ };
	} while(1);
	return 0;
}

int main(int argc, char * argv[]) {

	char * path = "wordlist.text";
	long minlen = 3;

	if (argc > 1) {
		if (strcmp(argv[1], "-h") == 0) {
			printf("\nhangman command line arguments:\n\
					\n-w path\n\tPath to a whitespace seperated list of words.\
					\n-s size\n\tMinimum word size.\n");
			return 0;
		}
		else {
			int i = 1;
			do {
				if (strcmp(argv[i], "-w") == 0) {
					if (i+1 < argc) { i++; }
					else {
						printf("\n-w requires a wordlist path\n");
						return 1;
					}
					path = argv[i];
				}
				if (strcmp(argv[i], "-s") == 0) {
					if (i+1 < argc) { i++; }
					else {
						printf("\n-s requires a minimum size\n");
						return 1;
					}
					minlen = strtol(argv[i], NULL, 0);
				}
				i++;
			}	while (i < argc);
		}
	}
	load(path);
	if (minlen > words->maxlen) {
		printf("\nsize must not be larger than the longest word, %ld\n", words->maxlen);
		exit(1);
	}
	return play(minlen);
}
