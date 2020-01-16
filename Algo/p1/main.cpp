/*
Algorithms 9/27/18
Project #1 Part B .cpp File
Mastermind Game
Andrea Matellian and Rebekah Davis
Group ID: DAVMAT
*/

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iomanip>

#include "mastermind.h"

using namespace std;

int main()
{
  int n, m;
  cout << "\nPlease enter the length of your desired code: ";
  cin >> n;
  cout << "\nPlease enter the max number in your range: ";
  cin >> m;
  //mastermind object play is used to call playGame
  mastermind play(n,m);
  play.playGame();
  return 0;
}
