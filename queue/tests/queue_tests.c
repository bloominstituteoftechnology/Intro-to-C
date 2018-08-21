#include <stdlib.h>
#include <queue.h>
#include <time.h>
#include <unistd.h>
#include "../utils/minunit.h"
#include "../utils/utils.h"

char *test_queue_creation()
{
    unsigned int capacity = 5;
    Queue *q = createQueue(capacity);

    mu_assert(q, "Your createQueue function did not return a valid pointer to the created queue.");
    mu_assert(q->length == 0, "Your createQueue function did not initialize a queue length of 0.");
    mu_assert(q->capacity == capacity, "Your createQueue function did not initialize a queue with the expected capacity.");
    mu_assert(q->storage, "Your createQueue function did not initialize a pointer for storage in the queue.");

    destroyQueue(q);

    return NULL;
}

char *test_enqueue_and_dequeue()
{
    srand(time(NULL) + getpid());

    unsigned int capacity = (rand() % 30) + 1;

    Queue *q = createQueue(capacity);
    int *rand_values = malloc(sizeof(int) * capacity);

    unsigned int i;

    for (i = 0; i < capacity; i++) {
        rand_values[i] = (rand() % 100) + 1;
    }

    for (i = 0; i < capacity; i++) {
        enqueue(q, rand_values[i]);
    }

    for (i = 0; i < capacity; i++) {
        mu_assert(dequeue(q) == rand_values[i], "Your queue did not return an expected value.");
    }

    destroyQueue(q); 

    return NULL;
}

char *test_queue_expansion()
{
    srand(time(NULL) + getpid());

    unsigned int capacity = (rand() % 30) + 1;
    unsigned int increased_cap = capacity + 5;

    Queue *q = createQueue(capacity);
    int *rand_values = malloc(sizeof(int) * increased_cap);

    unsigned int i;

    for (i = 0; i < increased_cap; i++) {
        rand_values[i] = (rand() % 100) + 1;
    }

    for (i = 0; i < increased_cap; i++) {
        enqueue(q, rand_values[i]);
    }

    for (i = 0; i < increased_cap; i++) {
        mu_assert(dequeue(q) == rand_values[i], "Your queue did not return an expected value.");
    }

    destroyQueue(q);

    return NULL;
}


char *all_tests()
{
    mu_suite_start();

    mu_run_test(test_queue_creation);
    mu_run_test(test_enqueue_and_dequeue);
    mu_run_test(test_queue_expansion);

    return NULL;
}

RUN_TESTS(all_tests);