#include "shell.h"

void redirection(char *command , char *root)
{
	int i, len = strlen(command) , flag =0 , gt = -1, lt = -1 ,  append = 0;

	for(i=0;i<len;i++)
	{
		if(command[i] == '>')
		{
			flag =1;
			gt =  i;
		}

		else if(command[i] == '<')
		{
			flag =1;
			lt =  i;
		}
	}

	if(flag == 0)
	{
		parse_command(command , root);
		return;
	}

	else
	{
		int in = dup(0) , out =  dup(1);
		int k,j , fd_read = -1 , fd_write = -1;
		char *read , *write , *cmnd;
		struct stat st;
		read = (char*)malloc(sizeof(char) * 100);
		write = (char*)malloc(sizeof(char) * 100);
		cmnd = (char*)malloc(sizeof(char) * 100);
		read[0] = '\0';
		write[0] = '\0';
		cmnd[0] = '\0';

		for(i = 0; command[i] != '>' && command[i] != '<' ;i++)
		{
			cmnd[i] = command[i]; 
		}

		j = i-1;
		while(cmnd[j] == ' ' || cmnd[j] == '\t')
		{
			j--;
		}
		cmnd[j+1] ='\0';


		if(gt != -1)
		{
			if(command[gt-1] == '>')
			{
				append = 1;
			}

			j = gt + 1;
			while(command[j] == ' ' || command[j] == '\t')
			{
				j++;
			}

			for(i = j ; i < len && command[i] != '<'; i++)
			{
				write[i - j] = command[i];
			}

			k = i-j-1;
			while(write[k] == ' ' || write[k] == '\t')
			{
				k--;
			}
			write[k+1] ='\0';


		
		}

		if(lt != -1)
		{
			j = lt + 1;
			while(command[j] == ' ' || command[j] == '\t')
			{
				j++;
			}

			for(i = j ; i < len && command[i] != '>' ; i++)
			{
				read[i - j] = command[i];
			}

			k = i-j-1;
			while(read[k] == ' ' || read[k] == '\t')
			{
				k--;
			}
			read[k+1] ='\0';
		}

		// printf("%s %s %s\n",cmnd,read,write);

		if(strlen(read) == 0 && strlen(write) == 0)
		{
			printf("Please Enter a valid command\n");
			return;
		}

		if(strlen(read) != 0)
		{
			if(stat(read, &st) < 0)
			{
				fprintf(stderr, "file does not exist\n");
				return;	
			}

			fd_read = open(read , O_RDONLY);
			if(fd_read < 0)
			{
				fprintf(stderr, "error while opening the file\n");
				return;
			}

			if (dup2(fd_read, 0) < 0)
			{	
				fprintf(stderr, "Failure of dup2\n");
			}

			close(fd_read);

		}

		if(strlen(write) != 0)
		{
			if(append == 1)
			{
				fd_write = open(write, O_WRONLY|O_APPEND|O_CREAT, 0644);
			}

			else
			{
				fd_write = open(write, O_WRONLY|O_TRUNC|O_CREAT, 0644);
			}

			if (dup2(fd_write, 1) < 0)
			{	
				fprintf(stderr, "Failure of dup2\n");
			}
			close(fd_write);

		}

		parse_command(cmnd , root);
		dup2(in , 0);
		dup2(out , 1);
		close(in);
		close(out);
		return;

	}
	return;
}