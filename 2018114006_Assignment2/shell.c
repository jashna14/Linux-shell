#include "shell.h"

int main( int argc, char * argv[])
{

  int len = strlen(argv[0]);
  int i;
  char temp1_path[str]; // path from actual root to from where the ./a.out is called
  getcwd(temp1_path , str-1);
  temp1_path[str-1] = '\0';

  for(i =len-1 ;i >=0 ;i--)
  {
    if(argv[0][i] == '/')
    {
      break;
    }
  }
  argv[0][i] = '\0';

  char temp_path[str];
  strcpy(temp_path,argv[0]); //path from where the ./a.out was called to where a.out actually exists
  chdir(argv[0]);

  char root[str];     // root contains the path to a.out from actual root
  getcwd(root , str-1);
  root[str-1] = '\0';

  chdir(temp1_path);
  int cnt2 = 0;
  cnt2 = retrive_history();
  histt(cnt2);

  while(1)
  {
		int pid, status;
		if((pid = waitpid(-1, &status, WNOHANG | WUNTRACED)) > 0)
		{
			if (WIFEXITED(status))
			{	
				printf("pid: %d exited normally\n",pid);	
			}
								
		}

    display(root);
  	signal(SIGINT, SIG_IGN);
  	input(root);

  }
}
