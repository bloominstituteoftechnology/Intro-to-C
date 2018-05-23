#include <pointers.h>
#include "../../utils/minunit.h"
#include "../../utils/utils.h"

char *test_swap()
{
    int ints_short[] = { 4, 9 };
    swap(&ints_short[0], &ints_short[1]);
    mu_assert((ints_short[0] == 9 && ints_short[1] == 4), "Your swap function did not swap values correctly.");

    int ints_long[] = { 1, 9, 2, 8, 3, 7, 6, 4, 5 };
    swap(&ints_long[0], &ints_long[8]);
    swap(&ints_long[3], &ints_long[4]);
    mu_assert((ints_long[0] == 5 && ints_long[8] == 1), "Your swap function did not swap values correctly.");
    mu_assert((ints_long[3] == 3 && ints_long[4] == 8), "Your swap function did not swap values correctly.");

    mu_assert((ints_long[5] == 7 && ints_long[6] == 6), "Your swap function swapped values it shouldn't have.");

    return NULL;
}

char *test_string_length()
{
    char *string = "Not really a very long string.";
    char string_arr[] = { 'a', 'b', 'c', '\0' };

    mu_assert(string_length("hello, world") == 12, "Your string_length function did not return the correct length for 'hello, world'.");
    mu_assert(string_length(string) == 30, "Your string_length function did not return the correct length when passed a char pointer.");
    mu_assert(string_length(string_arr) == 3, "Your string_length function did not return the correct length when passed a char array.");

    return NULL;
}

char *test_string_copy()
{
    char *string = "hello, world";
    char empty[20];

    string_copy(empty, string);
    mu_assert(check_strings(empty, string) == 0, "Your string_copy did not correctly copy the given string.");

    return NULL;
}

char *test_string_compare()
{
    char *s = "hello, world";
    char *t = "hiya";
    char *m = "goodbye";
    char *n = "see ya";

    char *firetruck = "firetruck";
    char *firetrucks = "firetrucks";

    mu_assert(string_compare(s, s) == 0, "Your string_compare did not return 0 for matching strings.");
    mu_assert(string_compare(s, t) < 0, "Your string_compare did not return a negative value where it was expected.");
    mu_assert(string_compare(n, m) > 0, "Your string_compare did not return a positive value where it was expected.");
    mu_assert(string_compaire(firetruck, firetrucks) < 0, "Your string_compare did not return a negative value where it was expected.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_swap);
    mu_run_test(test_string_length);
    mu_run_test(test_string_copy);
    mu_run_test(test_string_compare);

    return NULL;
}

RUN_TESTS(all_tests);