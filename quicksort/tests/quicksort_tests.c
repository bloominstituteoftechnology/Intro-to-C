#include <quicksort.h>
#include "../../utils/minunit.h"
#include "../../utils/utils.h"

char *test_quicksort()
{
    int single_int[] = { 100 };
    int expected1[] = { 100 };
    quicksort(single_int, 0, 0);
    mu_assert(check_arrays(single_int, expected1, 1, 1), "Your quicksort implementation failed on an array with a single element.");

    int arr1[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int expected2[] = {4, 10, 11, 18, 42, 43, 47, 49, 55, 67, 79, 89, 90, 95, 98, 100};
    int n = sizeof(arr1) / sizeof(arr1[0]);
    int m = sizeof(expected2) / sizeof(expected2[0]);
    quicksort(arr1, 0, n-1);
    mu_assert(check_arrays(arr1, expected2, n, m) == 1, "Your quicksort implementation did not return the expected output.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_quicksort);

    return NULL;
}

RUN_TESTS(all_tests);
