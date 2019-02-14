#include <stdlib.h>
#include <malloc.h>
#include <string.h>
#include "../../utils/minunit.h"
#include "../../utils/utils.h"
#include "../../pointers/pointers.h"

char *test_string_dup()
{
    char *s = "Some string to duplicate.";
    char *dup = string_dup(s);
    mu_assert(s != dup, "Your string_dup function did not actually duplicate the given string.");
    mu_assert(check_strings(dup, s) == 0, "Your string_dup function did not correctly duplicate the given string.");

    free(dup);

    return NULL;
}

char *test_mem_copy()
{
    int numbers[] = {100, 55, 4, 98, 10, 18, 90, 95, 43, 11, 47, 67, 89, 42, 49, 79};
    int n = sizeof(numbers) / sizeof(numbers[0]);
    int *target = malloc(n * sizeof(int));
    
    mem_copy(target, numbers, n * sizeof(int));
    mu_assert(check_arrays(target, numbers, n, n) == 1, "Your mem_copy function did not correctly copy an array of integers.");

    char src[50] = "http://lambdaschool.com";
    char dest[50];

    mem_copy(dest, src, strlen(src)+1);
    mu_assert(check_strings(dest, src) == 0, "Your mem_copy function did not correctly copy an array of characters.");

    free(target);

    return NULL;
}

char *test_resize_memory()
{
    char *url = strdup("http://lambdaschool.com");
    char *path = strdup("/students/");
    int url_length = strlen(url);
    int path_length = strlen(path);
    
    int new_length = url_length + path_length + 1; // +1 for the NUL terminator
    char *new_url = resize_memory(url, url_length, new_length);
    char *p = new_url + url_length;

    while (*path != '\0') {
        *p = *path;
        p++;
        path++;
    }

    *p = '\0';

    mu_assert(check_strings(new_url, "http://lambdaschool.com/students/") == 0, "Your resize_memory function did not increase the size of the given string correctly.");
    
    char *new_new_url = resize_memory(new_url, new_length, 8);

    mu_assert(memcmp(new_new_url, "http://l", 8) == 0, "Your resize_memory function did not truncate the size of the given string correctly.");

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_string_dup);
    mu_run_test(test_mem_copy);
    mu_run_test(test_resize_memory);
    
    return NULL;
}

RUN_TESTS(all_tests)