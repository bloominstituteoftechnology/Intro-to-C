// **** Sort strings alphabetically ****
// #include <stdio.h>
// int main(void)
// {
//     char word1[50];
//     char word2[50];
//     int i = 0;

//     printf("Please enter a word: ");
//     scanf("%s", word1);
//     printf("And another: ");
//     scanf("%s", word2);
//     // Find first letter in which words differ
//     while (word1[i] != '\0' && word2[i] != '\0' && word1[i] == word2[i])
//         i++;
//     if (word1[i] < word2[i])
//         printf("%s comes before %s in the alphabet.\n", word1, word2);
//     else if (word1[i] > word2[i])
//         printf("%s comes after %s in the alphabet.\n", word1, word2);
//     else
//         printf("You entered the same word, %s, twice.\n", word1);
//     return 0;
// }

// ****  Search for a number in an array using linear search ****
// #include <stdio.h>
// int main(void)
// {
//     //! showArray(list, cursors=[i])
//     int list[] = {6, -2, 5, 12, 7, 3, 8, 18, -10, 1};
//     int n = 10;
//     int item, i, found;

//     printf("Which number are you looking for? ");
//     scanf("%d", &item);
//     found = 0;
//     i = 0;
//     while (!found && i < n)
//     {
//         if (item == list[i])
//             found = 1;
//         else
//             i++;
//     }
//     if (!found)
//         printf("%d is not a member of this list. \n", item);
//     else
//         printf("I found %d at index %d in the list. \n", item, i);
//     return 0;
// }

// You are conducting a linguistic study and are interested in finding words that contain the letter 't' or 'T' in the first half of the word (including the middle letter if there is one). Specifically, if the first half of the word does contain a 't' or a 'T', your program should output a 1. If the first half does not contain the letter 't' or 'T', but the second half does, then your program should output a 2. Otherwise, if there is no 't' or 'T' in the word at all, your program's output should be -1. You may assume that the word entered does not have more than 50 letters.
// #include <stdio.h>
// int main(void)
// {
// 	char word[51];
// 	int length = 0;
// 	int i,found, maxindex;

// 	scanf("%s", word);

// 	while (word[length]!='\0')
// 	    length++;
// 	if (length%2==0)
// 	    maxindex = length/2-1;
// 	else
// 	    maxindex = length/2;

// 	i = 0;
// 	found = 0;
// 	while (!found && i < length) {
// 		if (word[i]=='t' || word[i]=='T') found++;
// 		else i++;
// 	}

// 	if (!found)
// 	    printf("-1");
// 	else if (i <= maxindex) printf("1");
// 	else printf("2");

// 	return 0;
// }

// Sort an array using bubble sort
// #include<stdio.h>
// int main(void) {
//     //! showArray(list, cursors=[i])
//     // Sorting from smallest to largest
//     int list[] = {759, 14, 2, 900, 106, 77, -10, 8, -3, 5}; /* unsorted list */
//     int n = 10;
//     int i, j;
//     int swap;

//     printf("Unsorted list: \n");
//     for (i=0; i<n; i++) {
//         printf("%d ", list[i]);
//     }

//     for (j=0; j<n-1; j++) {
//         for (i=0; i<n-1; i++) {
//             if (list[i] > list[i+1]) {
//                 swap = list[i];
//                 list[i] = list[i+1];
//                 list[i+1] = swap;
//             }
//         }
//     }
//     printf("\nSorted list: \n");
//     for (i=0; i<n; i++) {
//         printf("%d ", list[i]);
//     }
//     return 0;
// }

//  find repeat letters in a word
// #include <stdio.h>
// int main(void)
// {
//     //! showArray(list, cursors=[i])
//     char word[51];
//     int length = 0;
//     int i, j;
//     char swap;
//     int repeats = 0;

//     scanf("%s", word);

//     while (word[length]!='\0')
// 	length++;

//     //Sort the word by alphabetical order
//     for(j=0;j<length-1; j++) {
//         for(i=0;i<length-1;i++) {
//             if (word[i] > word[i+1]) {
//                 swap = word[i];
//                 word[i]   = word[i+1];
//                 word[i+1] = swap;
//             }
//         }
//     }

//     i = 0;

//     //Check for repeating characters in the sorted word
//     while (i<length-1) {
//         if (word[i]==word[i+1]) {
//             repeats++;
//             j=i+2;

//             //Continues through the word until it reaches a new character
//             while (j<length && word[i]==word[j])
//                 j++;
//             i = j;
//         } else {
//             i++;
//         }
//     }

//     printf("%d", repeats);

//     return 0;
// }