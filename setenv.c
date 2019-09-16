#include "shell.h"

void setenvo(char *input1 , char *input2)
{
	if(input1[0] == '\0')
	{
		printf("Please enter the correct number of arguments\n");
	}

	else
	{
		char var[str];
		char value[str];
		var[0] = '\0';
		value[0] = '\0';
		strcpy(var,input1);
		strcpy(value,input2);

		if(setenv(var , value , 1) < 0)
		{
			fprintf(stderr, "Variable could not be set\n");
		}


	}
	return;
}