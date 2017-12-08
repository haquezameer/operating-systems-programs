#include<stdio.h>
#include<stdlib.h>
#include<semaphore.h>
#include<pthread.h>

#define buffersize 10

pthread_mutex_t mutex;
sem_t full,empty;
pthread_t tidp[10],tidc[10];

int counter;
int buff[buffersize];

void init(){
    pthread_mutex_init(&mutex,NULL);
    sem_init(&full,1,0);
    sem_init(&empty,1,buffersize);
    counter=0;
}

void write(int item){
    buff[counter++]=item;
}

int read(){
    return buff[--counter];
}

void* producer(void* arg){
    int item;
    item=rand()%5;
    sem_wait(&empty);
    pthread_mutex_lock(&mutex);
    printf("Producer has produced item %d\n",item);
    write(item);
    pthread_mutex_unlock(&mutex);
    sem_post(&full);
}

void* consumer(void* arg){
    int item;
    sem_wait(&full);
    pthread_mutex_lock(&mutex);
    item=read();
    printf("Consumer has consumed item %d\n",item);
    pthread_mutex_unlock(&mutex);
    sem_post(&empty);
}

int main(){
    int i,n1,n2;
    init();
    printf("Enter the number of producers\n");
    scanf("%d",&n1);
    printf("Enter the number of consumers\n");
    scanf("%d",&n2);
    for(i=0;i<n1;i++)
        pthread_create(&tidp[i],NULL,producer,NULL);
    for(i=0;i<n2;i++)
        pthread_create(&tidc[i],NULL,consumer,NULL);
    for(i=0;i<n1;i++)
        pthread_join(tidp[i],NULL);
    for(i=0;i<n2;i++)
        pthread_join(tidc[i],NULL);
    exit(0);
}