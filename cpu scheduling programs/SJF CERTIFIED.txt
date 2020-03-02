//sjf
#include<stdio.h>
#include<stdlib.h>
int n;
int cpu_ideal_time=0;
int bit[100];
struct process
{
    int pid;
    int bt;
    int at;
    int wt;
    int tat;
    int ct;
}process[100];

void compute()
{
    int i,j;

    int total=n,time=0;

    while(total)
    {
        //time++;
        int max=10000,pos=-1;

        for(i=0;i<n;i++)
        {
            if(max > bit[i] && bit[i] && time>=process[i].at)
            {
                max=bit[i];
                pos=i;
            }
        }

        if(pos==-1)
        {
            cpu_ideal_time++;
            time++;
            continue;
        }

        //bit[pos]--;
        

        
            total--;
            time=time+bit[pos];
            bit[pos]=0;
            process[pos].ct=time;
            process[pos].tat=process[pos].ct - process[pos].at;
            process[pos].wt=process[pos].tat - process[pos].bt;
        
    }
}

int main()
{
    int i,j;
    printf("enter thr no of processes \n");
    scanf("%d",&n);

    printf("enter the arrival time and brust time of each process\n");
    for(i=0;i<n;i++)
    {
        int a,b;
        scanf("%d%d",&a,&b);

        process[i].pid=i+1;
        process[i].at=a;
        process[i].bt=b;
        bit[i]=b;

    }

    compute();

    printf("process :::::::  arrival time :::::brust time :::: completion time :::  tat   :::: waiting time\n");
    {
        for(i=0;i<n;i++)
        {
        printf("%d\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n",process[i].pid,process[i].at,process[i].bt,process[i].ct,process[i].tat,process[i].wt);
        }
    }

    printf("\n cpu ideal time is %d\n",cpu_ideal_time);
    printf("Number of context switching is %d",n-1);

    return 0;

}