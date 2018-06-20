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

int str_contains(char *str, char target) {
  return (strchr(str, target) == NULL ? 0 : 1);
}

void print_ui(char *word, char *guessed, int hangman_state, int clear) {
  // if the clear flag is set to true, clear the screen
  if (clear) {
    printf("\033[2J\033[1;1H");
    fflush(stdout); 
  }

  // print the current hangman state
  for (int i = 0; i < 7; i++) {
    printf("%.10s\n", &HANG_STATES[i][hangman_state * 10]);
  }
  printf("\n");

  // print guessed letters
  for (int i = 0; i < strlen(word); i++) {
    if (i > 0) {
      printf(" ");
    }
    if (str_contains(guessed, word[i])) {
      printf("%c", word[i]);
    } else {
      printf("_");
    }
  }

  printf("\n\nWrong guesses:\n");

  // Find and print missed letters 
  for (int i = 0; i < strlen(guessed); i++) {
    if (!str_contains(word, guessed[i])) {
      if (i > 0) {
        printf(" ");
      }
      printf("%c", guessed[i]);
    }
  }
  printf("\n\n");
}

// Reads user input from stdin with the given text prompt
char *read_input(char *prompt) {
  size_t s = 1;
  size_t r = 0;
  int c;

  char *in = malloc(sizeof(char) * s);

  printf("%s", prompt);

  // read in the user's input
  while ((c = fgetc(stdin)) != EOF) {
    if ((char)c == '\n') break;
    if (r == s) {
      s *= 2;
      in = realloc(in, s * sizeof(char)); 
    }
    in[r++] = (char)c;
  }
  in = realloc(in, (strlen(in) + 1) * sizeof(char));
  in[r] = '\0';

  return in;
}

int main(int argc, char *argv[]) {
  /* Your code here */
  // Keep looping until one of three things happens
  // Read in user input
  // Game needs to be able to respond to said input
	// Print the game's UI
  // Store all guessed letters 
  // Need to be able to handle individual letter guesses as well as word guesses
  // Ability to exit out of the game 

  char *word = NULL;
  char *guessed = NULL;
  char *guess = NULL;
  unsigned int guesses = 0; 
  unsigned int clear = 0;
  unsigned int hangman_state = 0;
  unsigned int counter = 0;

  // Check if no input was passed to our program
  if (argc == 1) {
	  printf("Usage: %s [-c] word\n", argv[0]);
	  return 1;
  }

  // Check if the user typed in a flag
  if (argv[1][0] == '-') {
	  // Check if user typed in the `-c` flag
	  if (argv[1][1] == 'c')  {
		  // clear the screen
		  clear = 1;
	  }
    word = argv[2]; 
  } else {
    word = argv[1]; 
  }

  // allocate memory to hold guessed letters
  // use calloc instead of malloc since calloc initializes memory with all 0s 
  guessed = calloc(strlen(word) + 1, sizeof(char));

  // print some spiffy title ascii art
  printf("#################\n");
	printf("#    Hangman    #\n");
	printf("#################\n\n");

  // start our game loop!
  while(1) {
    // print our UI
    print_ui(word, guessed, hangman_state, ((guesses == 0) ? 0 : clear));

    // read user input
    guess = read_input("Guess a letter or a word (or type 'exit'): ");

    // handle if the user wants to exit the game
    if (strcmp(guess, "exit") == 0) break;

    // handle word guesses
    if (strlen(guess) > 1) {
      // word guess
      if (strcmp(guess, word) == 0) {
        // correct guess!
        printf("You guessed the whole word! You win!\n");
        free(guess);
        break; 
      } else {
        // incorrect guess
        printf("Nope!\n");
        // increase strike count against the player
        hangman_state++;
      }
    } else {
      // player guess a single letter
      guessed[guesses++] = guess[0];
      // check to see if the player's guess is a correct one
      if (str_contains(word, guessed[guesses-1])) {
        // player made a correct guess
        // check to see they have the whole word
        for (int i = 0, counter = 0; i < strlen(word); i++) {
          if (str_contains(guessed, word[i])) counter++;
        }
        if (counter == strlen(word)) {
          // player got the whole word
          print_ui(word, guessed, hangman_state, clear);
          printf("Correct! You win!\n");
          free(guess);
          break;
        }
      } else {
        // an incorrect letter guess
        printf("Nope!\n");
        hangman_state++;
      }
    }

    // check to see if the hangman state made it all the way to the end
    if (hangman_state == 8) {
      // hangman complete; player loses
      print_ui(word, guessed, hangman_state, clear);
      printf("You lost! The correct word was %s!\n", word);
      free(guess);
      break;
    }

    printf("\n"); 
  }

  free(guess);
  free(guessed);
  printf("See ya!\n"); 
  
  return 0;
}