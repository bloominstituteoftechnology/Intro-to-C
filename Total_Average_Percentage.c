#include <stdio.h>

int main()
{
  float a, b, c, d, e;
  float total, average, percentage;
  
  /* Input five floats */
  printf("Enter 5 floats: \n");
  scanf("%f%f%f%f%f", &a, &b, &c, &d, &e);
  
  /* Calculate total, average, and percentage */
  total = a + b + c + d + e;
  average = total / 5.0;
  percentage = (total / 500.0) * 100;
  
  /* Print all results */
  printf("Total = %.2f\n", total);
  printf("Average = %.2f\n", average);
  printf("Percentage = %.2f%\n", percentage);
  
  return 0;
}