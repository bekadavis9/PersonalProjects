/*
Algorithms 9/27/18
Project #1 Part B .h file
Mastermind Game
Andrea Matellian and Rebekah Davis
Group ID: DAVMAT
*/

#include <stdlib.h>
#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;

class code
{
    public:
      code(int, int); //constructor
      int checkCorrect(vector <int> &v);  // correct digits, correct location
      int checkIncorrect(vector <int> &v);  // correct digits, wrong location
      vector <int> getVector(); //for getting the vector
      void codeGuess(int, int); //creates vector for guess
      void createSecretCode(); //creates random code

    private:
       int length; //n
       int range;  //m
       vector <int> secretC; //represents secret code generated randomly
       vector <int> checkLoc; //vector to hold values in incorrect location
       vector <int> newGuess; //used for condition statements
};

// ***********************************************************
//      code class implementation
// ***********************************************************

void code::createSecretCode()
{
  srand(time(NULL));  // initialize random seed
  secretC.clear();  //clear past secret code
  for (int i = 0; i < length; i++)
    {
      secretC.push_back(rand()%range); // create vector within range
    }
}

void code::codeGuess(int n, int m) //creates empty guess vector of length n
{
  length = n;
  range = m;
  vector <int> guess(n,0);
}

code::code(int n, int m)  //constructor
{
  length = n;
  range = m;
  vector <int> guess(n,0);
}

vector <int> code::getVector()  //gets vector, returns secret code
{
  return secretC;
}

int code::checkCorrect(vector <int> &v) //correct digits, correct location
{
  int numCorrect = 0;
  for(int i = 0; i < v.size(); i++)
  {
    if (v[i] != secretC[i])
    {
      checkLoc.push_back(secretC[i]);
      newGuess.push_back(v[i]);
    }
    else
      numCorrect ++;
  }
  return numCorrect;
}

int code::checkIncorrect(vector <int> &v) //correct digits, incorrect location
{
  int wrongLoc = 0;

  for(int j = 0; j < checkLoc.size(); j++)
  {
    for(int k = 0; k < newGuess.size(); k++)
    {
      if(newGuess[k] == checkLoc[j]) //check if values are in secret code at all
      {
        wrongLoc++;
        newGuess.erase(newGuess.begin()+k);
      }
    }
  }

  checkLoc.clear();
  newGuess.clear();

  return wrongLoc;
}
