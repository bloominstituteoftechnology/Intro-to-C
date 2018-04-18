#ifndef utils_h
#define utils_h

int check_arrays(int input[], int expected[], int n, int m)
{
    int i;

    if (n != m) {
        return 0;
    }

    for (i = 0; i < n; i++) {
        if (input[i] != expected[i]) {
            return 0;
        }
    }

    return 1;
}

int check_strings(char *input, char *expected)
{
    for ( ; *input == *expected; input++, expected++) {
        if (*input == '\0') {
            return 0;
        }
    }
    
    return *input - *expected;
}

#endif