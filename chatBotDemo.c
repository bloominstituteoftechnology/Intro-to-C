#include <stdio.h>

int main(void) {
  char first_name[20];
  char last_name[20];
  //receive user input from standard input
  printf("Chatbot: Hello there! What's your name?\n");
  printf("Your full name: ");
  scanf("%s %s", first_name, last_name);
  printf("You said your is: %s %s\n", first_name, last_name);
  // user can enter 'q' in order to exit the chatbot
  // respond to the user's input
  if (strlen(name) > 20) {
    printf("Please abbreviate your name.")
  } else {
    
  }
  return 0;
}