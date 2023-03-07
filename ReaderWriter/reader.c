#include <stdio.h>
#include <sys/shm.h>
#include "psem.h"
#include <unistd.h>

int main(){
	psem_t mutex,wrt;
	int readcnt=0;
	int shmid=shmget(4321,sizeof(int),0666|IPC_CREAT);
	int *val=(int*)shmat(shmid,NULL,0);
	psem_init(&mutex,2345,1);
	psem_init(&wrt,2346,1);
	*val=10;
	int i=1;
	while(1){
		psem_wait(&mutex);
		readcnt++;
		if(readcnt==1){
			psem_wait(&wrt);
		}
		psem_post(&mutex);
		printf("Reader %d reads %d\n",i,*val);
		psem_wait(&mutex);
		readcnt--;
		if(readcnt==0){
			psem_post(&wrt);
		}
		psem_post(&mutex);
		i++;
		sleep(2);
	}
	psem_destroy(&mutex);
	psem_destroy(&wrt);
	shmdt(val);
	shmctl(shmid,IPC_RMID,NULL);
	return 0;
}
