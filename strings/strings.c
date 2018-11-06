#include <stdio.h>
#include <stdlib.h>

/*
    Given a character array s, return the number of characters 
    held inside it.
    
    Do not just use the `strlen` function from the standard libary.
*/
int string_length(char s[])
{
    int count = 0;
    for (int i=0; i < 6000; i++) { //probably should have this be better but testing
         // you're initializing the variable inside of the loop. what is the value of count at the start of every loop? wouldn't it kinda go with the index looking at it?
        //like count is initialized as 0 if the value isn't \0 it increases where as the i one will increase every loop so wouldn't it also increase on the \0 which wouldn't be ideal? 
        // also it's lunch time and I need to shower so brb. plus Imma see when i gotta vote and i'll just hit you up on slack
        // the problem is that every time a loop happens, you're basically saying: "make count 0". every time it loops. OOOOOH how did I miss that!
        // type this in JS in repl.it and see what the value of count is each time:
        /*
        for (let i = 0; i < 10; i++) {
            let count = 0;
            console.log("count: ", count);
            count++;
        }
        */
        if (s[i] == '\0') {
            return count;// need to lookup grabbing values at given index's of array in C. Probably close to js I bet
        }
        else {
            count++;
        }
    }
        return count;
    } // yes you were missing  an ending bracket
 // that would explain those weird errors partially. probably because we have 500 lines of comments
/*
    Write a function that reverses the order of string s and outputs 
    the reversed string to the input array rv. The rv array will have 
    enough space for the reversed string. Don't forget to terminate 
    the reversed string with a null character. Return the rv array.
*/

//now we are hanging out here
// first things first read the readme this time around because I didn't notice that each problem had it's own readme
// I get your for loop on `string_length`. For now that is great, but later on if you have time, consider trying to remove that arbitrary `6000` I know I just don't know with what right off
//
//first idea on reverse_string is to treat it like an array and just chop values off the first aray into another array in the reverse order and just return 2nd array <- This is good
//
// So since i can't just do easy stuff like append and pop and all that I don't think I need to probably instantiate an array the size of the orig array and just 
//every loop of the array make secondArr[0] = s[i] but I don't think that would push the other items over so it might end up being a one item array  <- Think you're right on that
// R: Might end up with a 1 item array
// The first argument that will be passed to reverse_string is already a preconfigured block of memory you can toss items into rofl  J: so that's cool that rv does that. so I just have to 
// move these values over somehow. Should I be hunting for an append or anyhthing crazy or should I really just do some combo of rv[0] = rv[1] s[i] = rv[0] because that seems shitty
// could I just iterate in reverse & then just keep adding them at the index of a sep count starting at 0 counting up?
// 
// i' jiving with what your code is doin', so let's get some printf statements to figure out what's going on 
// these errors are.................yeaaaaaaaaa
//=================================================================================================================

char *reverse_string(char rv[], char s[])
{
    int count = 0; // <- semicolons! c is UNFORGIVING. You also need to declare the type everything you initialize a variable
    for ( int i = string_length(s) - 1; i >= 0; i--) {
        rv[count] = s[i];
        count++;
    }
    int endingZero = (string_length(s)); // Isn't it expecting an array here though? because get_length function's parameters are that way
    // You might need to use `string_length(s)`, not `string_length(rv)`. If you look at the below code, `string_length(rv) + 1` is gonna end up to be like 513 o_o oh. 
    // shit then it's looping it and there is no \0 to stop it
    // also your loop above is just based on the string length right? might not need the +1 then if I grab the length wouldn't the +1 be handled by it being an index anyway/ starting from 0 instead of 1
    // anyways run it again and lets see what errors we're getting

    rv[endingZero] = '\0';
    printf("s: %s, rv: %s\n", s, rv);
    return rv;
}

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";

    char rv[512];

    printf("The string 'Don't forget to be awesome' has %d characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2)); // you can see that the first argument is an empty 512 character array/string

    return 0;
}
#endif
    
