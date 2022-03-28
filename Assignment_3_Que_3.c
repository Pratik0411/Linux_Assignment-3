#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<pthread.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/types.h>

void* proc(void* param)
{
	sleep(2);
	return 0;
}

int main()
{
	printf("ALL IZZ WELL\nSECOND CHANGE\n");
	pthread_attr_t Attr;
	pthread_t id;
	void *stk;
	size_t siz;
	int err;
	
	size_t my_stksize = 300000;
	void *my_stack;
	
	pthread_attr_init(&Attr);
	
	pthread_attr_getstacksize(&Attr,&siz);
	pthread_attr_getstackaddr(&Attr,&stk);
	
	printf("Default: Addr=%08x Default Size= %d\n", stk, siz);
	
	my_stack=(void*)malloc(my_stksize);

	pthread_attr_setstack(&Attr,my_stack,my_stksize);

	pthread_create(&id,&Attr,proc,NULL);
	
	pthread_attr_getstack(&Attr,&stk,&siz);
	
	printf("\nNewly defined stack : addr=%08x and size =%d\n"), stk, siz;;
	sleep(3);
	
	return 0;
}


