// Write a C program that calls an add function(long add(long a, long b).

#include <stdio.h>
#include <stdlib.h>

long add(long a, long b)
{
	long sum = a + b;
	return sum;
}

int main()
{
	long num1 = 4;
	long num2 = 9;
	long sum = add(num1, num2);

	printf("\n%d + %d = %d\n", num1, num2, sum);

	return 0;
}

