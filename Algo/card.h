/*
Algorithms 10/15/18
Project #2 Part B card.h file
Flipcard Game
Rebekah Davis, Andrea Matellian and Nathan Newbury
Group ID: DAVMATNEW
*/

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

#ifndef CARD_H
#define CARD_H

class card
{
    public:

      card(); //constructor

      card(int v, string s); //constructor value and suit

      void setValue(int); //sets value of card

      card(const card& c1);

      void setSuit(string); //gets suit of card

      int getValue(); //gets value of card

      string getSuit();

      friend ostream& operator<< (ostream &ostr, const card& c);

    private:
      int value;
      string suit;
};

template <typename T>
class node
{
public:
	T nodeValue;
	node<T>* next;
	node() : next(NULL) {}
	node(const T& item, node<T> *nextNode = NULL) :
		nodeValue(item), next(nextNode) {}
};
#endif
// ***********************************************************
//      card class implementation
// ***********************************************************
card::card()
{

}

//copy constructor
card::card(const card& c1)
{ //using the card c1 to set the suit and value
	suit = c1.suit;
	value = c1.value;
}

card::card(int v, string s): value(v), suit(s)
{
  setValue(v);
  setSuit(s);
}

ostream & operator<<(ostream & os, const card & c)
{
  if(c.value == 1)
    os << "card value: " << "Ace" << "  ";
  else if(c.value <= 10)
    os << "card value: " << c.value << "  ";
  else if(c.value == 11)
    os << "card value: " << "Jack" << "  ";
  else if(c.value == 12)
    os << "card value: " << "Queen" << "  ";
  else if(c.value == 13)
    os << "card value: " << "King" << "  ";
  os << "suit: " << c.suit << endl;
	return os;
}

void card::setValue(int v)
{
  value = v;
}

void card::setSuit(string s)
{
  suit = s;
}

int card::getValue()
{
  return value;
}

string card::getSuit()
{
  return suit;
}
