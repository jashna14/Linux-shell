#include "shell.h"
char *input_str , *output_str , *removespace_output_str;
size_t st = 1000000;

int hist_cnt;

void histt(int cn)
{
	hist_cnt = cn;
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

    history(output_str,"NULL", hist_cnt ,0);
    hist_cnt++;
    histt1(hist_cnt);

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
