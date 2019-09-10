#include "shell.h"
char path[str] , pid[str] , ex_pathh[str] , ex_path[str] , proc_status[str], proc_memory[str], file[str];

void pinfo(char *id, char * root)
{
  int idd;
  if(!strcmp(id,"NULL"))
  {
    idd = getpid();
    sprintf(pid,"%d",idd);
  }
  else
  {
    strcpy(pid,id);
  }

  strcpy(path,"/proc/");
  strcat(path,pid);
  strcpy(ex_pathh, path);
  strcat(path,"/stat");
  strcat(ex_pathh, "/exe");

  int fd = open(path,O_RDONLY);
  read(fd, file, str);
  if(fd > 0)
  {
    printf("pid -- %s\n",pid);

    char *token  = strtok(file, " ");
    int cnt = 1;
    while(token != NULL)
    {
      if(cnt == 3)
      {
        strcpy(proc_status, token);
      }
      if(cnt == 23)
      {
        strcpy(proc_memory, token);
      }
      cnt++;
      token = strtok(NULL , " ");
    }
    printf("Process Status -- {%s}\n",proc_status);
    printf("memory ​ -- %s\n",proc_memory);
  
    char ans[str];
    realpath(ex_pathh,ex_path);
    if(strstr(ex_path,root) != NULL)
    {
    	strcpy(ans,"~");
    	strcat(ans,&ex_path[strlen(root)]);
    	printf("%s\n",ans );
    }
    else
    {
    	printf("Executable Path -- %s\n",ex_path);
    }	
  //
  //
  }
}
