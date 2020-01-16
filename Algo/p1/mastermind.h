/*
Algorithms 9/27/18
Project #1 Part B .h File
Mastermind Game
Andrea Matellian and Rebekah Davis
Group ID: DAVMAT
*/

#include "response.h"

using namespace std;

class mastermind
{
  public:
    mastermind(int,int);  //constructor with keyboard input
    mastermind(); //constructor with n=5 and m=10
    void printSecretCode(); //print the secret code to screen
    int humanGuess(); //reads guess from keyboard and returns the guess
    bool isSolved(int response);  //to figure out if code has been solved
    response getResponse(code &guessCode, code &secretCode);  //returns a response

  private:
    int length;
    int range;
    mastermind response(int, int);
    code secretCode;  //code object as a data member
    vector <int> guess;
};

// ***********************************************************
//      mastermind class implementation
// ***********************************************************

mastermind::mastermind(int n,int m)
{ //keyboard input, creates the random secret code with function from code class
  code secretCode(length, range);
  length = n;
  range = m;
  secretCode.createSecretCode();
}

mastermind::mastermind()
{ //non-keyboard input, creates random secret code
  secretCode(length, range);
  length = 5;
  range = 10;
  code secretCode(length, range);
}

void mastermind::printSecretCode()
{ //display secretCode to the screen
  for (int i = 0; i <= length; i++)
    {
      cout << secretCode << " ";
    }
}

int mastermind::humanGuess()
{ //returns code object guess
  int input;
  guess.code(length,range);
  cout << "Please enter your guess: ";
  cin >> input;
  guess.push_back(input);
  return guess;
}

response mastermind::getResponse(code &guessCode, code &secretCode)
{ //uses pointer *r to get response using code functions
  response *r = new response(secretCode.checkCorrect(guessCode.getVector()),
  secretCode.checkIncorrect(guessCode.getVector()));
  r = &response;
  return *r;
}

bool mastermind::isSolved(int response)
{
  //pass in response, true if code has been solved
  setNumCorrect(response);
  if(getNumCorrect == length)
    return true;
  else
  {
    setNumIncorrect(response);
    return false;
  }
}

void mastermind::playGame()
{
  //initialize random code, print code to screen
  //iteratively (10x) get guess from user & print response until maker or breaker wins
  mastermind master(n,m); //makes object
  //call funtions
  master.printSecretCode();
  master.humanGuess();
  master.getResponse(&guess);
  master.isSolved(*r);

  int i = 0;
  while (i<10)
  {
    if (isSolved())
    {
      cout<<"You win";
      break;
    }

    else
    {
      master.getNumCorrect();
      master.getNumIncorrect();
      cout<<"Try again";
      continue;
    }
  }

  if (i=10)
    cout<<"You lose";
  }
