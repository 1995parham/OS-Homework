/*
 * In The Name Of God
 * ========================================
 * [] File Name : while-2.c
 *
 * [] Creation Date : 13-11-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#define _GNU_SOURCE

#include <stdio.h>
#include <sched.h>

int main(int argc, char *argv[])
{
	int i, ret;
	cpu_set_t set;

	CPU_SET(0, &set);
	ret = sched_setaffinity(0, sizeof(cpu_set_t), &set);
	if (ret == -1)
		perror("sched_setaffinity()");
	i = 0;
	while (1) {
		i++;
		printf("%d\n", i);
	}
}
