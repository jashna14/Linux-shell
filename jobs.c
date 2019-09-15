#include "shell.h"

void jobs()
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
				char file[str];
				char path[100];
				path[0] = '\0';
				char pidd[10];
				sprintf(pidd, "%d", jobs_array[j].pid1);
				strcat(path,"/proc/");
				strcat(path,pidd);
				strcat(path,"/stat");
	            int fd = open(path,O_RDONLY);
			  	read(fd, file, str);
			  	if(fd > 0)
			  	{
				    char *token  = strtok(file, " ");
				    int cnt = 1;
				    while(token != NULL)
			    	{
				      	if(cnt == 3)
				      	{
				      		if(!strcmp(token,"T"))
								printf("[%d] %s %s [%d]\n",cnt1, "Stopped" , jobs_array[j].cmnd1 , jobs_array[j].pid1);
			    			else
								printf("[%d] %s %s [%d]\n",cnt1, "Running" , jobs_array[j].cmnd1 , jobs_array[j].pid1);

			    			break;
				      	}
				      	cnt++;
				      	token = strtok(NULL , " ");
			    	}
		  		}
		  		path[0] = '\0';
		  		file[0] = '\0';
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