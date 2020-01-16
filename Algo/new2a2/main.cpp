#include <iostream>
#include <cstdlib>
#include <string>
#include <time.h>
using namespace std;
#include "card.h"
#include "deck.h"
int main()
{
	//run the program
	int x;
	srand(time(NULL));
	deck d1;
	cout << "original deck: " << endl;
	cout << d1;
	//shuffle the deck 40 times
	for (int j = 0; j < 40; j++)
	{
		d1.shuffle();
	}
	cout << "shuffled deck:" << endl;
	cout << d1;
	cin >> x;
}
