#include "shell.h"
char *input_str , *output_str , *removespace_output_str;
size_t st = 1000000;

// int hist_cnt;

// void histt(int cn)
// {
// 	hist_cnt = cn;
// }

char* removespace(char* string)
{
  removespace_output_str = (char*)malloc(sizeof(char)*st);
  int len = strlen(string),i,j,k;
  for(i=0;i<len;i++)
  {
    if(string[i]!=' ' && string[i] != '\t')
    {
      break;
    }
  }

  for(j=len-1;j>=0;j--)
  {
    if(string[j] != ' ' && string[j] != '\n' && string[j] != '\t')
    {
      break;
    }
  }
  int cnt =0 ;
  for(k=i;k<=j;k++)
  {
    removespace_output_str[cnt++] = string[k];
  }

  removespace_output_str[j+1] = '\0';

  return removespace_output_str;
}

// void parse_command(char *command , char *root)
// {
//   char *token1 = strtok(command," ");

//   	while(token1 != NULL)
//   	{
// 	    if(strcmp(token1,"history"))
// 	    {
// 	      history(token1,"NULL", hist_cnt);
// 	      hist_cnt++;
// 	    }


// 	    if(!strcmp(token1,"pwd"))
// 	    {
// 	      pwd();
// 	      return;
// 	    }

// 	    else if(!strcmp(token1,"history"))
// 	    {
// 	      token1 = strtok(NULL, " ");
// 	      if(token1 == NULL)
// 	      {
// 	        token1 = "NULL";
// 	      }
// 	      history("history",token1 ,hist_cnt);
// 	      hist_cnt++;
// 	      return;
// 	    }

// 	    else if(!strcmp(token1,"cd"))
// 	    {
// 	      token1 = strtok(NULL, " ");
// 	      if(token1 == NULL || !strcmp(token1,"&"))
// 	      {
// 	        token1 = "NULL";
// 	      }
// 	      cd(token1 , root);
	      
// 	      return;

// 	    }

// 	    else if(!strcmp(token1,"echo"))
// 	    {
// 	      token1 = strtok(NULL, " ");
// 	      if(token1 == NULL)
// 	      {
// 	        token1 = "NULL";
// 	        echo(token1);
// 	      }
// 	      // printf("%s %s\n",token1 , root);
// 	      else
// 	      {
// 	        while(token1 != NULL && strcmp(token1,"&"))
// 	        {
// 	          echo(token1);
// 	          token1 = strtok(NULL," ");
// 	        }

// 	        echo("break");
// 	      }

// 	      return;
// 	    }


// 	    else if(!strcmp(token1,"ls"))
// 	    {
// 	      token1 = strtok(NULL," ");
// 	      int l_flag = 0;
// 	      int a_flag = 0;
// 	      char path[str];
// 	      strcpy(path,"NULL");

// 	      while(token1 != NULL)
// 	      {
// 	        if(token1[0] == '-')
// 	        {
// 	          int token_len = strlen(token1);
// 	          for(int i=1;i<token_len;i++)
// 	          {
// 	            if(token1[i] == 'l')
// 	            {
// 	              l_flag = 1;
// 	            }
// 	            else if(token1[i] == 'a')
// 	            {
// 	              a_flag = 1;
// 	            }
// 	          }
// 	        }
// 	        else if(strcmp(token1,"&"))
// 	        {
// 	          strcpy(path,token1);
// 	        }

// 	        token1 = strtok(NULL, " ");
// 	      }
// 	      ls(l_flag,a_flag,path,root);

// 	      return;
// 	    }

// 	    else if(!strcmp(token1,"pinfo"))
// 	    {
// 	      token1 = strtok(NULL, " ");
// 	      if(token1 == NULL || !strcmp(token1,"&"))
// 	      {
// 	        token1 = "NULL";
// 	      }
// 	      pinfo(token1,root);
// 	      return;
// 	    }

// 	    else if(!strcmp(token1,"quit") || !strcmp(token1,"q") || !strcmp(token1,"exit"))
// 	    {
// 	      save_history(hist_cnt-1);
// 	      exit(0);
// 	      return;
// 	    }

// 	    else
// 	    {
// 	      char *com[1000];

// 	      for(int i=0;i<1000;i++)
// 	      {
// 	        com[i] = (char*)malloc(sizeof(char)*1000);
// 	      }

// 	      int and_flag = 0;
// 	      int cnt1 =0;
// 	      while(token1 != NULL)
// 	      {
// 	        if(strcmp(token1,"&"))
// 	        {
// 	          strcpy(com[cnt1],token1);
// 	          cnt1++;
// 	        }
// 	        else
// 	        {
// 	          and_flag=1;
// 	        }

// 	        token1 = strtok(NULL, " ");
// 	      }
// 	       com[cnt1] = NULL;
// 	       fore_back_grnd(com,and_flag,cnt1);
// 	       return;

// 	    }

//   	}

//   return;
// }


int input(char *root)
{	
    input_str = (char*)malloc(sizeof(char)*st);
    output_str = (char*)malloc(sizeof(char)*st);

    getline(&input_str , &st , stdin);
    output_str = removespace(input_str);

    char *token = strtok(output_str , ";");
    char *com;
    struct com{
      char arr[1000];
    };
    struct com tokens[100];
    int i=0;

    while (token != NULL)
    {
        strcpy(tokens[i++].arr,token);
        token = strtok(NULL, ";");
    }

    for(int j=0;j<i;j++)
    {
    	piping(tokens[j].arr , root);
    }

}
