#include "shell.h"
char *pwd_dir;
void pwd()
{
  pwd_dir = (char*)malloc(sizeof(char)*str);

  getcwd(pwd_dir , str-1);
  printf("%s\n",pwd_dir);

  return;
}
