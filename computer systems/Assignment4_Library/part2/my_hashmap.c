// =================== Support Code =================
// Hashmap
//
// - Implement each of the functions to create a working hashmap.
// - Do not change any of the function declarations
//   - (i.e. hashmap_t* hashmap_create() should not have additional arguments)
// - You should not have any 'printf' statements in your functions other
//   than functions that explicitly ask for printf  output.
//   - (You may consider using these printf statements to debug, but they should be removed from your final version)
// - You may add any helper functions that you think you need (if any, or otherwise for debugging)
// ==================================================
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "containers.h"
#include "my_hashmap.h"


// Simple hash function that will put a key into a bucket
// The module operator will make sure we do not go out of bounds.
int stringHash(char* myKey, int numberOfBuckets){
    return strlen(myKey) % numberOfBuckets;
}

// Creates a new hashmap
// Allocates memory for a new hashmap.
// Initializes the capacity(i.e. number of buckets)
// Allocate memory for our hashmap
hashmap_t* hashmap_create(unsigned int _buckets){
    hashmap_t* _hashmap = (hashmap_t*)malloc(sizeof(hashmap_t*));
    // Set the number of buckets
    _hashmap->buckets = _buckets;
    // Initialize our array of lists for each bucket
    node_t* arr[_buckets];
    _hashmap->arrayOfLists = arr;
    // Setup our hash function to point to our
    // stringHash function.
    _hashmap->hashFunction = stringHash;
    // Return the new map that we have created

    return NULL;
}

// Frees a hashmap
// Responsibility to free a hashmap that has been previously allocated.
// Must also free all of the chains in the hashmap
// Attempting to delete a NULL hashmap should exit(1)
// This function should run in O(n) time
void hashmap_delete(hashmap_t* _hashmap){
	node_t* curr = (node_t*)malloc(sizeof(node_t*));
	curr = _hashmap->arrayOfLists[0];

	node_t* next = (node_t*)malloc(sizeof(node_t));
	//next = _hashmap->arrayOfLists[0]->next;

	node_t* temp = (node_t*)malloc(sizeof(node_t));

  int i = 0;
	if(_hashmap != NULL){
    while(i <=_hashmap->buckets)
    {
      curr = _hashmap->arrayOfLists[i];
  		while(curr->next != NULL)
  		{

  			next = curr->next;
  			temp = curr;
  			free(curr);
  			curr = next;
  		}
  		free(_hashmap->arrayOfLists[0]);
  		free(_hashmap);
  	}
  }
	else
        	exit(1);

  //delete all linked list nodes and then delete entire array then entire hashmap
}

node_t* hashmap_iterate(hashmap_t* _hashmap, char* kv){
	int b = _hashmap->buckets;
  	node_t* curr = (node_t*)malloc(sizeof(node_t));
  	curr = _hashmap->arrayOfLists[0];

	int i = 0;

  	while(i<= _hashmap->buckets)
  	{
    		while(curr->next != NULL)
    		{
      			if(strcmp(curr->kv->key, kv) == 0 || strcmp(curr->kv->value, kv) == 0)
			{
				return curr;
			}
			else
			{
				curr = curr->next;
			}
      		}
    	i++;
	}
}

// Returns a boolean value if a key has been put into
// the hashmap
//  - Returns a '1' if a key exists already
//  - Returns a '0' if the key does not exist
//  - Attempting hashmap_hasKey on a NULL hashmap should exit(1)
// The algorithm is:
//  - Call the _hashmap's hash function on the key
//  - Search (i.e. iterate through) that bucket to see if the key exists.
// This function should run in average-case constant time
int hashmap_hasKey(hashmap_t* _hashmap, char* key){
  int bucket = stringHash(key, _hashmap->buckets); //store key for comparison
  int b = 0; //"boolean" to return
  node_t* curr = (node_t*)malloc(sizeof(node_t));
  //curr = _hashmap->arrayOfLists[0];

  if(_hashmap == NULL)
		exit(1);
	else
	{
    curr = _hashmap->arrayOfLists[bucket];
		while(curr->next != NULL)
		{
			if(strcmp(curr->kv->key, key) == 0) // if key of array node is key
			{
  				b = 1;
  				return b;
			}
			else
  				curr = curr->next;
	  }

    b = 0;
    return b; //key not found
  }
}

