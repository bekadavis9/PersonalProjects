// Write a C program using the goto command and a label.

#include <stdio.h>
#include <stdlib.h>

void chooseThree(int chosen)
{
	if(chosen != 3)
		goto first;
	else
		goto second;

	first:
		printf("\nThe number is not 3. It is %d.\n", chosen);
		return;

	second:
		printf("\nThe number is 3\n");
}

int main()
{
	int num = 7;
	chooseThree(num);

	return 0;
}
