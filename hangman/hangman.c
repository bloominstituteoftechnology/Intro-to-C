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
  int counter = 0;
  int wincounter = 0;
  char word[20];
  printf("enter a letter \n");
  scanf("%s", &word);

  int len = strlen(word);
  for (int counter = 0; counter < 26; counter++)
  {
    if (wincounter == len)
    {
    }
  }

  return 0;
}