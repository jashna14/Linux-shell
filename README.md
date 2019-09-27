

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
    * parse_command.c - handles parsing of commands
    * history.c - history command
    * piping.c - handles piping
    * redirection.c - handles redirection
    * setenv.c - setenv command
    * unsetenv.c - unsetenv command
    * jobs.c - job command
    * kjobs.c - kjob command
    * fg.c - fg command
    * bg.c - bg command
    * overkill.c - overkill command
    * cronjob.c - cronjob command

### Functioning
    * cd <directory path>       - Changes directory to the given path. Changes to shell home if no directory is provided
    * pwd               - Shows the absolute path of the current working directory 
    * echo              - Prints the message to the terminal. Handled single and double quotes.
    * ls <al> <directory path>  - Handles all variations of ls with a and l flags and directory path
    * pinfo <pid>           - Prints process related info (pid, Process Status {R, S, S+, Z}, memory and Executable Path) about given pid. Prints process related info of shell program if no pid is provided
    * quit              - Exits the shell	
    * history <n>           - Prints history of n (max 20) commands. Prints history of maximum 10 commands if n is not provided
    * setenv var [value]   - creates the environment variable "var"
    *                        sets its value to "value"
    * unsetenv var          - unsets the value of the environment 
    *                          variable "var"
    * jobs                   - prints a list of all currently running jobs along with their job ids , pid, in particular,
                               background jobs, in order of their creation along with their state – Running or
                               Stopped.
    * ​kjob <jobNumber> <signalNumber>  - takes the job id of a running job and sends a signal value to that process
    * ​fg <jobNumber> ​        - brings a running or a stopped background job with given job number to foreground
    * ​bg <jobNumber> ​        - changes a stopped background job to a running background
    * ​overkill               - kills all background process at once
    * quit ​                  - exits the shell
    * CTRL-Z ​                - changes the status of currently running job to stop, and push it
                               in background process.
    * CTRL-C ​                - causes a SIGINT signal to be sent to the current foreground job
                               of the shell​ . If there is no foreground job, then the signal has no effect.
    * cronjob -c [command] -p <total time> -t <interval time>   -  runs the command( in [] ) 
    *                                                               after every time interval for total time.
    *  UP key recall         -  press the up key k no. of times and then press enter , the kth reccent command will display and run.  
                                                                                                                     
    * All other commands are implemented using execvp
    * Background Processing (can be run with '&') is handled for commands executed through execvp
