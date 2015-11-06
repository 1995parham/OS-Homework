/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 06-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <semaphore.h>

#define GREEN "\x1B[32m"
#define NORMAL  "\x1B[0m"

int buffer = 0;

void die(const char *msg);

void *increase_run(void *arg);

void *decrease_run(void *arg);

int main(int argc, char *argv[])
{
	int i;

	/* decrease thread section */
	pthread_t decrease;
	pthread_attr_t decrease_attr;

	pthread_attr_init(&decrease_attr);
	if (pthread_create(&decrease, &decrease_attr, decrease_run, NULL) < 0) {
		die("pthread_create()");
	}

	/* increase thread section */
	pthread_t increase;
	pthread_attr_t increase_attr;

	pthread_attr_init(&increase_attr);
	if (pthread_create(&increase, &increase_attr, increase_run, NULL) < 0) {
		die("pthread_create()");
	}

	int sum = 0;
	void *return_value;

	pthread_join(increase, &return_value);
	sum += *((int *) return_value);

	pthread_join(decrease, &return_value);
	sum += *((int *) return_value);

	printf("Total buffer accesses: %d\n", sum);

	return 0;
}

void *decrease_run(void *arg)
{
	int *times = ((int *) malloc(sizeof(int)));

	*times = 0;
	if (buffer > 0) {
		(*times)++;
		buffer--;
		printf("[decrease] TID: %lld, PID: %d, Buffer: %d\n",
			(long long int) pthread_self(), getpid(), buffer);
	} else {
		printf("[decrease] Insuffient money in buffer\n");
	}

	return times;
}

void *increase_run(void *arg)
{
	int *times = ((int *) malloc(sizeof(int)));

	*times = 0;
	(*times)++;
	buffer++;
	printf("[increase] TID: %lld, PID: %d, Buffer: %d\n",
		(long long int) pthread_self(), getpid(), buffer);
	return times;
}


void die(const char *msg)
{
	perror(msg);
	exit(1);
}
