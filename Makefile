all:
	gcc -g shell.h shell.c cd.c pwd.c input.c display.c echo.c ls.c pinfo.c history.c fore_back_grnd.c redirection.c piping.c parse_command.c setenv.c unsetenv.c jobs.c kjobs.c bg.c  overkill.c -o shell
compile: