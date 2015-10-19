#include <pthread.h>
#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <unistd.h>

#define GREEN "\x1B[32m"
#define NORML  "\x1B[0m"

int counter = 0;
pthread_mutex_t mutex;

void die(const char* msg);
void* run(void* arg);

int main(int argc, char* argv[]){
	pthread_mutex_init(&mutex, NULL);

	pthread_t t1;
	pthread_attr_t attr1;
	pthread_attr_init(&attr1);
	if(pthread_create(&t1, &attr1, run, NULL) < 0){
		die("pthread_create()");
	}
	
	pthread_t t2;
	pthread_attr_t attr2;
	pthread_attr_init(&attr2);
	if(pthread_create(&t2, &attr2, run, NULL) < 0){
		die("pthread_create()");
	}

	pthread_t t3;
	pthread_attr_t attr3;
	pthread_attr_init(&attr3);
	if(pthread_create(&t3, &attr3, run, NULL) < 0){
		die("pthread_create()");
	}
	
	int sum = 0;
	void* retval;
	pthread_join(t1, &retval);
	sum += *((int *)retval);

	pthread_join(t2, &retval);
	sum += *((int *)retval);

	pthread_join(t3, &retval);
	sum += *((int *)retval);

	printf("Total buffer accesses: %d\n", sum);
}

void* run(void *arg){
	int* times = ((int *)malloc(sizeof(int)));
	*times = 0;
	while(1){
		pthread_mutex_lock(&mutex);
		
		if(counter < 15){
			(*times)++;
			counter++;
			printf("TID: %lld, PID: %d, Buffer: %d\n", pthread_self(), getpid(), counter);
		}else{
			pthread_mutex_unlock(&mutex);
			break;
		}
		pthread_mutex_unlock(&mutex);
	}
	printf("TID %lld worked on the buffer %d %stimes%s\n", pthread_self(), *times, GREEN, NORML);
	return times;
}

void die(const char* msg){
	perror(msg);
	exit(1);
}
