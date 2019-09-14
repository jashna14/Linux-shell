#include "shell.h"

int hist_cnt1;

void histt1(int cn)
{
	hist_cnt1 = cn;
}

void parse_command(char *command , char *root)
{
  char *token1 = strtok(command," ");

  	while(token1 != NULL)
  	{

	    if(!strcmp(token1,"pwd"))
	    {
	      pwd();
	      return;
	    }

	    else if(!strcmp(token1,"history"))
	    {
	      token1 = strtok(NULL, " ");
	      if(token1 == NULL)
	      {
	        token1 = "NULL";
	      }
	      history("history",token1 ,hist_cnt1-1,1);
	      return;
	    }

	    else if(!strcmp(token1,"cd"))
	    {
	      token1 = strtok(NULL, " ");
	      if(token1 == NULL || !strcmp(token1,"&"))
	      {
	        token1 = "NULL";
	      }
	      cd(token1 , root);
	      
	      return;

	    }

	    else if(!strcmp(token1,"echo"))
	    {
	      token1 = strtok(NULL, " ");
	      if(token1 == NULL)
	      {
	        token1 = "NULL";
	        echo(token1);
	      }

	      else
	      {
	        while(token1 != NULL && strcmp(token1,"&"))
	        {
	          echo(token1);
	          token1 = strtok(NULL," ");
	        }

	        echo("break");
	      }

	      return;
	    }


	    else if(!strcmp(token1,"ls"))
	    {
	      token1 = strtok(NULL," ");
	      int l_flag = 0;
	      int a_flag = 0;
	      char path[str];
	      strcpy(path,"NULL");

	      while(token1 != NULL)
	      {
	        if(token1[0] == '-')
	        {
	          int token_len = strlen(token1);
	          for(int i=1;i<token_len;i++)
	          {
	            if(token1[i] == 'l')
	            {
	              l_flag = 1;
	            }
	            else if(token1[i] == 'a')
	            {
	              a_flag = 1;
	            }
	          }
	        }
	        else if(strcmp(token1,"&"))
	        {
	          strcpy(path,token1);
	        }

	        token1 = strtok(NULL, " ");
	      }
	      ls(l_flag,a_flag,path,root);

	      return;
	    }

	    else if(!strcmp(token1,"pinfo"))
	    {
	      token1 = strtok(NULL, " ");
	      if(token1 == NULL || !strcmp(token1,"&"))
	      {
	        token1 = "NULL";
	      }
	      pinfo(token1,root);
	      return;
	    }

	    else if(!strcmp(token1,"quit") || !strcmp(token1,"q") || !strcmp(token1,"exit"))
	    {
	      save_history(hist_cnt1-1);
	      exit(0);
	      return;
	    }


	    else if(!strcmp(token1,"setenv"))
	    {
	      token1 = strtok(NULL, " ");

	      if(token1 == NULL || !strcmp(token1,"&"))
	      {
	        token1 = "NULL";
	      }

	      setenvo(token1);
	      return;

	    }

	    else if(!strcmp(token1,"unsetenv"))
	    {
	      token1 = strtok(NULL, " ");

	      if(token1 == NULL || !strcmp(token1,"&"))
	      {
	        token1 = "NULL";
	      }

	      unsetenvo(token1);
	      return;

	    }


	    else
	    {
	      char *com[1000];

	      for(int i=0;i<1000;i++)
	      {
	        com[i] = (char*)malloc(sizeof(char)*1000);
	      }

	      int and_flag = 0;
	      int cnt1 =0;
	      while(token1 != NULL)
	      {
	        if(strcmp(token1,"&"))
	        {
	          strcpy(com[cnt1],token1);
	          cnt1++;
	        }
	        else
	        {
	          and_flag=1;
	        }

	        token1 = strtok(NULL, " ");
	      }
	       com[cnt1] = NULL;
	       fore_back_grnd(com,and_flag,cnt1);
	       return;

	    }

  	}

  return;
}