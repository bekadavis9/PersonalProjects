// Write a C program called array2.c that has an array of 400 integers in the function of main that is dynamically allocated.

#include <stdlib.h>
#include <stdio.h>

void addElement(int *arr, int index, int value, int *size, int *capacity){
	if(*size > *capacity)
	{
		arr = realloc(arr, sizeof(arr) * 2);
          	*capacity = sizeof(arr) * 2;
     	}
     	arr[index] = value;
     	*size = *size + 1;
}


int main()
{
	int *arr = malloc(400 * sizeof(int*));
	
	int size = 0;
	int capacity = 400;
	
	addElement(arr, 0, 27, &size, &capacity);
	addElement(arr, 20, 36, &size, &capacity);
	addElement(arr, 100, 59, &size, &capacity);
	addElement(arr, 180, 73, &size, &capacity);
	addElement(arr, 240, 84, &size, &capacity);
	addElement(arr, 310, 90, &size, &capacity);
	addElement(arr, 375, 102, &size, &capacity);
	addElement(arr, 400, 178, &size, &capacity);

	return 0;
}
