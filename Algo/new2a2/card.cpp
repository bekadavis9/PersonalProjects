/*
Algorithms 9/28/18
Project #2 card.cpp file
Flipcard Game
Rebekah Davis, Andrea Matellian, and Nathan Newbury
Group ID: DAVMATNEW
*/

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iomanip>
#include <string>
#include "card.h"
#include "deck.h"

using namespace std;

//empty constructor
card::card() {}

//create card given value & suit
card::card(int v, string s): value(v), suit(s)
{
  setValue(v);
  setSuit(s);
}

//overloaded operator to create new card in copy constructor
card& card::operator = (const card &c)
{
  if(this== &c)
    return *this; //calls copy constructor
  value = c.value; //create copy members
  suit = c.suit;
  return *this; //calls copy constructor
}

//copy constructor, = overloaded
card::card(const card &c)
{
  value = c.value;
  suit = c.suit;
}

//overloaded cout to print card
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

/*
bool operator== (const card& lhs, const card& rhs)
{

	if(lhs.value == rhs.value && lhs.suit ==rhs.suit )
	{
		return true;
		cout<< rhs.value<<endl;
	}
	else
	{
		return false;
	}
}
*/

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
