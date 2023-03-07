#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void* find_sum(void *args)
{
	int n,sum=0,i;
	printf("Enter a natural no.:");
	scanf("%d",&n);
	if(n<1)
		printf("INVALID NUMBER\n");
	else
	{
		for(i=1;i<=n;i++)
			sum+=i;
	}
	pthread_exit((void *)sum);
}

int main()
{
	pthread_t thread;
	int sum, count=0;
		pthread_create(&thread, NULL, find_sum, &count);
		pthread_join(thread, (void *)&sum);
		printf("Sum=%d\n",sum);
		sleep(1);
}
