#ifndef lib_h
#define lib_h

void swap(int* a, int* b, int* c)
{
  int temp = *a;
  *a = *b;
  *b = temp;
  printf("param 1: %i\n", *a);
  printf("param 1: %i\n", *b);
  printf("param 1: %i\n", *c);
}

#endif