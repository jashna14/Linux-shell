#include "shell.h"

void setenvo(char *input)
{
	if(!strcmp(input, "NULL"))
	{
		printf("Please enter the correct number of arguments\n");
	}

	else
	{
		int len = strlen(input),i;
		char var[str];
		char value[str];
		i=0;

		while(input[i] != '[')
		{
			var[i] = input[i];
			i++;
		}
		var[i] = '\0';

		if(input[i+1] == ']')
		{
			value[0] = '\0';
		}

		else
		{
			i++;
			int j= i;
			while(input[i] != ']')
			{
				value[i-j] = input[i];
				i++;
			}
			value[i-j] = '\0';
		}

		if(setenv(var , value , 1) < 0)
		{
			fprintf(stderr, "Variable could not be set\n");
		}

		printf("%s\n",var);

	}
	return;
}