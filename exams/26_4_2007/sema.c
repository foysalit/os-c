#include "stdlib.h"
#include "stdio.h"
#include "unistd.h"
#include "pthread.h"
#include "semaphore.h"

sem_t sem1, sem2, sem3, sem4, sem5, sem6;

void * Proc2 (void *arg);
void * Proc3 (void *arg);
void * Proc4 (void *arg);
void * Proc5 (void *arg);
void * Proc6 (void *arg);

int main(int argc, char const *argv[])
{
	pthread_t th2, th3, th4, th5, th6;

	sem_init(&sem1, 0, 1);
	sem_init(&sem2, 0, 0);
	sem_init(&sem3, 0, 0);
	sem_init(&sem4, 0, 0);
	sem_init(&sem5, 0, 0);
	sem_init(&sem6, 0, 0);

	pthread_create(&th2, NULL, Proc2, NULL);
	pthread_create(&th3, NULL, Proc3, NULL);
	pthread_create(&th4, NULL, Proc4, NULL);
	pthread_create(&th5, NULL, Proc5, NULL);
	pthread_create(&th6, NULL, Proc6, NULL);

	while(1) {
		printf("Process 1 is waiting\n");
		sem_wait(&sem1);
		printf("awake and running process 1\n");
		sleep(2);
		printf("finished process 1\n");
		sem_post(&sem2);
		sem_post(&sem3);
	}

	pthread_exit(0);

	sem_destroy(&sem1);
	sem_destroy(&sem2);
	sem_destroy(&sem3);
	sem_destroy(&sem4);
	sem_destroy(&sem5);
	sem_destroy(&sem6);

	return 0;
}

void * Proc2 (void *arg) {
	while(1) {
		printf("Process 2 is waiting\n");
		sem_wait(&sem2);
		printf("awake and running process 2\n");
		sem_post(&sem4);
	}
}

void * Proc3 (void *arg) {
	while(1) {
		printf("Process 3 is waiting\n");
		sem_wait(&sem3);
		printf("awake and running process 3\n");
		sem_post(&sem4);
		sem_post(&sem5);
	}
}

void * Proc4 (void *arg) {
	while(1) {
		printf("Process 4 is waiting\n");
		sem_wait(&sem4);
		sem_wait(&sem4);
		printf("awake and running process 4\n");
		sem_post(&sem6);
	}
}

void * Proc5 (void *arg) {
	while(1) {
		printf("Process 5 is waiting\n");
		sem_wait(&sem5);
		printf("awake and running process 5\n");
		sem_post(&sem6);
		sem_post(&sem1);
	}
}

void * Proc6 (void *arg) {
	while(1) {
		printf("Process 6 is waiting\n");
		sem_wait(&sem6);
		sem_wait(&sem6);
		printf("awake and running process 6\n");
	}
}