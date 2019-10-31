#include <stdio.h>
#include <unistd.h>
#include "malloc.h"

#define BLOCK_SIZE sizeof(block_t)
#define INIT_BLOCK(X) block_t X = {.memory = 0} //list starts with total memory bytes = 0
int firstMalloc = 0; //head empty
block_t* list; //linked list


block_t createMemory(size_t s){

	void* ptr = (void*)sbrk(s + BLOCK_SIZE);
	INIT_BLOCK(b); //block_t b with memory = 0
	void* next;

	b.size = s + BLOCK_SIZE;
	b.free = 1;
	b.address = &ptr - 4*BLOCK_SIZE;

	next = (void*)(&ptr + 4*(b.size - BLOCK_SIZE) + 4); //address of pointer + #bytes
	if(next != (void*)0) //if data allocated
	{
		void* end = sbrk(0); //go to end of program for free space
		b.next = end;
	}
	else
	{
			b.next = next;
	}

	return b;
}

void* mymalloc(size_t s){
	INIT_BLOCK(b);
	b = createMemory(s);

	if(firstMalloc == 0)
	{
		firstMalloc = 1;
		list = (block_t*)&b;
		list->next = b.next;
	}
	else
	{
		list->next = &b;
	}
	list->memory += b.size;

	printf("malloc %zu bytes\n",s);
	return b.address;
}

void* mycalloc(size_t nmemb, size_t s){

	int true_size = nmemb * (s + BLOCK_SIZE);
	INIT_BLOCK(b);
	b = createMemory(true_size);

	if(firstMalloc == 0) //using same list but calloc could be called first
	{
		firstMalloc = 1;
		list = (block_t*)&b;
		list->next = b.next;
	}
	else
	{
		list->next = &b;
	}
	list->memory += b.size;

	printf("calloc %zu bytes\n",s);
	return b.address;
}

void myfree(void *ptr){
	size_t count = 0;
	while( ((count - 40) * 4) <= list->memory)
	{
		if (list->address == ptr)
		{
			list->free = 0;
		}
		else
		{
			list = list->next;
		}
	}
	printf("freed %zu bytes\n",list->size);
}
