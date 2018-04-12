#include<stdio.h> 
struct Project
{
	int processno;
	int arrivalT;
	int burstT;
};
int main() 
{
	int i,j,min,no_of_process;
	int count=0,t=3,flag=0,t_Quanta=10;;
	float total_wait_time=0,total_turnaround_time=0;
	float average_waiting_time,average_turnaround_time;
	printf("\nEnter Total Number of Processes:\t\n");
	scanf("%d",&no_of_process);
	struct Project p[no_of_process];
	struct Project  temp;
	int burst_time[no_of_process],wait_T[no_of_process],turn_T[no_of_process]; 
	printf("\n\nEnter Details of %d Processes\n\n\n",no_of_process);
	for(i=0;i<no_of_process;i++)
	{
		printf("Enter the name of process: \t");
		scanf("%d",&p[i].processno);
		printf("Enter Arrival Time:\t");
		scanf("%d",&p[i].arrivalT);
		printf("Enter Burst Time:  \t");
		scanf("%d",&p[i].burstT);
		burst_time[i]=p[i].burstT; 
		printf("\n\n");
		
	}
	int temp2;
	for(i=0;i<no_of_process;i++)
    {
        for(j=i;j<no_of_process-1;j++)
        {
            if(p[j].burstT>p[j+1].burstT)
            {
            	 temp=p[j+1];
                 p[j+1]=p[j];
                 p[j]=temp;
                 temp2=burst_time[j+1];
                 burst_time[j+1]=burst_time[j];
                 burst_time[j]=temp2;
            }
        }
       
    }

    printf("\n\nPROCESS NO\t\tArrival Time\t\t\tBurst Time\t\n");
    for(i=0;i<=no_of_process-1;i++)
    {
    printf("%d                \t\t%d       \t\t%d   \n\n",p[i].processno,p[i].arrivalT,p[i].burstT);
    }
    min=p[0].arrivalT;
    for(i=1;i<no_of_process;i++)
    {
    	if(p[i].arrivalT<min)
    		min=p[i].arrivalT;
	}
	if(min>3)
	{
		t=min;
	}
	printf("\n\n");
	printf("Process\t|TurnAround-time|Waiting-time\t\n");
	for(i=0;count!=no_of_process;i++)
	{
		if(p[i].arrivalT<=t && p[i].burstT<=t_Quanta && p[i].burstT>0)
		{
		  t+=p[i].burstT;
		  p[i].burstT=0;
		  flag=1;
		}
		else if(p[i].arrivalT<=t && p[i].burstT>0)
		{
			p[i].burstT-=t_Quanta;
			t+=t_Quanta;
		}
		if(p[i].burstT==0 && flag==1)
		{
				count++;
				turn_T[i]=t-p[i].arrivalT;
				wait_T[i]=t-p[i].arrivalT-burst_time[i];
				printf("P[%d]\t|\t%d\t|\t%d\n",p[i].processno,turn_T[i],wait_T[i]);
				flag=0;
		}
		if((i+1)==no_of_process)
			i=-1;
	}
	printf("\n---------------------------------------------------------------------------------------------\n");
	for(i=0;i<no_of_process;i++)
	{
		total_wait_time+=wait_T[i];
		total_turnaround_time+=turn_T[i];
	}
	printf("\nAverage Waiting Time= %f\n",total_wait_time*1.0/no_of_process); 
	printf("\n\n");
    printf("Averageg Turnaround Time = %f",total_turnaround_time*1.0/no_of_process);  
    printf("\n");
}
