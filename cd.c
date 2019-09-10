#include "shell.h"

void cd(char *dir , char *root)
{
  char newpath[str];
  strcpy(newpath, root);
  int len  = strlen(newpath);

  if (!strcmp(dir ,"NULL"))
  {
    chdir(root);
  }

  else if (dir[0] == '~')
  {
    int i;
    for(i =1;i<strlen(dir);i++)
    {
      newpath[len+i-1] = dir[i];
    }

    newpath[len+i-1] = '\0';
    {
      if(chdir(newpath) < 0)
      printf("No such file or directory exists\n");
    }
  }
  else
  {
    if(chdir(dir) < 0)
    {
      printf("No such file or directory exists\n");
    }
  }
  return;

}
