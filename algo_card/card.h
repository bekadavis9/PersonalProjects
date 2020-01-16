/*
Algorithms 9/28/18
Project #2 card.h file
Flipcard Game
Rebekah Davis, Andrea Matellian, and Nathan Newbury
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
      card(); //empty constructor
      card(int v, string s); //value and suit
      card(const card &c); //copy constructor
      void setValue(int);
      void setSuit(string);
      int getValue(); //return value
      string getSuit(); //return suit
      friend ostream& operator<< (ostream &ostr, const card& c); //overloaded cout
      card& operator = (const card &c); //overloaded assignment for copy constructor

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
    return *this;  //calls copy constructor
  value = c.value; //create copy members
  suit = c.suit;
  return *this;    //calls copy constructor
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
