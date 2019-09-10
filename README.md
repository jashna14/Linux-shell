

# Computer Systems Engineering-1 
## Assignment 2

**Jashn Arora**
**2018114006**

## my shell

### Usage



### Files
    * shell.c    - contains the main functioning of the shell
    * input.c    - contains the code for analysing the input
    * shell.h     - contains all the required headers and functions
    * display.c  - to display the prompt to user
    * cd.c      - cd command
    * pinfo.c   - pinfo command
    * echo.c    - echo command
    * pwd.c     - pwd command
    * ls.c      - ls command
    * fore_back_grnd.c   - handling background and foreground processes for commands which are executed through execvp
    * history.c - history command

### Functioning
    * cd <directory path>       - Changes directory to the given path. Changes to shell home if no directory is provided
    * pwd               - Shows the absolute path of the current working directory 
    * echo              - Prints the message to the terminal. Handled single and double quotes.
    * ls [al] <directory path>  - Handles all variations of ls with a and l flags and directory path
    * pinfo [pid]           - Prints process related info (pid, Process Status {R, S, S+, Z}, memory and Executable Path) about given pid. Prints process related info of shell program if no pid is provided
    * exit , q , quit              - Exits the shell	
    * history [n]           - Prints history of n (max 20) commands. Prints history of maximum 10 commands if n is not provided
    * All other commands are implemented using execvp. 
    * Background Processing (can be run with '&') is handled for commands executed through execvp
