#include <unistd.h>
#include<stdio.h>
#include<stdlib.h>
#define n 5
int no[n];
void sort(void)
{
 int i,j,temp;
 for(i=0;i<5;i++)
 {
 for(j=i+1;j<5;j++)
 {
 if(no[i]>no[j])
 {
 temp=no[i];
 no[i]=no[j];
 no[j]=temp; 
 }
 }
 }
}
void sort1(void)
{
 int i,j,temp;
 for(i=0;i<5;i++)
 {
 for(j=i+1;j<5;j++)
 {
 if(no[i]<no[j])
 {
 temp=no[i];
 no[i]=no[j];
 no[j]=temp; 
 }
 }
 }
}
void xyz()
{
if(fork()==0)
{
printf("\nChild Process is Executing\n");
sort();
printf("The array after sorting by child is\n");
int j;
for(j=0;j<5;j++)
{
printf("%d",no[j]);
printf(" ");
}
printf("\n");
}
else{
int status =0;
printf("\nParent Process is Executing\n");
sort1();
printf("The array after sorting by parent is\n");
int j;
for(j=0;j<5;j++)
{
printf("%d",no[j]);
printf(" ");
}
printf("\n");
}
}
void orphan()
{
if(fork()==0)
{
printf("In child process\n");
sleep(5);
printf("Child Process ID: %d\n", getpid());
printf("Parent Process ID: %d\n", getppid());
printf("Child process is orphan now\n");
printf("Parent Process ID: %d\n", getppid());
printf("Child process completed\n");
}
else
{
printf("In parent Process\n");
printf("Parent Process ID: %d\n", getpid());
printf("Parent Process completed\n");
}
}
void zombie()
{
if(fork()==0)
{
printf("In child process\n");
printf("Child process completed\n");
printf("Child Process ID: %d\n", getpid());
printf("Parent Process ID: %d\n", getppid());
printf("Child process is zombie now\n");
}
else
{
printf("In parent Process\n");
sleep(4);
printf("Parent Process ID: %d\n", getpid());
printf("Parent Process completed\n");
}
}
int main(void)
{
printf("Enter the 5 elements\n");
for(int i=0;i<n;i++)
 scanf("%d",&no[i]);
printf("The array before sorting is\n");
int i;
for(i=0;i<5;i++)
{
printf("%d",no[i]);
printf(" ");
}
int k;
do
{
printf("\nEnter your choice \n 1)Child-Parent demo \n 2)Orphan Process \n 
3)Zombie Process");
int choice;
scanf("%d",&choice);
if(choice==1)
{
xyz();
}
else if(choice==2)
{
orphan();
}
else if(choice==3)
{
zombie();
}
else
{
break;
}
printf("\nDo you want exit 1)Continue 2)Exit\n");
scanf("%d",&k);
} while(k==1); 
return 0;
}
