#include "shell.h"

char *user , *host , *dir_present , *dir_shell;


void display(char *root)
{
    host = (char*)malloc(sizeof(char)*str);
    user = (char*)malloc(sizeof(char)*str);
    dir_shell = (char*)malloc(sizeof(char)*str);
    dir_present = (char*)malloc(sizeof(char)*str);


    user = getenv("USER");
    gethostname(host, str-1);
    host[str-1] = '\0';
    getcwd(dir_present , str-1);
    int cnt=0;

    if(strlen(dir_present) < strlen(root))
    {
      dir_shell = dir_present;
    }

    else
    {
      int fl  = 0;
      for(int i=0;i<strlen(root);i++)
      {
        if(root[i] != dir_present[i])
        {
          fl =1;
        }
      }

      if(fl == 1)
      {
        dir_shell = dir_present;
      }
      else
      {
        dir_shell[cnt++] = '~';
        for(int i=0;i<strlen(dir_present);i++)
        {
          if(root[i] != dir_present[i])
          {
            dir_shell[cnt++] = dir_present[i];
          }
        }
      }
    }

    printf("\033[1;31m");
    printf("%s@%s :" , user , host);
    printf("\033[0m");

    printf("\033[0;32m");
    printf(" %s > " ,dir_shell);
    printf("\033[0m");


}
