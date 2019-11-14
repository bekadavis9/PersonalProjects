#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){

  // A pointer to a file
  FILE* myFile;

  // open file containing data
  myFile = fopen(argv[1],"r");

  // check if successfully opened file
  if(NULL == myFile){
        fprintf(stderr,"Unable to open file\n");
        fprintf(stderr,"Program terminating now...");
        exit(1);
  }

char buffer[257];

int instrCtr = 0; //count number of instructions
int cycles = 0;   //get estimated number of cycles

int addC, subC, mulC, divC, movC, leaC, pushC, popC, retC = 0;
char addS[] = "add";
char subS[] = "sub";
char mulS[] = "mul";
char divS[] = "div";
char movS[] = "movq";
char leaS[] = "leaq";
char pushS[] = "pushq";
char popS[] = "popq";
char retS[] = "ret";
int add, sub, mul, div, mov, lea, push, pop, ret = 0;



while(fscanf(myFile, "%256s", buffer) != EOF)
{
  if(strcmp(buffer, addS) == 0)
  {
    mulC++;
    instrCtr++;
  }
  else if(strcmp(buffer, subS) == 0)
  {
    subC++;
    instrCtr++;
  }
  else if(strcmp(buffer, mulS) == 0)
  {
    mulC++;
    instrCtr++;
  }
  else if(strcmp(buffer, divS) == 0)
  {
    divC++;
    instrCtr++;
  }
  else if(strcmp(buffer, movS) == 0)
  {
    movC++;
    instrCtr++;
  }
  else if(strcmp(buffer, leaS) == 0)
  {
    leaC++;
    instrCtr++;
  }
  else if(strcmp(buffer, pushS) == 0)
  {
    pushC++;
    instrCtr++;
  }
  else if(strcmp(buffer, popS) == 0)
  {
    popC++;
    instrCtr++;
  }
  else if(strcmp(buffer, retS) == 0)
  {
    retC++;
    instrCtr++;
  }
  else
    continue;
}

  fclose(myFile);

  //int add, sub, mul, div, mov, lea, push, pop, ret = 0;
  printf("\nadd %d\n", addC);
  printf("sub %d\n", subC);
  printf("mul %d\n", mulC);
  printf("div %d\n", divC);
  printf("mov %d\n", movC);
  printf("lea %d\n", leaC);
  printf("push %d\n", pushC);
  printf("pop %d\n", popC);
  printf("ret %d\n", retC);

  printf("\n\nTotal Instructions = %d", instrCtr);

  cycles += 1*addC;
  cycles += 1*subC;
  cycles += 3*mulC;
  cycles += 32*divC;
  cycles += 1*movC;
  cycles += 2*leaC;
  cycles += 5*pushC;
  cycles += 5*popC;
  cycles += 3*retC;
  printf("\nTotal Cycles = %d\n", cycles);


  return 0;

}
