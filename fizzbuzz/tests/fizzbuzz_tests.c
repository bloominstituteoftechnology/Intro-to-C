#include <fizzbuzz.h>
#include "../../utils/minunit.h" 

char *test_fizzbuzz()
{
    mu_assert(fizzbuzz(3) == 2, "Your fizzbuzz function did not return 2 for n = 3.");
    mu_assert(fizzbuzz(5) == 3, "Your fizzbuzz function did not return 3 for n = 5.");
    mu_assert(fizzbuzz(10) == 5, "Your fizzbuzz function did not return 5 for n = 10.");
    mu_assert(fizzbuzz(100) == 53, "Your fizzbuzz function did not return 53 for n = 100.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_fizzbuzz);

    return NULL;
}

RUN_TESTS(all_tests);
