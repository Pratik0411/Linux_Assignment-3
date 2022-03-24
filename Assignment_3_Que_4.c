#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>

pthread_t tid;
int id;
void* thread1(void *arg)
{
	int thread=(int)arg;
	printf("newly created thread executing\n");
	printf("\nThread id : %u\n",thread);
	
	id=getppid();
	printf("\nParent process id : %u\n\n",id);
	while(1);
	
}

int main()
{
	pthread_t thread;
	int rc,t=0;
	printf("creating thread\n\n");
	rc=pthread_create(&thread,NULL,thread1,thread);
	sleep(3);
	return 0;
}

