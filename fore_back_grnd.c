 #include "shell.h"

// int proc_cnt;
job jobs_array[100];		
void fore_back_grnd(char ** com,int and_flag , int cnt)
{

  int pid,status;
  pid = fork();

  if(pid < 0)
  {
  	perror("check");
  	return;
  }

  if(pid == 0)
  {

    if(execvp(com[0],com) == -1)
    {
      printf("Please enter a valid command\n");
    }
    exit(0);
  }
  else if(pid > 0 && and_flag == 0)
  {
    waitpid(pid,&status, WUNTRACED);
  }

  else if(pid < 0)
  {
    printf("error forking\n");
  }

  else
  {

  	int k;
  	char comm[str];
  	for(k=1;k<100;k++)
  	{
  		if(jobs_array[k].cmnd1[0] == '\0')
  		{	
		  	jobs_array[k].pid1 = pid;
		  	jobs_array[k].status = 1;
		  	
		  	for(int j = 0 ;j <cnt;j++)
		  	{
		  		strcat(comm,com[j]);
		  		if(j!=cnt -1)
		  			strcat(comm," ");
		  	}

		  	strcpy(jobs_array[k].cmnd1,comm);
		  	break;
		}	
	}  	

    printf("%s process with pid : %d started\n",comm,pid);
  	comm[0] = '\0';

  }

  return;

}
