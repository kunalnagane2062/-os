#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h> 
#include <unistd.h> 
#define buffer_size 5
sem_t empty;
sem_t full;
pthread_mutex_t lock;
void * consumer(void * threadid)
{
sem_wait(&full);
pthread_mutex_lock(&lock);
printf("Consumed Item %d\n",*((int *)threadid));
pthread_mutex_unlock(&lock);
sem_post(&empty);
return NULL;
}
void * producer(void * threadid)
{
sem_wait(&empty);
pthread_mutex_lock(&lock);
printf("Produced Item %d\n",*((int *)threadid));
pthread_mutex_unlock(&lock);
sem_post(&full);
return NULL;
}
int main (int argc, char *argv[])
{
int i,j;
printf("Enter the number of Producer\n");
scanf("%d",&i);
printf("Enter the number of Consumer\n");
scanf("%d",&j);
pthread_t th1[i];
pthread_t th2[j];
sem_init(&empty,0,buffer_size);
 sem_init(&full,0,0); 
int f=0;
int p[5]={1,2,3,4,5};
int x=0,z=0;
while(f==0)
{
printf("1 Producer\n 2 Consumer \n 3 Exit\n");
int y;
scanf("%d",&y);
if(y==1 )
{
pthread_create(&th1[x], NULL, (void *)producer, (void *)&p[x]);
x++; 
}
else if(y==2)
{
pthread_create(&th2[z], NULL, (void *)consumer, (void*)&p[z]);
z++;
}
else{
break;
}
}
pthread_mutex_destroy(&lock);
sem_destroy(&empty);
sem_destroy(&full); 
return 0;
}
