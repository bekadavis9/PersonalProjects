/*
Algorithms 9/27/18
Project #1 Part B .h File
Mastermind Game
Andrea Matellian and Rebekah Davis
Group ID: DAVMAT
*/

#include "code.h"

using namespace std;

class response //stores the response to a guess
{
  public:
    response(); //constructor
    vector <int> getResponse(); //used to get the response
    int setNumCorrect(vector <int> &v);
    int getNumCorrect();
    int setNumIncorrect(vector <int> &v);
    int getNumIncorrect();

    //overloaded operators
    friend ostream & operator << (ostream& ostr, const response &r1);
    friend bool operator == (const response &r1, const response &r2);

  private:
    int numCorrect;
    int numIncorrect;
    int length;
    int range;
    vector <int> reply;
    vector <int> g;
    code guess;
};

// ***********************************************************
//      response class implementation
// ***********************************************************

response::response()//constructor
{
  //storing the response to a the guess
  reply.push_back(guess.checkCorrect(&g));
  reply.push_back(guess.checkIncorrect(&g));
}

vector <int> response::getResponse()
{
  //gets the response and returns it
  return reply;
}

//the following are functions to set and get the
//individual stored values in a response
int response::setNumCorrect(vector <int> &v)
{
  guess.checkCorrect(&g);
  numCorrect = guess;
}

int response::getNumCorrect()
{
  return numCorrect;
}

int response::setNumIncorrect(vector <int> &v)
{
  guess.checkIncorrect(&g);
  numCorrect = guess;
}

int response::getNumIncorrect()
{
  return numIncorrect;
}
