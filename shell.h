#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <pwd.h>
#include <sys/stat.h>
#include <sys/utsname.h>
#include <fcntl.h>
#include <signal.h>
#include <dirent.h>
#include <time.h>
#include <locale.h>
#include <langinfo.h>
#include <grp.h>
#include <signal.h>
#include <inttypes.h>

typedef struct{
	int pid1;
	int status;
	char cmnd1[1000];
}job;

extern job jobs_array[100];
extern int foregrnd_pid;
extern char* user;
extern char* host;
extern char* dir_shell;

extern void display();
extern int input();
extern void ls();
extern void pwd();
extern void cd();
extern void echo();
extern void pinfo();
extern void history();
extern void fore_back_grnd();
extern void save_history();
extern int retrive_history();
extern void histt();
extern void histt1();
extern char* removespace();
extern void piping();
extern void redirection();
extern void jobs();
extern void kjobs();
extern void bg();
extern void fg();
extern void parse_command();
extern void setenvo();
extern void unsetenvo();
extern void overkill();
extern char* up_command();
extern void cronjob();

#define str (int) 1000000
#define clear() printf("\033[H\033[J")
