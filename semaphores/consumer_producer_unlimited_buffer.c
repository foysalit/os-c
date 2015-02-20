#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>

#ifndef BUFFER_SIZE
#define BUFFER_SIZE 10
#endif

int in, out;
int buffer[BUFFER_SIZE];
sem_t *full, *empty;

static void put(int data){
	sem_wait(empty);

	buffer[in] = data;
	in = (in+1) % BUFFER_SIZE;

	sem_post(full);
}

static int get(){
	int d;
	sem_wait(full);

	d = buffer[out];
	out = (out+1) % BUFFER_SIZE;
	
	sem_post(empty);
	return d;
}

static void * producerA (void *data) {
	int n;
	printf("producing\n");

	for (n = 0; n < 20; n++) {
		sleep(1);
		printf("A is writing %d\n", n);
		put(n);
	}

	return NULL;
}

static void * producerB (void *data) {
	int n;
	printf("producing\n");

	for (n = 600; n > 580; n--) {
		sleep(2);
		printf("B is writing %d\n", n);
		put(n);
	}

	return NULL;
}

static void * consumer (void *data) {
	int d;
	printf("consuming\n");

	while (1) {
		d = get();
		printf("Number read: %d\n", d);
	}

	return NULL;
}

int main(int argc, char const *argv[])
{
	pthread_t producer_a_thread, producer_b_thread, consumer_a_thread;
	void *retval;

	empty = (sem_t *) malloc(sizeof(sem_t));
	full = (sem_t *) malloc(sizeof(sem_t));

	in = 0;
	out = 0;

	printf("Starting semaphores\n");
	sem_init(empty, 0, BUFFER_SIZE);
	sem_init(full, 0, 3);
	printf("Started semaphores\n");

	printf("Starting threads\n");
	pthread_create(&producer_a_thread, NULL, producerA, 0);
	pthread_create(&producer_b_thread, NULL, producerB, 0);
	pthread_create(&consumer_a_thread, NULL, consumer, 0);
	printf("Started threads\n");

	pthread_join(producer_a_thread, &retval);
	pthread_join(producer_b_thread, &retval);
	printf("joined a\n");
	pthread_join(consumer_a_thread, &retval);
	printf("joined b\n");

	return 0;
}