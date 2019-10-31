// Write a C program using a switch statement

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int num;

	srand(time(NULL));
	num = rand() % 6;

	//printf("\nnum: %d", num);
	
	switch(num)
	{
		case 1:
			printf("\nThe number is 1.\n");
			break;
		case 2:
			printf("\nThe number is 2.\n");
			break;                                                                                        
		case 3:
			printf("\nThe number is 3.\n");
			break;                                                                                        
		case 4:
			printf("\nThe number is 4.\n");
			break;                                                                                        
		case 5:
			printf("\nThe number is 5.\n");
			break;
		case 6:
			printf("\nThe number is 0.\n");
			break;
		default:
			printf("\nThe number is between 1 and 5.\n");
			printf("\nThe number is %d.\n", num);                                                                                        		
	}

	return 0;
}
