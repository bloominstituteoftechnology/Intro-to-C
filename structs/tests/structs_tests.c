#include "../../utils/minunit.h"
#include "../../utils/utils.h"
#include <structs.h>

char *test_person_create()
{
    struct Person *tony = Person_create("Tony Stark", 32, 64, 140);

    mu_assert(check_strings(tony->name, "Tony Stark") == 0, "Person_create struct name field does not match the expected result.");
    mu_assert(tony->age == 32, "Person_create struct age field does not match the expected result.")
    mu_assert(tony->height == 64, "Person_create struct height field does not match the expected result.")
    mu_assert(tony->weight == 140, "Person_create struct weight field does not match the expected result.")

    free(tony->name);
    free(tony);

    return NULL;
}

char *test_person_destroy()
{
    struct Person *kurt = Person_create("Kurt Hugo Schneider", 29, 63, 130);
    Person_destroy(kurt);

    return NULL;
}

char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_person_create);
    mu_run_test(test_person_destroy);
    
    return NULL;
}

RUN_TESTS(all_tests);