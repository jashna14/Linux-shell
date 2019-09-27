#include "shell.h"
void redirection(char *command , char *root);
void piping(char* command , char* root)
{
	char* outputcom_str;
	outputcom_str = (char*)malloc(sizeof(char)*str);
	char* token = strtok(command, "|");
	int cnt_tokens = 0;

	struct com{
	  char arr[1000];
	};

	struct com tokens[100];
	int i=0;

	while (token != NULL)
	{
		strcpy(tokens[i++].arr,token);
		token = strtok(NULL, "|");
		cnt_tokens++ ;
	}

	if(!cnt_tokens)
	{
		return;
	}

	else if(cnt_tokens == 1)
	{
		outputcom_str = removespace(tokens[0].arr);
		redirection(outputcom_str , root);
		return;
	}

	else
	{
		int p[2];
		int in = dup(0), out = dup(1);

		for(i=0;i<cnt_tokens;i++)
		{	
			if(i > 0)
			{
				if(dup2(p[0],0) < 0)
				{
					fprintf(stderr, "failure of dup2\n");
				}
				close(p[0]);
			}

			if(i < cnt_tokens - 1)
			{
				pipe(p);
				if(dup2(p[1],1) < 0)
				{
					fprintf(stderr, "failure of dup2\n");
				}
				close(p[1]);
			}


			outputcom_str = removespace(tokens[i].arr);

			int pid = fork(),status;
			if(pid == 0)
			{   
			  redirection(outputcom_str , root);
			  exit(0);
			} 

			else if(pid > 0)
			{
				waitpid(pid,&status,WUNTRACED);
				dup2(in , 0);
				dup2(out , 1);
			} 

			else
			{
				dup2(in , 0);
				dup2(out , 1);
				perror("error forking\n");
				return;		
			}

		}

		return;
	}

}