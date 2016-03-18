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

#define GRN "\x1B[32m"
#define NRM "\x1B[0m"

#define READER_NUM 2

int buffer;
int have_read_access;
int reader_counter;

pthread_mutex_t write_mutex;
pthread_mutex_t read_mutex;

void die(const char *msg);

void *write_run(void *arg);

void *read_run(void *arg);

int main(int argc, char *argv[])
{
	int i;

	pthread_mutex_init(&write_mutex, NULL);
	pthread_mutex_init(&read_mutex, NULL);

	/* reader threads section */
	pthread_t readers[READER_NUM];
	pthread_attr_t readers_attr[READER_NUM];

	for (i = 0; i < READER_NUM; i++) {
		pthread_attr_init(readers_attr + i);
		if (pthread_create(readers + i, readers_attr + i, read_run,
			NULL) < 0) {
			die("pthread_create()");
		}
	}

	/* writer thread section */
	pthread_t writer;
	pthread_attr_t writer_attr;

	pthread_attr_init(&writer_attr);
	if (pthread_create(&writer, &writer_attr, write_run, NULL) < 0) {
		die("pthread_create()");
	}

	int sum = 0;
	void *return_value;

	for (i = 0; i < READER_NUM; i++) {
		pthread_join(readers[i], &return_value);
		sum += *((int *) return_value);
	}

	pthread_join(writer, &return_value);
	sum += *((int *) return_value);

	printf("Total buffer accesses: %d\n", sum);

	return 0;
}

void *write_run(void *arg)
{
	int *times = ((int *) malloc(sizeof(int)));

	*times = 0;
	while (1) {
		pthread_mutex_lock(&write_mutex);

		if (buffer < 15) {
			(*times)++;
			buffer++;
			printf("[write] TID: %lld, PID: %d, Buffer: %d\n",
				(long long int) pthread_self(), getpid(),
				buffer);
		} else {
			pthread_mutex_unlock(&write_mutex);
			break;
		}
		pthread_mutex_unlock(&write_mutex);
	}
	printf("TID %lld write on the buffer %d %stimes%s\n",
		(long long int) pthread_self(),
		*times, GRN, NRM);
	return times;
}

void *read_run(void *arg)
{
	int *times = ((int *) malloc(sizeof(int)));

	*times = 0;
	while (1) {
		if (have_read_access) {
			if (buffer < 15) {
				(*times)++;
				printf("[read] TID: %lld, PID: %d, Buffer: %d\n",
					(long long int) pthread_self(),
					getpid(),
					buffer);
				pthread_mutex_lock(&read_mutex);
				reader_counter++;
				if (reader_counter == READER_NUM) {
					pthread_mutex_unlock(&write_mutex);
				}
				pthread_mutex_unlock(&read_mutex);
			} else {
				pthread_mutex_unlock(&write_mutex);
				break;
			}
		} else {
			if (!pthread_mutex_trylock(&write_mutex)) {
				have_read_access = 1;
			}
		}
	}
	printf("TID %lld write on the buffer %d %stimes%s\n",
		(long long int) pthread_self(),
		*times, GRN, NRM);
	return times;
}


void die(const char *msg)
{
	perror(msg);
	exit(1);
}
