#include "shell.h"

void overkill()
{
	int cnt1 =0;
	int flag =0;
	for(int j = 1 ; j< 100;j++)
	{
		if(jobs_array[j].cmnd1[0] != '\0')
		{	
			if(jobs_array[j].status == 1)
			{	
				flag = 1;
				cnt1 ++;
				kill(jobs_array[j].pid1,SIGKILL);
			}	
				
	  	}	
	    else
	    {
	    	break;
	    }    
    
	}

	if(flag == 0)
	{
		printf("There are no jobs\n");
		return;
	}
 
	return;
}