// Insert a new key/value pair into a hashmap
// The algorithm is:
//  - If a key already exists, do not add it--return
//  - Call the _hashmap's hash function on the key
//  - Store the key/value pair at the end of the buckets chain
//      - You should malloc the key/value in this function
//  - Attempting hashmap_insert on a NULL hashmap should exit(1)
// This function should run in average-case constant time
void hashmap_insert(hashmap_t* _hashmap,char* key,char* value){

  if(hashmap_hasKey(_hashmap,key) == 1){
      printf("already got it");
      return;
  }
  // Create a new pair_t
  pair_t* newpair = (pair_t*)malloc(sizeof(pair_t)); printf("1");
  newpair->key    = (char*)malloc(strlen(key)     * sizeof(char)); printf("2");
  newpair->value  = (char*)malloc(strlen(value)   * sizeof(char)); printf("3");
  // Copy the string passed by the user to our node
  strcpy(newpair->key     ,key); printf("4");
  strcpy(newpair->value   ,value); printf("5");
  // Create a new node
  node_t* newnode = (node_t*)malloc(sizeof(node_t));
  newnode->next = NULL;
  newnode->kv = newpair;

  // Which bucket to search
  unsigned int bucket = _hashmap->hashFunction(key, _hashmap->buckets); // Call some function here
  // Create an iterator that points to the head of list for appropriate bucket
  node_t* iter = _hashmap->arrayOfLists[bucket];
printf("if/else");
  if(iter == NULL)
  {
    iter = newnode;
    printf("\ninsert function -- first\n");
  }
  else
  {
  	while(iter != NULL)
  	{
  		iter = iter->next;

      printf("\ninsert function -- not first\n");

  	}

	iter->next = newnode;
}
  //
  // ... Insert node to appropriate linked list
  return;

}

// Return a value from a key
// Returns NULL if the key is not found
// The algorithm is:
//  - If the key does not exist, then--return NULL if not found.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and return the value
//  - Attempting hashmap_getValue on a NULL hashmap should exit(1)
// This function should run in average-case constant time
char* hashmap_getValue(hashmap_t* _hashmap, char* key){
  if(hashmap_hasKey(_hashmap,key) == 0)
      return NULL;
  else
  {
	node_t* temp = (node_t*)malloc(sizeof(node_t));
        temp = hashmap_iterate(_hashmap, key);
        char* myValue = temp->kv->value;
        return myValue;
  }
}

// Remove a key from a hashmap
// The algorithm is:
//  - Determine if the key exists--return if it does not.
//  - Call the _hashmap's hash function on the key
//  - Search the _hashmap's bucket for the key and then remove it
//  - Attempting hashmap_removeKey on a NULL hashmap should exit(1)
// This function should run in average-case constant time
void hashmap_removeKey(hashmap_t* _hashmap, char* key){
	node_t* temp = (node_t*)malloc(sizeof(node_t));
	temp = hashmap_iterate(_hashmap, key);
	temp->kv->key = NULL;
	return;
}

// Update a key with a new Value
// The algorithm is:
//  - Returns immediately if the key does not exist
//  - Call the _hashmap's hash function on the key
//  - Updates the value of the key to the new value
//  - Attempting hashmap_update on a NULL hashmap should exit(1)
// This function should run in average-case constant time
void hashmap_update(hashmap_t* _hashmap, char* key, char* newValue){
	node_t* temp = (node_t*)malloc(sizeof(node_t));
        temp = hashmap_iterate(_hashmap, key);
        temp->kv->key = newValue;
        return;
}

// Prints all of the keys in a hashmap
// The algorithm is:
//  - Iterate through every bucket and print out the keys
//  - Attempting hashmap_printKeys on a NULL hashmap should exit(1)
// This function should run in O(n) time
void hashmap_printKeys(hashmap_t* _hashmap){

printf("\nprinting\n");

	if(_hashmap == NULL)
		exit(1);
	else
	{
		int i = 0;
		node_t* temp = (node_t*)malloc(sizeof(node_t));
		while(i <= _hashmap->buckets)
		{
			temp = _hashmap->arrayOfLists[i];
			printf("%d\n", temp->kv->key);
			i++;
		}
		free(temp);
	}
}
