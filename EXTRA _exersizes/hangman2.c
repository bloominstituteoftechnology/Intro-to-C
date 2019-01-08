#include <stdio.h>
#include <string.h>
#include <curses.h>

void clrscr()				//A function to clear the terminal/cmd window.
{
    system("@cls||clear");
}

void hangman(int i){			//A function that prints the hanged man ascii art according to how many wrong guesses the user has made.
        clrscr();           		//Command to clear screen, if it doesn't work, use the commented line bellow.
        //printf(" \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n");
        switch (i){
        case 0:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| | | / \n| |/ \n| | \n| | | \n| | \n| | \n| | | \n| | \n| | \n| | | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 1:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| | | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| | | \n| | \n| | \n| | \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 2:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |           . .    \n| |          |   |    \n| |          | . |     \n| |          |   |      \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 3:
            printf("___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . .    \n| |       // |   |    \n| |      //  | . |     \n| |     ')   |   |      \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 4:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\ \n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| | \n| | \n| | \n| | \n| | \n|=========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 5:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\ \n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| |          ||    \n| |          ||    \n| |          ||    \n| |          ||    \n| |         / |    \n==========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
        case 6:
            printf(" ___________.._______ \n| .__________))______| \n| | / /      || \n| |/ /       || \n| | /        ||.-''. \n| |/         |/  _  \ \n| |          ||  `/,| \n| |          (\\`_.' \n| |         .-`--'. \n| |        /Y . . Y\ \n| |       // |   | \\ \n| |      //  | . |  \\ \n| |     ')   |   |   (` \n| |          || || \n| |          || || \n| |          || || \n| |          || || \n| |         / | | \\ \n==========|_`-' `-' |===| \n|=|=======\ \       '=|=| \n| |        \ \        | | \n: :         \ \       : : \n. .          `'       . . \n");
            break;
}       }

int main()
{
    char word[20];			//Used to store the user word. Most words are less than 20 characters so the default size is 20.
    char stars[20];			//A string full of * that are replaced upon the user entering the right letter of the word.
    int counter = 0;			//A counter to use in the for loops.
    int len;				//len is the length of the word entered.
    char ch;				//ch is a temporary character variable.
    int strikes=0;			//strikes counts how many wrong characters the user has guessed.
    int trigger = 0;			//The trigger variable serves as a flag in the for loops bellow.
    int wincounter=0;			//wincounter keeps track of the number of correct guesses.
    int i;				//Another counter variable to be used in for loops.

    //Ascii Art
    printf(" _                                             \n");
    printf("| |                                            \n");
    printf("| |__   __ _ _ __   __ _ _ __ ___   __ _ _ __  \n");
    printf("| '_ \\ / _` | '_ \\ / _` | '_ ` _ \\ / _` | '_ \\ \n");
    printf("| | | | (_| | | | | (_| | | | | | | (_| | | | | \n");
    printf("|_| |_|\\__,_|_| |_|\\__, |_| |_| |_|\\__,_|_| |_| \n");
    printf("                    __/ |                      \n");
    printf("                   |___/  \n");


    printf("\n\nEnter a word:");			//Ask the user to enter a word.
    scanf("%s", &word);
    len = strlen(word);					//Make len equal to the length of the word.


    clrscr();						//To clear the screen, if function doesn't work properly, use the commented line bellow instead.
    /*printf(" \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n \n");*/


    //Fill the stars string with * according to the input word length (len)
    for(counter=0; counter<len; counter++)
    {
        stars[counter]='*';
    }


    stars[len]='\0';					//Insert the terminating string character at the end of the stars string.


    //Enter main program loop where guessing and checking happens. 26 is for 20 maximum characters + 6 strike characters.
    for(counter = 0; counter<26; counter++)
    {

        if(wincounter==len)			    	//If the number of correct guesses matches the length of the word it means that the user won.
        {
            printf("\n\nThe word was: %s\n", word);
            printf("\nYou win!\n");
            break;
        }

        hangman(strikes);			    	//Print the hangman ascii art according to how many wrong guesses the user has made.

        if(strikes==6)				    	//If the user makes 6 wrong guesses it means that he lost.
        {
            printf("\n\nThe word was: %s\n", word);
            printf("\n\nYou lose.\n");
            break;
        }

        printf("\n\n\n\n%s", stars);			//Print the stars string (i.e: h*ll* for hello).

	printf("\n\nGuess a letter:");			//Have the user guess a letter.
        scanf(" %c",&ch);

        for(i=0; i<len; i++)            		//Run through the string checking the characters.
        {
            if(word[i]==ch)
            {
                stars[i]=ch;		    		//If the guess is correct, replace it in the stars string.
                trigger++;			   	//If a character the user entered matches one of the initial word, change the trigger to a non zero value.
                wincounter++;		    		//Increase the number of correct guesses.
            }
        }

        if(trigger==0)
        {
            strikes++;				    	//If the trigger is not a non zero value, increase the strikes counter because that means that the user input character didn't match any character of the word.
        }

        trigger = 0;				    	//Set the trigger to 0 again so the user can guess a new character.
    }

    printf("\nPress any key to exit.");
    while (!kbhit()){};                 		//Wait for user to hit a key. This is done to keep results on-screen and not close the terminal/cmd window right away.
    return 0;

}