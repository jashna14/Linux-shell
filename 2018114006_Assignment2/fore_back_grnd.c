 #include "shell.h"

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
    printf("%s process with pid : %d started\n",com[0],pid);
  }

}
