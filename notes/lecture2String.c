#include <stdio.h>

int string_to_int(char *s, char **bad) // IRL use strtoul() instead
{
    int a = 0;
    int v;

    while (*s)
    {                 // while *s isn't '\0'
        v = *s - '0'; // idiomatic

        *bad = s;

        if (v < 0 || v > 9)
        {
            // found a bad character
            // s points to the bad character
            break;
        }

        a *= 10;
        a += v;

        s++;
        (*bad)++;
    }

    return a;
}

int main(void)
{
    char *p;

    printf("%d\n", string_to_int("124x5", &p));

    printf("%s\n", p); // should print x5
}

// #include <stdio.h>
// int string_to_int(char *s) // IRL use stroul() instead
// {
//     int a = 0;

//     while (*s)
//     { //  (*s != '\0') same as (*s != 0)
//         a *= 10;
//         // a += *s - 48; //equivalent to the next line;
//         a += *s - '0'; // idiomatic
//         // printf("%d\n", *s - 48);
//         // a += (int)(*s);
//         s++;
//     }
//     return a;
// }

// int main(void)
// {
//     printf("%d\n", string_to_int("1245"));
// }

// a=0; // 0
// a*=10; // 0
// a+=1; // 1
// a*=10; // 10
// a+=2; // 12
// a*=10; // 120
// a+=4; // 124
// a*=10; // 1240
// a+=5; // 1245
