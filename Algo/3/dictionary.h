/*
Algorithms 10/23/18
Project #3 dictionary.h file
Word Search
Rebekah Davis and Julian Perez
Group ID: DAVPER (24)
*/

#include <stdlib.h>
#include <iostream>
#include <random>
#include "grid.h"
using namespace std;

class dictionary
{
  public:
    dictionary();
    friend ostream& operator<< (ostream &ostr, const vector<string>& words);
    void selectionSort();
    int binarySearch(string target);
    void quickSort();
    void heapSort();


  private:
    vector <string> words;
    vector <string> sorted;
    grid g;
    int length;
};

dictionary::dictionary()
{
  string word;
  int length = 0;
  ifstream f_in;
	string filename = "dictionary.txt";
	f_in.open(filename.c_str());

  if (!f_in)
		cout<<"ERROR: could not open file."<<endl;

  while(!f_in.eof())
	{
    f_in>> word;
    length++;
    words.push_back(word);
  }
  f_in.close();
}

ostream& operator<< (ostream &ostr, const vector<string>& words)
{
  for(int i = 0; i<words.size(); i++)
  {
    cout<< words[i];
    cout<< "\n";
  }
  return ostr;
}

void dictionary::selectionSort()
{
  int minIndex;
  string tmp;

  ofstream fout;
  string filename = "dictionary-sorted.txt"; //create output file
  fout.open(filename.c_str());

  if(!fout)
  {
    cout<<"ERROR: could not open file."<<endl;
  }

  else
  {
    for( int i = 0; i < words.size()-1; ++i)
    {
      minIndex = i;
      tmp = words[i];
      for (int j = i + 1; j < words.size(); ++j)
      {
        if (words[j] <= words[minIndex])
          minIndex = j;
      }

      if(minIndex != i)
      {
        tmp = words[minIndex];
        words[minIndex] = words[i];
        words[i] = tmp;
      }


      fout<< words[i] << "\n";
    }
  }
  fout.close();
}


int dictionary::binarySearch(const I& target)
{
  int i = 0;
  while(i < words.size())
  {
    if(words[i] == target)
    {
      cout<< "\nFound: "<< target;
      return i;
    }
    else
    {
      i++;
      continue;
    }
  }
  
  int left = 0;
  int right = (int)words.size()-1;
  int mid = (left + right)/2;
  
  return -1;
}

void dictionary::quickSort()
{

}

void dictionary::heapSort()
{
  buildMaxHeap(words);
  maxHeapify(words);
}
