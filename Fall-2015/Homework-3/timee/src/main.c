/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 21-10-2015
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
/*
 * Copyright (c) 2015 Parham Alvani.
*/
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, const char *argv[])
{
	time_t now_t;
	struct tm now;

	time(&now_t);
	localtime_r(&now_t, &now);


	#pragma omp parallel sections
	{
		#pragma omp section
		{
			printf("Thread %d, Months: %d\n",
				omp_get_thread_num(), now.tm_mon);
		}

		#pragma omp section
		{
			printf("Thread %d, Days: %d\n",
				omp_get_thread_num(), now.tm_yday);
		}

		#pragma omp section
		{
			printf("Thread %d, Weeks: %d\n",
				omp_get_thread_num(), now.tm_yday / 7);
		}

		#pragma omp section
		{
			printf("Thread %d, Hours: %d\n",
				omp_get_thread_num(),
				now.tm_hour + now.tm_yday * 24);
		}

		#pragma omp section
		{
			printf("Thread %d, Minutes: %d\n",
				omp_get_thread_num(),
				now.tm_min + now.tm_hour * 60 +
					now.tm_yday * 24 * 60);
		}

		#pragma omp section
		{
			printf("Thread %d, Seconds: %d\n",
				omp_get_thread_num(),
				now.tm_sec + now.tm_min * 60 +
					now.tm_hour * 60 * 60 +
					now.tm_yday * 24 * 60 * 60);
		}
	}
	return 0;
}
