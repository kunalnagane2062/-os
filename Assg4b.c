#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
pthread_mutex_t lock;
sem_t wrt;
int readerCount=0;
int d=0;
void * reader(void * threadid)
{
 pthread_mutex_lock(&lock);
 readerCount++;
 if(readerCount>0 && d>0)
 {
 printf("\nReader has to wait since writer is Writing\n");
 sem_wait(&wrt);
 }
 pthread_mutex_unlock(&lock);
 sleep(2);
 printf("\nReader is Reading!!!\n");
 pthread_mutex_lock(&lock);
 readerCount--;
 if(readerCount==0 && d==0)
 {
 printf("\nWriter Or Reader anyone come now!!!\n");
 sem_post(&wrt);
 }
 pthread_mutex_unlock(&lock);
}
void * writer(void * threadid)
{
 d++;
 sem_wait(&wrt);
 printf("\nWriter is Writing!!!\n");
 sleep(2);
 sem_post(&wrt);
 d--;
}
int main (int argc, char *argv[])
{
 pthread_t th1;
pthread_t th2;
 pthread_mutex_init(&lock, NULL);
 sem_init(&wrt,0,1);
 int f=0;
 while(f==0)
{
printf("1 Reader\n 2 Writer \n 3 Exit");
int y;
scanf("%d",&y);
 int x=0,z=0;
if(y==1 )
{
pthread_create(&th1, NULL, (void *)reader, (void *)&x);
x++;
}
else if(y==2 )
{
pthread_create(&th2, NULL, (void *)writer, (void *)&z);
}
 else{
 break;
 }
}
}
