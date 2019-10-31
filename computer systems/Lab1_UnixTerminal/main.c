// A program to recursively compute 2^n
// where 1<= n <= 10
//

#include <stdio.h>
#include <math.h>

int main(){
  int n;
  int power = 1; //start at n
  for(n = 1; n <= 10; n++)
  {
    power = 2*power;
    printf("2^%d = %d \n", n, power);
  }
return 0;
}  
