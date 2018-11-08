#include <stdio.h>

int string_compare(void)
{
  char *alphabet = "abcdefghijklmnopqrstuvwxyz";
  int alphaCount = 0; 


  while(*alphabet != '\0') {
    alphaCount++;
    printf("%d", alphaCount);

    // if(m[0] == *alphabet)  {
    //   mCheck = alphaCount;  
    // } else if(n[0] = *alphabet) {
    //   nCheck = alphaCount;
    // }
  }
    return 1;
}

int main(void)
{




    printf("Comparison is %d\n", string_compare());


    return 0;
}