#include <stdio.h>
#include <stdlib.h>
#include <sys/shm.h>
#include "psem.h"
#include <unistd.h>
#include <time.h>

int main(){
	srand(time(NULL));
	psem_t wrt;
	int shmid=shmget(4321,sizeof(int),0666|IPC_CREAT);
	int *val=(int*)shmat(shmid,NULL,0);
	psem_init(&wrt,2346,-1);
	int i=1;
	*val=10;
	while(i<=5){
		sleep(rand()%5+1);
		psem_wait(&wrt);
		printf("Writer Started\nOriginal Value:%d\n",*val);
		*val+=10;
		sleep(3);
		i++;
		printf("Modified Value:%d\nWriter Stopped\n\n",*val);
		psem_post(&wrt);
	}
	psem_destroy(&wrt);
	shmdt(val);
	return 0;
}
