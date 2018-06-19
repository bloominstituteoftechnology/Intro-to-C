#ifndef callbacks_h
#define callbacks_h

typedef int (*compare_cb) (int a, int b);

int sorted_order(int a, int b);

int reverse_order(int a, int b);

int *bubble_sort(int *numbers, int count, compare_cb cmp);

#endif