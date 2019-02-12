#include <pointers.h>
#include "../../utils/minunit.h"
#include "../../utils/utils.h"

char *test_swap()
{
    int ints_short[] = {4, 9};
    swap(&ints_short[0], &ints_short[1]);
    mu_assert((ints_short[0] == 9 && ints_short[1] == 4), "Your swap function did not swap values correctly.");

    int ints_long[] = {1, 9, 2, 8, 3, 7, 6, 4, 5};
    swap(&ints_long[0], &ints_long[8]);
    swap(&ints_long[3], &ints_long[4]);
    mu_assert((ints_long[0] == 5 && ints_long[8] == 1), "Your swap function did not swap values correctly.");
    mu_assert((ints_long[3] == 3 && ints_long[4] == 8), "Your swap function did not swap values correctly.");

    mu_assert((ints_long[5] == 7 && ints_long[6] == 6), "Your swap function swapped values it shouldn't have.");

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
    mu_assert(string_compare(firetruck, firetrucks) < 0, "Your string_compare did not return a negative value where it was expected.");

    return NULL;
}

char *test_find_char()
{
    char *str = "LambdaSchool";
    char *found = find_char(str, 'b');
    mu_assert(string_compare(found, "bdaSchool") == 0, "Your find_char function did not work as expected.");

    found = find_char(str, 'S');
    mu_assert(string_compare(found, "School") == 0, "Your find_char function did not work as expected.");

    found = find_char(str, 's');
    mu_assert(!found, "Your find_char function return a char when it should have returned NULL.");

    return NULL;
}

char *test_find_string()
{
    char *str = "LambdaSchool";
    char *found = find_string(str, "School");
    mu_assert(string_compare(found, "School") == 0, "Your find_string function did not find the expected substring.");

    found = find_string(str, "Lambda");
    mu_assert(string_compare(found, "LambdaSchool") == 0, "Your find_sting function did not find the expected substring.");

    found = find_string(str, "lambda");
    mu_assert(!found, "Your find_string function found a substring when it should have returned NULL.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_swap);
    mu_run_test(test_string_copy);
    mu_run_test(test_string_compare);
    mu_run_test(test_find_char);
    mu_run_test(test_find_string);

    return NULL;
}

RUN_TESTS(all_tests);