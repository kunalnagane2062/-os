#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
int min(int arr[],int n)
{
    int min=0;
    int min_index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]<min)
        {
            min=arr[i];
            min_index=i;
        }
    }
    return min_index;
}
int max(int arr[],int n)
{
    int max=0;
    int max_index=0;
    for(int i=0;i<n;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
            max_index=i;
        }
    }
    return max_index;
}
void sjf(int arr[],int at[],int burst[],int * completion_time,int x)
{
    int m=32646;
    int t_time=min(at,x);
    int t_burst=0;
    int p_t=x;
    for(int i=0;i<x;i++)
    {
        t_burst=t_burst+burst[i];
    }
    while(t_time<t_burst )
    {
        int min=INT_MAX;
        int min_index=0;
        for(int i=0;i<x;i++)
        {
            if(at[i]<=t_time && burst[i]<min && burst[i]>0)
            {
                min=burst[i];
                min_index=i;
            }
        }
        burst[min_index]--;
        t_time++;
        completion_time[min_index]=t_time;
    }
}
int main()
{
    int n;
    printf("Enter the number of processes");
    scanf("%d",&n);
    int arr[n];
    int at[n];
    int burst[n];
    int burst1[n];
    int turn_around_time[n];
    int waiting_time[n];
    int completion_time[n];
    double tat=0;
    double wat=0;
    printf("Enter the array of processes\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the array of arrival times\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&at[i]);
    }
    printf("Enter the array of burst times\n");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&burst[i]);
    }
    for(int i=0;i<n;i++)
    {
        burst1[i]=burst[i];
    }
    sjf(arr,at,burst,completion_time,n);
    for(int i=0;i<n;i++)
    {
        int p=completion_time[i]-at[i];
        turn_around_time[i]=p;
    }
    for(int i=0;i<n;i++)
    {
      waiting_time[i]=turn_around_time[i]-burst1[i];
    }
    printf("Process          Arrival        Burst        Completion         Turnaround         Waiting");
    printf("\n");
    for(int i=0;i<n;i++)
    {
        printf("%d",arr[i]);
        printf("                  ");
        printf("%d",at[i]);
        printf("                ");
        printf("%d",burst1[i]);
        printf("                ");
        printf("%d",completion_time[i]);
        printf("               ");
        printf("%d",turn_around_time[i]);
        printf("                ");
        printf("%d",waiting_time[i]);
        printf("\n");
    }
    for(int i=0;i<n;i++)
    {
        tat=tat+turn_around_time[i];
        wat=wat+waiting_time[i];
    }
     printf("Average turnaround time is:");
    printf("%f",tat/n);
    printf("\n");
    printf("Average waiting time is:");
    printf("%f",wat/n);
    return 0;
}
