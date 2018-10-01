#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int n = 7;

  for (int i = 0; i<n;i++){
    if (i % 3 == 0)
      printf("Mod 3 = 0 at: %d\n",i);
  };
};