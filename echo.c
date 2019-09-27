#include "shell.h"

void echo(char* string)
{
  if(!strcmp(string,"NULL"))
  {
    printf("\n");
  }

  else if(!strcmp(string,"break"))
  {
    printf("\n");
  }
  else
  {
    printf("\33[2K\r%s ",string);
  }

  return;
}
