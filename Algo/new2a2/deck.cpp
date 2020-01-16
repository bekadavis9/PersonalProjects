/*
Algorithms 9/28/18
Project #2 deck.h file
Flipcard Game
Rebekah Davis, Andrea Matellian, and Nathan Newbury
Group ID: DAVMATNEW
*/
#include "card.h"
#include "deck.h"
#include <cstdlib>
#include <stdlib.h>
#include <iostream>
#include <utility>
#include <random>
#include <algorithm>

using namespace std;

deck::deck(int size)
{
  front=NULL;
  back=NULL;
}


deck::deck() //create a deck of 52 cards
{
  card first(1, "Clubs");
  front = new node<card>(first);

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
     os << nodeValue->nodeValue;
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

void deck::playFlip(deck &main_deck)
{
    vector<int> used_cards;
    int size = 24;
    //deck main_deck; //initialize the main deck 52 cards
    deck deck24(size);  //initialize the 24 card deck - empty
    node<card> *target;

    cout << "\n\nCards to be shuffled.\n\n";
    cout << main_deck;

    cout << "\n\nShuffling first time.";
    for(int i = 0; i<100; i++)
      main_deck.shuffle();
    cout << "\n\n\n";
    cout << main_deck;

    std::cout << "\n\nShuffing second time.";
    for(int i = 0; i<100; i++)
      main_deck.shuffle();
    cout << "\n\n\n";
    cout << main_deck;

    std::cout << "\n\nShuffling third time.";
    for(int i = 0; i<100; i++)
      main_deck.shuffle();
    cout << "\n\n\n";
    cout << main_deck;

    std::cout << "\n\nDone shuffling.\n\n";
    bool game = true;
    cout << "The game has started.\n\n";
    int pick;
    int draw;
    card current_card;

    cout << "24 cards are being dealt.\n\n";
    for (int i = 0; i < 24; i++)
    {
      deck24.replace(main_deck.deal());
    }

    while (game == true)
    {
      int points = 0;

      cout << "The dealt 24 cars are\n\n";
      cout << deck24;

      cout << "Do you want to flip a card? 0 = NO, 1 = YES.\n\n";
      cin >> draw;

      if (draw == 1)
      {
        cout << "Pick a number between 1 and 24.\n\n";
        cin >> pick;

        //loop through the used cards vector to make sure they didn't already choose that
        for (int x = 0; x < used_cards.size(); x++)
        {
          if (used_cards[x] == pick)
          {
            cout << "You already chose card number " << pick << ". Pick another card.\n\n";
            cout << "Pick a number between 1 and 24.\n\n";
            cin >> pick;
          }

        }
        used_cards.push_back(pick);
        //cout << used_cards;

        target = deck24.front;
        cout << "Choosing...\n\n";
        for (int j = 1; j <= pick -1; j++)
        {
          target = target->next;
        }
        current_card = target->nodeValue;

        cout << "You chose:  " << current_card << "\n\n";

      if ((current_card.getSuit() == "Hearts"))
      {
        points +=1;
        cout << "+1 point for Heart.\n\n";
        cout << "Points = " << points << " \n\n";
      }

      if (current_card.getValue() == 1)
      {
        points += 10;
        cout << "+10 points for Ace.\n\n";
        cout << "Points = " << points << " \n\n";
      }

      if ((current_card.getValue() == 8) ||
        (current_card.getValue() == 9) ||
        (current_card.getValue() == 10))
      {
        points += 0;
        cout << "no added points.\n\n";
        cout << "Points = " << points << " \n\n";
      }

      if ((current_card.getValue() == 11) ||
               (current_card.getValue() == 12) ||
               (current_card.getValue() == 13))
      {
        points += 5;
        cout << "+5 points for a face card.\n\n";
        cout << "Points = " << points << " \n\n";
      }

      if (current_card.getValue() == 7)
      {
        points /= 2;
        cout << "You lost half of your points.\n\n";
        cout << "Points = " << points << " \n\n";
      }

      if ((current_card.getValue() == 2) ||
          (current_card.getValue() == 3) ||
          (current_card.getValue() == 4) ||
          (current_card.getValue() == 5) ||
          (current_card.getValue() == 6))
          {
            points = 0;
            cout << "You lost all your points.\n\n";
            cout << "Points = " << points << " \n\n";
          }
    }
    else
    {
      break;
    }
  }
  cout<<"done\n\n";
}

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
