/*
Algorithms 9/28/18
Project #2 card.h file
Flipcard Game
Rebekah Davis, Andrea Matellian, and Nathan Newbury
Group ID: DAVMATNEW
*/

using namespace std;

#ifndef CARD_H
#define CARD_H
class card
{
    public:
      card();
      card(int v, string s); //value and suit
      card(const card &c);
      void setValue(int);
      void setSuit(string);
      int getValue();
      string getSuit();
      friend ostream& operator<< (ostream &ostr, const card& c);
	    //friend bool operator== (const card& lhs, const card& rhs);
      card& operator = (const card &c);

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
