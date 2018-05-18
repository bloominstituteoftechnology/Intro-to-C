#include "callbacks.h"
#include "../../utils/minunit.h"
#include "../../utils/utils.h"

char *test_bubble_sort()
{
    int arr[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int expected1[] = {4, 10, 11, 18, 42, 43, 47, 49, 55, 67, 79, 89, 90, 95, 98, 100};
    int expected2[] = {100, 98, 95, 90, 89, 79, 67, 55, 49, 47, 43, 42, 18, 11, 10, 4};
    int count = sizeof(arr) / sizeof(arr[0]);

    mu_assert(check_arrays(bubble_sort(arr, count, sorted_order), expected1, count, count) == 1, "bubble_sort did not sort the input in the correct order.");
    mu_assert(check_arrays(bubble_sort(arr, count, reverse_order), expected2, count, count) == 1, "bubble_sort did not sort the input in reverse order.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_bubble_sort);

    return NULL;
}

RUN_TESTS(all_tests);
