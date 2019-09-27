#include "shell.h"
char *pwd_dir;
void pwd()
{
  pwd_dir = (char*)malloc(sizeof(char)*str);

  getcwd(pwd_dir , str-1);
  printf("\33[2K\r%s\n",pwd_dir);
  fflush( stdout );


  return;
}
