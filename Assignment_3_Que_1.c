#include<stdio.h>
#include<stdlib.h>
float var = 5;

void *area_sphere(void *arg)
{
	printf("Area of the sphere = %.2f\n", (var*var*var*(4/3)*(3.14)));
}
void *area_square(void *arg)
{
	printf("Area of the square = %.2f\n", var*var);
}
void *area_circle(void *arg)
{
	printf("Area of circle = %.2f\n", var*var*(3.14));
}

int main()
{
	pthread_t thread1, thread2, thread3;
	
	pthread_create(&thread1, NULL, area_sphere, NULL);
	pthread_create(&thread2, NULL, area_square, NULL);
	pthread_create(&thread2, NULL, area_circle, NULL);
	
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread2, NULL);
	
	printf("Global Value = %.2f\n", var);
	return 0;
}	
