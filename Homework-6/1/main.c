// In The Name Of God
// ========================================
// * File Name : main.c
// 
// * Creation Date : 13-12-2014
//
// * Last Modified : Tue Jan 20 08:11:47 2015
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// ========================================
#include <time.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "hdd.h"

#define REQ_N 10

int main(int argc, char* argv[])
{
	if (argc < 2) {
		printf("Usage: HDD first_head_postion\n");
		exit(1);
	}
	
	int position = atoi(argv[1]);

	int req[REQ_N];
	srand(time(NULL));
	printf("Requests: ");
	for (int i = 0; i < REQ_N; i++) {
		req[i] = rand() % MAX_CYLINDERS;
		if (i % 10 == 0)
			printf("\n");
		printf("%04d ", req[i]);
	}
	printf("\n");
	
	set_head(position);
	printf("FCFS: %d\n", fcfs(req, REQ_N));

	set_head(position);
	printf("SSTF: %d\n", sstf(req, REQ_N));

	set_head(position);
	printf("SCAN: %d\n", scan(req, REQ_N));

	set_head(position);
	printf("C-SCAN: %d\n", c_scan(req, REQ_N));

	set_head(position);
	printf("LOOK: %d\n", look(req, REQ_N));

	set_head(position);
	printf("C-LOOK: %d\n", c_look(req, REQ_N));
}
