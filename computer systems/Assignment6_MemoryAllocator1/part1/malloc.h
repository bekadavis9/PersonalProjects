// This header is redefining every call to 'malloc' to our implementation
// 'mymalloc'
// Again, this is a simple textual replacement of the code by the preprocessor
#define malloc(size) mymalloc(size)
#define calloc(nmemb, size) mycalloc(nmemb,size)
#define free(ptr) myfree(ptr)

void *mymalloc(size_t size);
void *mycalloc(size_t nmemb, size_t size);
void myfree(void *ptr);


typedef struct block{
	size_t size; // How many bytes beyond this block have been allocated in the heap
	struct block* next; // Where is the next block in your linked list_m
	int free; // Is this memory free?
	void* address;
	size_t memory;
}block_t;

block_t createMemory(size_t s);
