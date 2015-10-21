/*
 * In The Name Of God
 * ========================================
 * [] File Name : main
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

/*
 * In this program we get R = 1
*/

int main(int argc, const char *argv[])
{
	#pragma omp parallel sections
	{
		#pragma omp section
		{
		printf("hello\n");
		}
		#pragma omp section
		{
		printf("bye\n");
		}
	}
	return 0;
}
