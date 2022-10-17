# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include<sys/types.h>
# include <sys/wait.h>
void perror(const char * s);
void sort(int arr[],int n)
{
 int i,j,temp;
 for(i=0;i<n;i++)
 {
 for(j=i+1;j<n;j++)
 {
 if(arr[i] > arr[j])
 {
 temp=arr[i];
 arr[i]=arr[j];
 arr[j]=temp; 
 }
 }
 }
}
int main(int argc, char *argv[])
{
int n;
printf("Enter the number of elements\n");
scanf("%d",&n);
int arr[n];
printf("Enter the elements:\n");
for(int i=0;i<n;i++)
{
scanf("%d",&arr[i]);
}
printf("The array before sorting is:\n");
for(int i=0;i<n;i++)
{
printf("%d",arr[i]);
}
printf("\n");
int k=fork();
if(k==0)
{
printf("\nInside the child process\n");
sort(arr,n);
printf("The array after sorting is:\n");
for(int i=0;i<n;i++)
{
printf("%d",arr[i]);
}
printf("\n");
char *newargv[n+2] ;
for(int i=0;i<=n;i++)
{
newargv[i]=(char *)malloc(5*sizeof(char));
sprintf(newargv[i],"%d",arr[i]);
}
newargv[n+1]=NULL;
char *newenviron[] = { NULL };
execve("./myecho.o",newargv,newenviron);
printf("Hi");
}
else if(k>0)
{
printf("Inside the parent Process\n");
wait(NULL);
printf("\nParent Process is completed\n");
}
}
