#include "shell.h"

void unsetenvo(char *input)
{
	if(!strcmp(input , "NULL"))
	{
		printf("Please enter the correct number of arguments\n");
	}

	else
	{
		if(unsetenv(input) < 0)
		{
			fprintf(stderr, "Variable could not be unset\n");
		}
	}

	return;
}