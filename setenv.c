#include "shell.h"

void setenvo(char *command)
{
	char var[str];
	char value[str];
	var[0] = '\0';
	value[0] = '\0';
	int len = strlen(command);
	int i = 0;

	while(command[i] == ' ')
		i++;

	int j =0;

	while(command[i] != ' ' && i < len)
	{
		var[j++] = command[i];
		i++;
	}

	var[j] = '\0';

	if(var[0] == '\0')
	{
		printf("Please enter the correct number of arguments\n");
		return;
	}

	while(command[i] == ' ')
		i++;

	int start , flag =0;

	if(command[i] == '[')
	{
		i++;
		start = i;
		while(i < len)
		{
			if(command[i] == ']' && command[i+1] == '\0')
			{
				flag =1;
				break;
			}	
			i++;
		}		
	}

	if(flag == 1)
	{
		strcat(value,&command[start]);
		value[i-start] = '\0';
	}

	else
	{
		printf("Please enter the correct number of arguments and in a proper format\n");
		return;
	}


	if(setenv(var , value , 1) < 0)
	{
		fprintf(stderr, "Variable could not be set\n");
	}

	return;
}