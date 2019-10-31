void find_space()
{
	char *input = get_input(); //user data
	char** cmds = (char **) malloc(sizeof(char*) * 16);
	int i;
	for(i=0; i<BUFFER_SIZE; i++)
	{
		cmds[i] = strsep(&input, " ");
		if(input[i] == NULL)
			break;
		if(strlen(input[i] == 0))
			i--;
		printf("cmd: %s", cmds[i]);
	}

void find_space()
{
	char *input = get_input(); //user data
	char** cmds = (char **) malloc(sizeof(char*) * 16);
	int i;
	for(i=0; i<BUFFER_SIZE; i++)
	{
		cmds[i] = strsep(&input, " ");
		if(input[i] == NULL)
			break;
		if(strlen(input[i] == 0))
			i--;
		printf("cmd: %s", cmds[i]);
	}

}