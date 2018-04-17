# Hangman

## Objective
Write a program that allows you play a game of Hangman. All of your code can be written in the `hangman.c` file. 

## How your Program Should Work
The main loop of the program prints the current state of the game and then waits for input from the player. When the player types in input (either a single letter guess or a word guess), the game checks if the letter is one that is in the target word or if the word guess matches the target word. If the guess is correct, the game state updates accordingly by revealing the guess as part of the target word. If the guess is incorrect, the game state updates accordingly by showing that letter in the 'incorrect guesses' list and adding another limb to the hangman drawing. 

You'll compile your program with 
```
gcc -o hangman hangman.c
```
This will create an executable called `hangman` that you'll execute with the command `./hangman` once you've successfully compiled the program. 

For this implementation, your program should receive a single word parameter; that will be the word that the player is trying to guess. So running your program might look like this
```
./hangman antidisestablishmentarianism
```
This will start the game loop, which will then continue running until the player wins, the player loses, or the player exits the game. 

## How to Tackle the Problem
This problem can be broken down into many subproblems. Each subproblem can be further broken down into chunks that you can think about how to implement in code. These include, but are not limited to, the following:
 - [ ] Reading input from the user and recording it properly
    - [ ] Figuring out how to parse command line arguments 
 - [ ] Properly recording game state
    - [ ] Keeping track of all letters/words that have been inputted
    - [ ] Recording the incorrect guesses
 - [ ] Printing the proper UI given the game's current state
 - [ ] Implementing the ability to accept both single letter guesses as well as entire word guesses
    - [ ] Having the game UI respond appropriately when a player makes a correct / incorrect guess
 - [ ] Adding the ability for the user to exit the game by typing in the proper keyword

## Rules of Hangman
Just in case you happen to be someone who _doesn't_ know the rules of Hangman, we'll list them here.

The game has you guess a word. You're given 8 strikes. If you guess an incorrect letter (that you haven't already guessed before), or take a stab at guessing the entire word and don't get the correct word, that's one strike. The game keeps track of each letter that you've guessed. You win the game when you guess the correct word. 

