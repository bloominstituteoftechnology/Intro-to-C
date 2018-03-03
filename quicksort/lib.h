#ifndef lib_h
#define lib_h

void swap(int* a, int* b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

#endif