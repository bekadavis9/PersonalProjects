/*
Algorithms 9/28/18
Project #2 deck.h file
Flipcard Game
Rebekah Davis, Andrea Matellian, and Nathan Newbury
Group ID: DAVMATNEW
*/

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
      void playFlip(deck &main_deck);
      ~deck();

    private:
      node<card> *front;
      node<card> *nodeValue;
      node<card> *current;
      node<card> *next;
      node<card> *back;
};
#endif
