/*
Algorithms 11/5/18
Project #4 main file
Word Search
Rebekah Davis and Julian Perez
Group ID: DAVPER (24)
*/

#include <iostream>
#include <limits.h>
#include <list>
#include <fstream>
#include "main.hpp"
using namespace std;

int main()
{
   ifstream fin;

   // Read the sample grid from the file.
   string fileName = "sudoku1.txt";

   fin.open(fileName.c_str());
   if (!fin)
   {
      cerr << "Cannot open " << fileName << endl;
      exit(1);
   }

   try
   {
      board b1(SquareSize);

      while (fin && fin.peek() != 'Z')
      {
      	 b1.initialize(fin);
      	 b1.print();

         b1.solve(b1);
         b1.recursions();

         cout<<"\n";
      }
   }
   catch  (indexRangeError &ex)
   {
      cout << ex.what() << endl;
      exit(1);
   }

   return 0;
}
