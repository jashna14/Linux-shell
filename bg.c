#include "shell.h"

void bg(char* id)
{
	int id1 = atoi(id);

	int cnt =0;

	for(int i=1;i<100;i++)
	{
		if(jobs_array[i].cmnd1[0] != '\0')
		{
			if(jobs_array[i].status == 1)
			{	
				cnt ++;
				if(cnt == id1)
				{
					kill(jobs_array[i].pid1 , SIGCONT);
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