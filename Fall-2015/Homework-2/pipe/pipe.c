/*
 * In The Name Of God
 * ========================================
 * [] File Name : pipe.c
 *
 * [] Creation Date : 15-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main(int argc, const char *argv[])
{
	int fd_to_child[2];
	int fd_to_parent[2];
	pid_t childpid;
	
	pipe(fd_to_child);
	pipe(fd_to_parent);
	
	if ((childpid = fork()) == -1) {
		perror("fork");
		exit(1);
	}

	if (childpid == 0) {
		close(fd_to_child[1]);
		close(fd_to_parent[0]);
		
		FILE *input = fdopen(fd_to_child[0], "r");
		FILE *output = fdopen(fd_to_parent[1], "w");
		
		int n;
			
		fscanf(input, "%d", &n);

		int i;
		int sum;

		for (i = 1; i < n; i++) {
			if (n % i == 0) {
				sum += i;
			}
		}
		if (sum == n) {
			fprintf(output, "True\n");
		} else {
			fprintf(input, "False\n");
		}

		exit(0);
	} else {
		close(fd_to_child[0]);
		close(fd_to_parent[1]);

		int n;

		scanf("%d", &n);
		
		FILE *output = fdopen(fd_to_child[1], "w");
		FILE *input = fdopen(fd_to_parent[0], "r");

		fprintf(output, "%d\n", n);
		fflush(output);
		
		char answer[200];

		fscanf(input, "%s", answer);
		printf("%s\n", answer);
	}
	return 0;
}
