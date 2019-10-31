// Implement a lexer parser in this file that splits text into individual tokens.
// You may reuse any functions you write for your main shell.
// The point is that you get something small working first!

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void print(char* argv[])
{
  int i = 1;  //skip ./parse
  while(argv[i] != NULL)
  {
    printf("%s\n", argv[i]);
    i++;
  }
}

int main(int argc, char* argv[])
{
  print(argv);
  return 0;
}
