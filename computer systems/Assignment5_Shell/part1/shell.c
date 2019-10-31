// Implement your shell in this source file.
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define BUFFER_SIZE 80

void sigint_handler(int sig){
	write(1,"\nmini-shell terminated\n",35);
	exit(0);
}

void create_shell()
{
    char* username = getenv("USER");
    printf("\n\n");
    printf("%s: mini-shell> ", username);
}

char* create_arr() {
  char* arr = (char *) malloc(sizeof(char) * BUFFER_SIZE);
  return arr;
}

char* get_input() {
  char* input = create_arr();
  fgets(input,BUFFER_SIZE,stdin);
  return input;
}

int find_pipe(char* input)
{
	int pipe_loc = 0;
	char* str;
	int i;
	for(i = 0; i<80; i++)
	{
		str = strchr(input, '|');
		pipe_loc = str-input;
	}
	return pipe_loc;
}

char** get_cmd()
{
	char** cmds = (char **) malloc(sizeof(char*) * 24);
	char *input = get_input(); //user data
	int pipe_loc = find_pipe(input);

	char* cmd = create_arr();
	char* cmd2 = create_arr();
	char* cmd3 = create_arr();

	int i,j,k = 0;

	//get first command
	for(i=0; i<=BUFFER_SIZE; i++) //search entire input
	{
			if(input[i] == 32) //ASCII char for space
			{
				break;
			}
			cmd[i] = input[i];
	}
	cmds[0] = cmd;

	cmds[2] = NULL;

	//get second command (if exists)
	i = 0;
	while(input[i] != 0) //NULL char
	{
		if(input[i] == 124) // | pipe
		{
			j = i+2; //skip | and space
			while(input[j] != 0)
			{
				cmd3[k] = input[j];
				j++;
				k++;
			}
		}
		i++;
	}
	cmds[3] = cmd3;


//having issues getting flags to work - moving on for the time being
/*
	if(pipe_loc == 0)
	{
		printf("i: %d", i);
		for(j = i+1; j<BUFFER_SIZE; j++)
		{
			cmd2[j] = input[j];
		}
	}
	else
	{
		printf("i: %d", i);
		cmds[2] = 'NULL';
		for(j = i+1; j<pipe_loc; j++)
		{
			cmd2[j] = input[j];
		}
	}
	cmds[1] = cmd2;
*/
	return cmds;
}

void c_cd(char* path)
{
	chdir(path);
}

void c_exit()
{
	exit(0);
}

void c_help()
{
	printf("\n\n----------help page----------\n\n");
	printf("to quit the mini shell, press \"Ctrl+C\" or type \"exit\"\n");
	printf("command structure: [command] <-flag> | [command] <-flag> \n\n");
	printf("type \"hello\" to find out who you are!\n\n");
}

void c_hello()
{
	char* username = getenv("USER");
	printf("hello, %s", username);
}

int run_cmd(char** cmds)
{
	char *input = get_input();
	int pipe_loc = find_pipe(input);
	if(strcmp(cmds[0], "cd"))
	{
		char* path = cmds[1];
		c_cd(path);
	}

	if(strcmp(cmds[0], "exit"))
	{
		c_exit();
	}

	if(strcmp(cmds[0], "help"))
	{
		c_help();
	}

	if(strcmp(cmds[0], "hello"))
	{
		c_hello();
	}

	if(fork()==0)
	{	execvp(cmds[0],&cmds[1]); //"/bin/<cmd>"
		int fd = open("out");
		if(pipe_loc != 0) //pipe exists
		{
			dup2(fd, 1);
		}
		
		exit(1);
		execvp(cmds[3],&cmds[4]); //"/bin/<cmd>"
	}
	else
	{
		wait(NULL); // handy synchronization function again!
	}

	return 0;
}


int main(){
	signal(SIGINT, sigint_handler);
	while(1)
	{
		create_shell();
		char** cmds = get_cmd();
		run_cmd(cmds);
	}
    return 0;
}
