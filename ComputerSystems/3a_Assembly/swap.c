// Write a C program that swaps two integers(in the main body of code).
//


#include <stdio.h>
#include <stdlib.h>

int swap(int* a, int* b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
	return 0;
}

int main()
{
	int a = 1;
	int b = 2;
	swap(&a, &b);

         //printf("\na: %d", a);
         //printf("\nb: %d", b);

	return 0;
}
                       
