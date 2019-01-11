#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char HANG_STATES[7][10 * 9] = 
{
//             10        20                  30                  40                  50                  
//   01234567890123456789012345678901234567890123456789012345678901234567890123456789012345678901234567890
	"           +         +----     +----     +----     +----     +----     +----     +----  ",
	"           |         |         |   O     |   O     |   O     |   O     |   O     |   O  ",
	"           |         |         |         |   +     | --+     | --+--   | --+--   | --+--",
	"           |         |         |         |   |     |   |     |   |     |   |     |   |  ",
	"           |         |         |         |         |         |         |  /      |  / \\ ",
	"           |         |         |         |         |         |         |         |      ",
	"/*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   /*****\\   "
};

int get_length(char *word){
	int i;
	for(i=0; word[i]!='\0'; i++){}
	return i+1;
}

char *create_blanks(char *word){
	int length = get_length(word);
	char *letters = malloc(((length-1)*2)+1);
	for(int i=0; i<(length-1)*2-1; i+=2){
		letters[i] = '_';
		letters[i+1] = ' ';
	}
	letters[length*2-1] = '\0';
	return letters;
}

int check_letter(char *word, char letter, char *letters){
	int found_letter = 0;
	for(int i=0; i<get_length(word); i++){
		if(word[i]==letter){
			found_letter++;
			letters[i*2] = letter;
		}
	}
	return found_letter;
}

void print_hang_state(int num){
	printf("printing hang state with num: %d\n", num);
	for(int i=0; i<7; i++){
		for(int j=0; j<8; j++){
			printf("%c", HANG_STATES[i][j+((num-1)*10)]);
		}
		printf("\n");
	}
}

int main(int argc, char *argv[]) {
  /* Your code here */
  char *letters = create_blanks(argv[1]);
  char *bad_letters = malloc(10);
  for(int i=0; i<10; i++){
	  bad_letters[i] = '\0';
  }
  int amount_bad_letters = 0;
  printf("Game beginning.\n");
  int ongoing = 1;
  int count = 0;
  int previous_count = 0;
  int length = get_length(argv[1]);
  while(ongoing == 1){
	printf("%s bad guesses:%s\nEnter a letter: ", letters, bad_letters);
	char c = (char)getchar();
	previous_count = count;
	count += check_letter(argv[1], c, letters);
	while(getchar() != '\n');
	if(previous_count == count){
		bad_letters[amount_bad_letters] = c;
		amount_bad_letters++;
		print_hang_state(amount_bad_letters);
	}
	if(count == length-1){
		ongoing = 2;
	}
	else if(amount_bad_letters == 9){
		ongoing = 3;
	}
  }
  if(ongoing == 2){
	  printf("You win!\n");
  }
  else if(ongoing == 3){
	  printf("You lose!\n");
  }
  printf("Game is over.\n");
  return 0;
}