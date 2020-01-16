/*
Algorithms 9/28/18
Project #2 deck.h file
Flipcard Game
Rebekah Davis, Andrea Matellian, and Nathan Newbury
Group ID: DAVMATNEW
*/
#include "card.h"
#include <stdlib.h>
#include <iostream>
#include <random>
using namespace std;

#ifndef DECK_H
#define DECK_H
class deck
{
    public:
      deck(); //constructor creates the linked list of 52 cards
      deck(int size); //creates list of 24 cards
      void swap(card *a, card *b);
      void shuffle();
	    void replace(card c);
	    void test(int y);
      friend ostream& operator<< (ostream &ostr, const deck& d); //printDeck
      card deal(); //returns the top card of the deck and is then removed
      ~deck();
      node<card> *front;
    private:
      node<card> *nodeValue;
      node<card> *current;
      node<card> *next;
      node<card> *back;
};
#endif

// ***********************************************************
//      deck class implementation
// ***********************************************************

//constructor for deck(24)
deck::deck(int size)
{
  front=NULL;
  back=NULL;
}

deck::deck() //create a deck of 52 cards
{
  //first card
  card first(1, "Clubs");
  front = new node<card>(first);

  //rest of the 51 cards
  for (int i = 2; i <= 13; i++)
  {
    card c(i, "Clubs");
    front = new node<card>(c, front);
  }

  for (int i = 1; i <= 13; i++)
  {
    card c(i, "Spades");
    front = new node<card>(c, front);
  }

  for (int i = 1; i <= 13; i++)
  {
    card c(i, "Hearts");
    front = new node<card>(c, front);
  }

  for (int i = 1; i <= 13; i++)
  {
    card c(i, "Diamonds");
    front = new node<card>(c, front);
  }
}

void deck::shuffle()
{
  //nodes to be used for shuffle algorithm
  node<card> *one;
	node<card> *two;
	node<card> *three;
	node<card> *four;
	node<card> *temp;
	node<card> *second;
	temp = front->next;
	one = front->next;
	second = front->next;
	int x = (rand() % 48)+1;

	//traverse the linked list to a random spot
	for (int i = 0; i < x; i++)
	{
		temp = one;
		one = one->next;
	}
	//swap two items and swap one item with the first
	front->next = one;
	temp->next = front;
	front = second;
	two = one->next;
	three = two->next;
	four = three->next;
	one->next = three;
	two->next = four;
	three->next = two;
}

//overloaded operator to print deck
ostream & operator<<(ostream & os, const deck & d)
{
  node<card> *current;
  node <card> *nodeValue;
  for(current = d.front; current != NULL; current = current->next)
  {
     os << current->nodeValue;
  }
  return os;
}

//returns top card in deck and then deletes it
card deck::deal()
{
  node<card> *top_card;
  top_card = front;
  front = front->next;
  return top_card->nodeValue;
  delete top_card;
}

//create new card @ end of deck(24)
void deck::replace(card c)
{
	node<card> *last;
  last = front;
  if (front == NULL)
  {
    front = new node<card>(c);
    back = front;
  }

  else
  {
    while (last->next != NULL)
    {
      last = last->next;
    }
  last->next = new node<card>(c);
  back = last->next;
  }
}

//deck destructor
deck::~deck()
{
  node <card>* current = front;
  while( current != 0 )
  {
    node<card>* next = current->next;
    delete current;
    current = next;
  }
  front = 0;
  cout << "Deck destroyed\n";
}
