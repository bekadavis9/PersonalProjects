// Modify this file
// compile with: gcc linkedlist.c -o linkedlist

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create your node_t type here
struct node{
  unsigned int data; 
  struct node* next;
};
typedef struct node node_t;

struct list{
  node_t* head;
  node_t* curr;
  node_t* tail;
};
typedef struct list list_t;


// Write your functions here
// There should be 1.) create_list 2.) print_list 3.) free_list
// You may create as many helper functions as you like.

node_t* create_node(int data, node_t* next)
{
  node_t* new_node = (node_t*)malloc(sizeof(node_t));
  new_node->data = data;
  new_node->next = NULL;
  return new_node;
}


list_t* create_list()
{
  list_t* l = (list_t*)malloc(sizeof(list_t));

  int winCount;
  int* pwinCount = &winCount;
  FILE* myFile;
  myFile = fopen("./data.txt","r");

  node_t* headNode = create_node(0,NULL);
  node_t* nextNode = create_node(0,NULL);
  node_t* currNode = create_node(0,NULL);

  while(fscanf(myFile, "%d", pwinCount) != EOF)
  {
    node_t* currNode = create_node(0,NULL);

    if(headNode->data == 0) //list is empty
    {
      headNode->data = winCount;
      headNode->next = currNode;
      l->head = headNode; //head of list - first node
    }
    else
    {
      // 1st iteration: currNode is head->next
      currNode->data = winCount;
      node_t* nextNode = create_node(0,NULL);
      currNode->next = nextNode;
      l->curr = currNode;
      l->tail = currNode;   //data only matters on last pass
      currNode = nextNode; //iterate to next node for next pass
    }
  }
  return l;
}


void print_list(list_t* l)
{
  node_t* temp = create_node(0,NULL);
  int i = 0;
  int year = 2018;
  temp = l->head;

  while(1)
  {
    year = 2018 - i;
    printf("wins in %d: %d\n", year, temp->data);
    temp = temp->next;

    if(temp != l->tail) //getting segmentation fault
      break;
  }
}


void free_list(list_t* l)
{
  free(l);
}

int main(){
  printf("running\n");

  list_t* l = create_list();
  print_list(l);
  free_list(l);

  return 0;
}
