#include <strings.h>
#include "../../utils/minunit.h"
#include "../../utils/utils.h"

char *test_string_length()
{
    char quote[] = "Don't forget to be awesome";
    char another_quote[] = "...My spirit is a roaring sea";

    mu_assert(string_length(quote) == 26, "Your string_length function did not return the expected length.");
    mu_assert(string_length(another_quote) == 29, "Your string_length function did not return the expected length.");

    return NULL;
}

char *test_reverse_string()
{
    char rv1[512];
    char rv2[512];
    char str1[] = "hello world";
    char str2[] = "a man a plan a canal panama";
    
    mu_assert(check_strings(reverse_string(rv1, str1), "dlrow olleh") == 0, "Your reverse_string function did not correctly reverse a string.");
    mu_assert(string_length(rv1) == 11, "Your reversed string does not have the same length as the original string.");

    mu_assert(check_strings(reverse_string(rv2, str2), "amanap lanac a nalp a nam a") == 0, "Your reverse_string function did not correctly reverse a string.");
    mu_assert(string_length(rv2) == 27, "Your reversed string does not have the same length as the original string.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_string_length);
    mu_run_test(test_reverse_string);

    return NULL;
}

RUN_TESTS(all_tests);