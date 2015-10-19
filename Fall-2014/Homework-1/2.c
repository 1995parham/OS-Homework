/*
 * In The Name Of God
 * ========================================
 * [] File Name : 2.c
 *
 * [] Creation Date : 06-02-2015
 *
 * [] Last Modified : Fri Feb  6 22:39:39 2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>

const int MAX_BUFFER_SIZE = 1024;

void die(const char *msg)
{
	perror(msg);
	exit(1);
}

int main(int argc, char *argv[])
{
	pid_t child;
	const char *path = "file.txt";

	if (argc > 2)
		path = argv[1];

	child = fork();
	if (child == -1) {
		die("fork()");
	} else if (child == 0) {
		/* using / is necessary */
		mqd_t mqd = mq_open("/file_message_queue", O_RDONLY);

		if (mqd == -1)
			die("[child] mq_open()");

		int number = 0;
		char buffer[MAX_BUFFER_SIZE];

		while (1) {
			int size = mq_receive(mqd, buffer, MAX_BUFFER_SIZE, 0);

			if (size == -1)
				die("mq_receive()");
			buffer[size] = 0;
			if (strcmp(buffer, "FIN") != 0) {
				number++;
			} else {
				printf("%d\n", number);
				mq_unlink("/file_message_queue");
				exit(0);
			}
		}
	} else {
		struct mq_attr attr;

		attr.mq_flags = 0;
		attr.mq_maxmsg = 10;
		attr.mq_msgsize = MAX_BUFFER_SIZE;
		attr.mq_curmsgs = 0;
		/* using / is necessary */
		mqd_t mqd = mq_open("/file_message_queue",
				O_CREAT | O_WRONLY, 0644, &attr);

		if (mqd == -1)
			die("[parent] mq_open()");

		FILE *file = fopen(path, "r");
		char buffer[MAX_BUFFER_SIZE];

		while (fscanf(file, "%s", buffer) > 0)
			if (mq_send(mqd, buffer, strlen(buffer), 0) == -1)
				die("mq_send()");
		fclose(file);
		strcpy(buffer, "FIN");
		if (mq_send(mqd, buffer, strlen(buffer), 0) == -1)
			die("mq_send()");
		mq_close(mqd);
	}
	return 0;
}
