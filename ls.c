#include "shell.h"

void ls(int l_flag,int a_flag, char *path , char *root)
{
  char final_path[str];
  if(strcmp(path,"NULL"))
  {
    if(path[0] == '~')
    {
      strcpy(final_path,root);
      int len = strlen(root);
      int len1 = strlen(path),i;
      for( i =1;i <len1;i++)
      {
        final_path[len+i-1] = path[i];
      }
      final_path[len+i-1] = '\0';
    }

    else
    {
      strcpy(final_path,path);
    }
  }
  else
  {
    strcpy(final_path,".");
  }

  final_path[1] = '\0';



  DIR *dir;
  struct stat info;
  struct dirent *file;
  struct passwd *pass;
  struct group *grp;
  dir = opendir(final_path);
  char st[1000];
  char time_string[str] = "";
  time_t now = time (NULL);
  struct tm timefl , timenow;

  if(!dir)
  {
    printf("No such directory exists\n");
    return;
  }



  if(l_flag == 0 && a_flag == 0)
  {
    int cnt =0;
    while(file = readdir(dir))
    {
      char *name = file->d_name;
      if(name[0] != '.')
      {
        cnt++;
        printf("%s   ",name);
        if(cnt%6 == 0)
        {
          printf("\n");
        }
      }

    }
    if(cnt%6 !=0)
    {
      printf("\n");
    }
  }

  else if(l_flag == 0 && a_flag == 1)
  {
    int cnt =0;
    while(file = readdir(dir))
    {
        char *name = file->d_name;
        cnt++;
        printf("%s   ",name);

        if(cnt%6 == 0)
        {
          printf("\n");
        }

    }
    if(cnt%6 !=0)
    {
      printf("\n");
    }
}

  else if(l_flag == 1 && a_flag == 0)
  {
    int cnt = 0;

    while(file = readdir(dir))
    {
      stat(file->d_name, &info);
      char *name = file->d_name;
      if(name[0] != '.')
      {
            cnt += info.st_blocks;
      }
    }
    printf("total %d\n",cnt/2);
    closedir(dir);
    dir = opendir(final_path);

    while(file = readdir(dir))
    {
      stat(file->d_name, &info);
      char *name = file->d_name;
      if(name[0] != '.')
      {
            printf((S_ISDIR(info.st_mode))  ? "d" : "-");
            printf((info.st_mode & S_IRUSR) ? "r" : "-");
            printf((info.st_mode & S_IWUSR) ? "w" : "-");
            printf((info.st_mode & S_IXUSR) ? "x" : "-");
            printf((info.st_mode & S_IRGRP) ? "r" : "-");
            printf((info.st_mode & S_IWGRP) ? "w" : "-");
            printf((info.st_mode & S_IXGRP) ? "x" : "-");
            printf((info.st_mode & S_IROTH) ? "r" : "-");
            printf((info.st_mode & S_IWOTH) ? "w" : "-");
            printf((info.st_mode & S_IXOTH) ? "x" : "-");
            printf(" ");

            printf("%ld ", info.st_nlink);
            pass = getpwuid(info.st_uid);
            grp = getgrgid(info.st_gid);
            printf("%s ",pass->pw_name);
            printf("%s ",grp->gr_name);

            printf("%10ld ", info.st_size);

            localtime_r (&info.st_mtime, &timefl);
            localtime_r (&now, &timenow);

            if(timefl.tm_year == timenow.tm_year)
            {
              strftime(time_string, str , "%b %e %H:%M", &timefl);
              printf("%s ",time_string);
            }
            else
            {
              strftime (time_string, str , "%b %e  %Y",&timefl);
              printf("%s ",time_string);
            }

            printf("%s\n",name);
      }
    }

  }

  else if(l_flag == 1 && a_flag == 1)
  {
    int cnt = 0;

    while(file = readdir(dir))
    {
      stat(file->d_name, &info);
      char *name = file->d_name;

          cnt += info.st_blocks;
    }
    printf("total %d\n",cnt/2);
    closedir(dir);
    dir = opendir(final_path);

    while(file = readdir(dir))
    {
      stat(file->d_name, &info);
      char *name = file->d_name;

          cnt += info.st_blocks;

          printf((S_ISDIR(info.st_mode))  ? "d" : "-");
          printf((info.st_mode & S_IRUSR) ? "r" : "-");
          printf((info.st_mode & S_IWUSR) ? "w" : "-");
          printf((info.st_mode & S_IXUSR) ? "x" : "-");
          printf((info.st_mode & S_IRGRP) ? "r" : "-");
          printf((info.st_mode & S_IWGRP) ? "w" : "-");
          printf((info.st_mode & S_IXGRP) ? "x" : "-");
          printf((info.st_mode & S_IROTH) ? "r" : "-");
          printf((info.st_mode & S_IWOTH) ? "w" : "-");
          printf((info.st_mode & S_IXOTH) ? "x" : "-");
          printf(" ");

          printf("%ld ", info.st_nlink);
          pass = getpwuid(info.st_uid);
          grp = getgrgid(info.st_gid);
          printf("%s ",pass->pw_name);
          printf("%s ",grp->gr_name);

          printf("%10ld ", info.st_size);

          localtime_r (&info.st_mtime, &timefl);
          localtime_r (&now, &timenow);

          if(timefl.tm_year == timenow.tm_year)
          {
            strftime(time_string, str , "%b %e %H:%M", &timefl);
            printf("%s ",time_string);
          }
          else
          {
            strftime (time_string, str , "%b %e  %Y",&timefl);
            printf("%s ",time_string);
          }

          printf("%s\n",name);

    }
  }

  else
  {
    printf("please input a correct flag for the command\n");
  }

  closedir(dir);
  return;
}
