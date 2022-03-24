#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>

pthread_t tid;

void* thread1(void *arg)
{
	printf("New created thread started executing\n");
	while(1);
}

int main()
{
	pthread_t thread;
	int rc,t=0;
	printf("Creating thread\n");
	rc=pthread_create(&thread,NULL,thread1,NULL);
	printf("\nThread ID : %u\n",thread);
	sleep(3);
	t=pthread_cancel(thread);
	if(t==0)
	printf("Canceled thread\n");
	printf("Thread ID: %u\n",thread);
	return 0;
}
