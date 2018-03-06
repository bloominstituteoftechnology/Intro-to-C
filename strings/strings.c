#include <stdio.h>
#include <stdlib.h>
#include <strings.h>

#ifndef TESTING
int main(void)
{
    char quote1[] = "Don't forget to be awesome";
    char quote2[] = "a man a plan a canal panama";
    char rv[512];

    printf("The string 'Don't forget to be awesome' has %i characters.\n", string_length(quote1));
    printf("The string 'a man a plan a canal panama' reversed is: '%s'\n", reverse_string(rv, quote2));
    // printf(">> %s", rv);
    return 0;
}
#endif