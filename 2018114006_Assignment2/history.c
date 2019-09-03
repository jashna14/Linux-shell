#include "shell.h"

struct his{
  char arr[1000];
};
struct his hist[25];
int y;
char out_str[str];

void removespace1(char* string)
{
  int len = strlen(string),i,j,k;
  for(i=0;i<len;i++)
  {
    if(string[i]!=' ')
    {
      break;
    }
  }

  for(j=len-1;j>=0;j--)
  {
    if(string[j] != ' ' && string[j] != '\n')
    {
      break;
    }
  }
  int cnt =0 ;
  for(k=i;k<=j;k++)
  {
    out_str[cnt++] = string[k];
  }

  out_str[j+1] = '\0';
}

void history(char *arg1 , char *arg2, int hist_cnt)
{
  if(strcmp(arg1,"history") && !strcmp(arg2 ,"NULL"))
  {
    strcpy(hist[hist_cnt%20].arr, arg1);
  }

  else if(!strcmp(arg1,"history") && !strcmp(arg2 ,"NULL"))
  {
    strcpy(hist[hist_cnt%20].arr, arg1);
    int lim = 0;
    int num = 10;
    if(hist_cnt-num+1 > 0)
    {
      lim = hist_cnt-num+1;
    }
    for(int i = lim ;i<= hist_cnt;i++)
    {
      printf("%s\n",hist[i%20].arr);
    }
  }

  else if(!strcmp(arg1,"history") && strcmp(arg2 ,"NULL"))
  {
    strcpy(hist[hist_cnt%20].arr, arg1);
    int num = atoi(arg2);
    int lim = 0;
    if(hist_cnt-num+1 > 0)
    {
      lim = hist_cnt-num+1;
    }

    for(int i = lim ;i<= hist_cnt;i++)
    {
      printf("%s\n",hist[i%20].arr);
    }
  }
  return;
}

void save_history(int hist_cnt)
{
	FILE *file;
	file = fopen("history.txt","ab+");

	for(int i=0;i<20;i++)
	{
		fprintf(file,"%s\n",hist[i].arr);
	}

	// fwrite(&hist_cnt,sizeof(hist_cnt),1,file);
	fprintf(file,"%d\n",hist_cnt+1);
	fclose(file);
}

int retrive_history()
{
	FILE *file;
	file = fopen("history.txt","r");
	if (file == NULL) 
    { 
        return 0;
        exit (1); 
    }

    char *input = NULL;
    size_t len =0;
    int hist_cnt=0;
    int cnt =0;
    while(getline(&input,&len,file)!= -1)
    {	
    	removespace1(input);
    	strcpy(hist[cnt%21].arr,out_str);
    	out_str[0] ='\0';
    	cnt++;
    }
    
  	fclose(file);
  	removespace1(hist[20].arr);
  	hist_cnt = atoi(out_str);
  	remove("history.txt");

  	return hist_cnt;
}

