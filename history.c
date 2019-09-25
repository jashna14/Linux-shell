#include "shell.h"

struct his{
  char arr[1000];
};
struct his hist[25];
int y;
char *out_str;

void history(char *arg1 , char *arg2, int hist_cnt,int flag)
{
  if(flag == 0 && strcmp(arg1,"\n"))
  {
    strcpy(hist[hist_cnt%20].arr, arg1);
  }

  else if(!strcmp(arg1,"history") && !strcmp(arg2 ,"NULL") && flag == 1)
  {
    int lim = 0;
    int num = 10;
    if(hist_cnt-num+1 >= 0)
    {
      lim = hist_cnt-num+1;
    }
    for(int i = lim ;i<= hist_cnt;i++)
    {
      printf("%s\n",hist[i%20].arr);
    }
  }

  else if(!strcmp(arg1,"history") && strcmp(arg2 ,"NULL") && flag == 1)
  {
    int num = atoi(arg2);
    if(num > 20)
    {
      num = 20;
    }
    int lim = 0;
    if(hist_cnt-num+1 >= 0)
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

	fprintf(file,"%d\n",hist_cnt+1);
	fclose(file);
}

int retrive_history()
{
  out_str = (char*)malloc(sizeof(char)*str);
	FILE *file;
	file = fopen("history.txt","r");
	if (file == NULL) 
    { 
        return 0;
    }

    char *input = NULL;
    size_t len =0;
    int hist_cnt=0;
    int cnt =0;
    while(getline(&input,&len,file)!= -1)
    {	
    	out_str = removespace(input);
    	strcpy(hist[cnt%21].arr,out_str);
    	out_str[0] ='\0';
    	cnt++;
    }
    
  	fclose(file);
  	out_str = removespace(hist[20].arr);
  	hist_cnt = atoi(out_str);
  	remove("history.txt");

  	return hist_cnt;
}

char* up_command(int up_cnt , int hist_cnt)
{
  int num = up_cnt;
  char re[2];
  re[0] = 'x';
  re[1] = '\0';
  // printf("%d %d\n",up_cnt, hist_cnt);
  // printf("%s\n",hist[(hist_cnt - up_cnt)%20].arr);
  return hist[(hist_cnt - up_cnt)%20].arr; 
  
}
