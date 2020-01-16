/*
Algorithms 10/15/18
Project #2 Part B main.cpp file
Flipcard Game
Rebekah Davis, Andrea Matellian and Nathan Newbury
Group ID: DAVMATNEW
*/

#include "deck.h"
#include <vector>

using namespace std;

void playFlip()
{
    vector<int> used_cards; //vector to store the used cards to check for repetition
    int size = 24;  //size of the deck
    deck main_deck; //initialize the main deck 52 cards
    deck deck24(size);  //initialize the 24 card deck - empty
    node<card> *target; //target node

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
    card current_card;  //create new card

    cout << "24 cards are being dealt.\n\n";

    for (int i = 0; i < 24; i++)
    {
      deck24.replace(main_deck.deal());
    }

    int points = 0; //set up the point system
    while (game == true)
    {
      cout << "The dealt 24 cars are\n\n";
      cout << deck24;

      cout << "\n\nDo you want to flip a card? 0 = NO, 1 = YES.\n\n";
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
        used_cards.push_back(pick); //putting the chosen card into the used cards pile

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
    cout<<"Your total points are: " << points << "\n\n";
}

int main()
{
  playFlip();

  return  0;
}
