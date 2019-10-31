#include <stdio.h> // Any other headers we need here
#include <unistd.h>

void* mymalloc(size_t s){

	//void* p = (void*)malloc(s); 	// In your solution no calls to malloc should be made!
					// Determine how you will request memory :)

	void* b = (void*)sbrk(s);

	if(!b){
		return NULL;
		// We we are out of memory
		// if we get NULL back from malloc
	}
	printf("malloc %zu bytes\n",b);
	
	return b;
}

	
void myfree(void *ptr){
	printf("Freed some memory\n");
	//free(ptr);
}
	
