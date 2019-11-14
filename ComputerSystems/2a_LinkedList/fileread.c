#include <stdio.h>
#include <stdlib.h>

int main(){

  // A pointer to a file
  FILE* myFile;

  // open file containing data
  myFile = fopen("./data.txt","r");

  // check if successfully opened file 
  if(NULL == myFile){
        fprintf(stderr,"data.txt not found, did you run data.sh?");
        fprintf(stderr,"note: stderr argument means we write to a special 'error' output stream.");
        fprintf(stderr,"Program terminating now...");
        exit(1);
  }

  char buffer[255];

  while(fscanf(myFile, "%s", buffer) != EOF){
    printf("Red Sox wins are: %s\n", buffer);
  }
  //printf("%s",buffer);
    //buffer is the number of wins

  fclose(myFile);

  return 0;

}  
