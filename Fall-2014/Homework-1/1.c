/*
 * In The Name Of God
 * ========================================
 * [] File Name : 1.c
 *
 * [] Creation Date : 06-02-2015
 *
 * [] Last Modified : Fri Feb  6 22:41:15 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void die(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	int fds[2];
	pid_t child;
	const char *path = "/";

	if (argc > 1)
		path = argv[1];
	if (pipe(fds) == -1)
		die("pipe()");
	child = fork();
	if (child == -1) {
			die("fork()");
	} else if (child == 0) {
			close(1);
			/*
			 * very very important if u
			 * remove it, program does not end.
			*/
			close(fds[0]);

			fprintf(stderr, "INFO: [child] child == %d\n", child);

			if (dup(fds[1]) == -1)
				die("dup()");

			fprintf(stderr, "INFO: [child] ls is going to exec\n");

			if (execlp("ls", "ls", "-la", path, NULL) == -1)
				die("execlp()");
	} else {
			close(0);
			/*
			 * very very important if u
			 * remove it, program does not end.
			*/
			close(fds[1]);

			fprintf(stderr, "INFO: [parent] child == %d\n", child);
			fprintf(stderr, "INFO: [parent] I am going to wait\n");

			int status = 0;

			if (wait(&status) != child)
				die("wait()");

			fprintf(stderr, "INFO: [parent] wait complete\n");
			fprintf(stderr, "INFO: [parent] Exited: %d Status: %d\n",
					WIFEXITED(status), WEXITSTATUS(status));

			if (dup(fds[0]) == -1)
				die("dup()");

			if (execlp("wc", "wc", "-l", NULL) == -1)
				die("execlp()");

			exit(0);
	}
	return 0;
}
