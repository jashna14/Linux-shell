#include "shell.h"
char *input_str , *output_str , *removespace_output_str;
size_t st = 1000000;

int hist_cnt;

void histt(int cn)
{
	hist_cnt = cn;
}

void evaluate(char *root)
{
	if(output_str[0] != '\0')
    {
	    history(output_str,"NULL", hist_cnt ,0);
    	hist_cnt++;
    	histt1(hist_cnt);
    }	

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


int input(char *root)
{	
    input_str = (char*)malloc(sizeof(char)*st);
    output_str = (char*)malloc(sizeof(char)*st);

    getline(&input_str , &st , stdin);
    output_str = removespace(input_str);
    if(output_str[0] == '\33')
    {	
	    int cnt_up = 0;
    	int len_up = strlen(output_str);
    	int i = 0  , flag = 1;
    	while(i<len_up)
    	{
    		if(output_str[i] == '\33' && output_str[i+1] == '[' && output_str[i+2] == 'A')
    		{
    			cnt_up++;
    			i += 3;
    		}
    		else
    		{
    			flag = 0;
    			break;
    		}
    	}

    	if(flag == 1)
    	{
    		if(cnt_up > 20 || hist_cnt-cnt_up < 0)
    		{
    			printf("Invalid no. of commands in history\n");
    		}
    		else
    		{
	    		char up_cmnd[str];
	    		strcpy(up_cmnd, up_command(cnt_up , hist_cnt));
	    		output_str[0] = '\0';
	    		output_str = removespace(up_cmnd);
	    		printf("\033[1;31m");
    			printf("%s@%s :" , user , host);
			    printf("\033[0m");

			    printf("\033[0;32m");
			    printf(" %s > " ,dir_shell);
			    printf("\033[0m");

			    printf("%s\n",output_str);
	    	}	
    	}
    }	

    evaluate(root);

}