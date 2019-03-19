#include <pointers.h>
#include <string.h>
#include "../../utils/minunit.h"
#include "../../utils/utils.h"

char *test_string_copy()
{
    char *string = "hello, world";
    char empty[20];

    string_copy(empty, string);
    mu_assert(check_strings(empty, string) == 0, "Your string_copy did not correctly copy the given string.");

    return NULL;
}

char *test_find_char()
{
    char *str = "LambdaSchool";
    char *found = find_char(str, 'b');

    mu_assert(strcmp(found, "bdaSchool") == 0, "Your find_char function did not work as expected.");

    found = find_char(str, 'S');

    mu_assert(strcmp(found, "School") == 0, "Your find_char function did not work as expected.");

    found = find_char(str, 's');

    mu_assert(!found, "Your find_char function return a char when it should have returned NULL.");

    return NULL;
}

char *test_find_string()
{
    char *str = "LambdaSchool";
    char *found = find_string(str, "School");

    mu_assert(strcmp(found, "School") == 0, "Your find_string function did not find the expected substring.");
    
    found = find_string(str, "Lambda");

    mu_assert(strcmp(found, "LambdaSchool") == 0, "Your find_sting function did not find the expected substring.");

    found = find_string(str, "lambda");

    mu_assert(!found, "Your find_string function found a substring when it should have returned NULL.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_find_char);
    mu_run_test(test_find_string);

    return NULL;
}

RUN_TESTS(all_tests);