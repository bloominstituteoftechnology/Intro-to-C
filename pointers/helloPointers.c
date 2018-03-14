#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// void random(x){
//  int* low = &x;
// }

int main()
{
   int arr[] ={};
   for(int i = 0; i < 20; i++){
      arr[i] = i+10;
   }
  for(int i = 0; i < 20; i++){
      printf("The %d\n", arr[i]);
  }

    // int a = 5;
    // int b = 6;
    // if(a>b){
    //     printf("Max iss %d\n", a);
    // } 
    // else
    // {
    //     printf("Max is %d\n", b);
    // }
    return 0;
}