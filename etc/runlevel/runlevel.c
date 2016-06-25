/*
 * In The Name Of God
 * ========================================
 * [] File Name : runlevel.c
 *
 * [] Creation Date : 25-06-2016
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2016 Parham Alvani.
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
	char input1[255];
	char input2[255];
	int fds[2];
	int pid;
	
	do {
		scanf("%s", input1);
		if (!strcmp(input1, "service"))
			break;
		else
			printf("Error: Input error\n");
	} while (1);

	scanf("%s", input2);

	pipe(fds);

	pid = fork();

	if (pid == 0) {
		/* close pipe input */
		close(fds[1]);
		/* close stdin  */
		close(0);
		/* duplicate pipe output as stdin */
		dup(fds[0]);
	
		execl("./runlevel.sh", "runlevel.sh", (char *) NULL);
	} else if (pid > 0) {
		/* close pipe output */
		close(fds[0]);
		/* close stdout */
		close(1);
		/* duplicate pipe input as stdout */
		dup(fds[1]);

		printf("%s", input2);
	} else {
		printf("Error: fork()\n");
	}	
}
