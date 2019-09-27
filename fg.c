#include "shell.h"

void fg(char* id)
{
	int id1 = atoi(id);

	int cnt =0,status;

	for(int i=1;i<100;i++)
	{
		if(jobs_array[i].cmnd1[0] != '\0')
		{
			if(jobs_array[i].status == 1)
			{	
				cnt ++;
				if(cnt == id1)
				{
					printf("%s\n",jobs_array[i].cmnd1);
					foregrnd_pid = jobs_array[i].pid1;
					kill(jobs_array[i].pid1 , SIGCONT);
					waitpid(jobs_array[i].pid1, &status, WUNTRACED);
					if(!WIFSTOPPED(status))
						jobs_array[i].status = 0;
					return;
				}
			}	
		}
		else
		{
			break;
		}

	}

	printf("There is no job with the given job_id\n");

	return;
	

}