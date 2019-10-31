// Take a look at some of the previous examples to create your own program!

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

    char** args[3];


    char* ls[16];
    ls[0]="/bin/ls";
    ls[1]=NULL;
    args[0] = ls;

    char* echo[16];
    echo[0]="/bin/echo";
    echo[1] = "testing";
    echo[2]=NULL;
    args[1] = echo;

    char* nl[16];
    nl[0]="/bin/nl ";
    nl[1]="example1.c";
    nl[2]=NULL;
    args[2] = nl;


    int child_status;

    if(fork()==0)
    {
        execve(ls[0],ls,NULL);
        sleep(5);
        exit(0);
    }
    else
    {
        wait(&child_status);
        if(WEXITSTATUS(child_status)>=0)
            //printf("Child exited with the following child_status %d\n",WEXITSTATUS(child_status));
            printf("\n");
    }

    if(fork()==0)
    {
        execve(echo[0],echo,NULL);
        sleep(5);
        exit(0);
    }
    else
    {
        wait(&child_status);
        if(WEXITSTATUS(child_status)>=0)
            printf("\n");
    }

    if(fork()==0)
    {
        execve(nl[0],nl,NULL);
        sleep(5);
        exit(0);
    }
    else
    {
        wait(&child_status);
        if(WEXITSTATUS(child_status)>=0)
            printf("\n");
    }

	return 0;
}
