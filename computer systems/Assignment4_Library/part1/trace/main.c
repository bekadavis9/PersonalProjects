#include <stdio.h>
#include <time.h>   // Contains handy things like: time_t and difftime
#include <unistd.h> // For the 'sleep' command

#define DEBUG 1
#define SLEEPTIME 5

void msg(){
	printf("Hello!\n");
}


int main(){
	
	int functionsExecuted = 0;

	time_t start;
	time_t end;
	time(&start);

	#if DEBUG
		sleep(SLEEPTIME);
		functionsExecuted++;
	#endif	

	int i;
	for(i= 0;i  < 10; ++i){
		msg();
		functionsExecuted++;
	}

	time(&end);
	double time_elapsed = difftime(end,start);
	printf ("%.f seconds elapsed\n", time_elapsed);

	printf("\nFunctions executed: %d\n", functionsExecuted);
	return 0;
}
