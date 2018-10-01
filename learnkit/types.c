#include <stdio.h>
#include <stdlib.h>
#include <math.h>


int main(){
  
  // int i = 12;
  // float f = 32.9;

  int floatInInt = 5.1;
  printf("The value stored in a is %d\n", floatInInt); // Output: The value stored in a is 5
  //This is as expected.  Integers cannot store decimals, so the value is implicitly type cast from a float to an integer.  The decimal is discarded.

  float IntInFloat = floatInInt;
  printf("The value stored in b is %f\n", IntInFloat); // Output: The value stored in b is 5.000000
  //This is as expected.  Floats can store the information present in an integer.  The value is implicitly converted to a float, in this case 5.000000

  int c = 22/7;
  printf("The value stored in c is %d\n", c); // Output: The value stored in c is 0
  //This is as expected.  Integer math discards decimals, so 5/7 == 0 in integer-speak.

  float d = 5/7;  
  printf("The value stored in d is %f\n", d); // Output: The value stored in d is 0
  //What gives?  5/7 is a decimal number, and floats can do that, right?
  //The issue arises from the order of operations in the statement.  
  //When the compiler sees the '/' operator, it looks at the types of the operands and performs the appropriate operation.  
  //Because 5 and 7 are both integers, it uses the integer version of divide.  
  //As in example a, (int) 5 divided by (int) 7 results in (int) 0, then, as above in example b, the value 0 is implicitly type cast from an int to a float.
  //The above format is actually how we solve this problem

  float e = (float) 5 / 7;
  printf("the value stored in e is %f\n", e); // Output: The value stored in e is 0.714286
  //This is what we expected.  The compiler sees that one of the operands is a float, and provides a result accordingly.
  //You don't need to typecast both operands to get this result, but be careful with order of operations.
  // (float)( 5/7 ) will first handle the division as integer math, then typecast the result into a float, resulting in 0.000000 again.

  return 0;
};