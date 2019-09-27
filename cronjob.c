#include "shell.h"

void cronjob(char* command , char* root)
{
	char cmnd[str];
	char total_time[10];
	char period[10];

	cmnd[0] = '\0';
	total_time[0] = '\0';
	period[0] = '\0';

	int len = strlen(command);
	int i = 0;

	while(command[i] == ' ' && i < len)
		i++;

	while(command[i] == '-' && i< len)
	{
		i++;

		if(command[i] == 'c' && command[i+1] == ' ')
		{

			i++;
			while(command[i] == ' ' && i < len)
				i++;

			int start , flag =0;

			if(command[i] == '[')
			{
				i++;
				start = i;
				while(i < len)
				{
					if(command[i] == ']')
					{
						flag =1;
						break;
					}	
					i++;
				}		
			}

			if(flag == 1)
			{
				strcat(cmnd,&command[start]);
				cmnd[i-start] = '\0';
			}

			else
			{
				printf("Please enter the command in a proper syntaxxx\n");
				return;
			}

			i++;

			while(command[i] == ' ' && i < len)
			i++;
		}

		else if(command[i] == 't' && command[i+1] == ' ')
		{
			i++;

			while(command[i] == ' ' && i < len)
			i++;

			int start =0;
			while(command[i] != ' ' && i <len)
			{
				period[start++] = command[i++];
			}

			period[start] = '\0';

			while(command[i] == ' ' && i < len)
			i++;
		}

		else if(command[i] == 'p' && command[i+1] == ' ')
		{
			i++;
			while(command[i] == ' ' && i < len)
			i++;

			int start =0;
			while(command[i] != ' ' && i <len)
			{
				total_time[start++] = command[i++];
			}

			total_time[start] = '\0';

			while(command[i] == ' ' && i < len)
			i++;
		}

	}

	if(total_time[0] == '\0' || period[0] == '\0' || cmnd[0] == '\0')
	{
		printf("Please enter the command in a proper syntaxx\n");
		return;
	}

	else
	{

		int pid , status , tt , p;
		char *com, *com1;

		com = (char*)malloc(sizeof(char)*str);
		com1 = (char*)malloc(sizeof(char)*str);
		tt = atoi(total_time);
		p = atoi(period);
		com1 = removespace(cmnd);



		if(tt < p)
		{
			printf("total time cannot be less than interval period\n");
			return;
		}

		else
		{

			pid = fork();

			if(pid == 0)
			{
				int time = 0;
				fflush( stdout );
				sleep(p);
				fflush( stdout );
				time += p;

				while(time <= tt)
				{
					strcpy(com,com1);
					piping(com , root);
					fflush( stdout );

					printf("\33[2K\r\033[1;31m");
	    			printf("%s@%s :" , user , host);
				    printf("\033[0m");

				    printf("\033[0;32m");
				    printf(" %s > " ,dir_shell);
				    printf("\033[0m");

					fflush( stdout );


					if(time == tt || time + p > tt)
					{
						exit(0);
					}
					sleep(p);
					fflush( stdout );
					time += p;
				}

				exit(0);
				return;
			}

			else if(pid < 0)
 			{
    			printf("error forking\n");
  			}
		}
	}



}