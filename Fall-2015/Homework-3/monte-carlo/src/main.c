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
#include <stdlib.h>
#include <time.h>

/*
 * Let R = 1000
 * Let Number = 1000
 * Let point's x, y are integer
*/

#define NUMBER (1000 * 1000 * 10)
#define RADIX 1000

int main(int argc, const char *argv[])
{
	int area_circle_1 = 0;
	int area_circle_2 = 0;
	int area_circle_3 = 0;
	int area_circle_4 = 0;
	int area_circle = 0;
	int area_square = NUMBER;

	srand((unsigned int) time(NULL));

	#pragma omp parallel sections
	{
		#pragma omp section
		{
			int i, x, y;

			for (i = 0; i < NUMBER; i++) {
				x = rand() % RADIX;
				y = rand() % RADIX;
				if (x * x + y * y <= RADIX * RADIX)
					area_circle_1++;
			}
			printf("Thrad %d finished: %d\n",
				omp_get_thread_num(), area_circle_1);
		}
		#pragma omp section
		{
			int i, x, y;

			for (i = 0; i < NUMBER; i++) {
				x = rand() % RADIX;
				y = rand() % RADIX;
				if (x * x + y * y <= RADIX * RADIX)
					area_circle_2++;
			}
			printf("Thrad %d finished: %d\n",
				omp_get_thread_num(), area_circle_2);
		}
		#pragma omp section
		{
			int i, x, y;

			for (i = 0; i < NUMBER; i++) {
				x = rand() % RADIX;
				y = rand() % RADIX;
				if (x * x + y * y <= RADIX * RADIX)
					area_circle_3++;
			}
			printf("Thrad %d finished: %d\n",
				omp_get_thread_num(), area_circle_3);
		}
		#pragma omp section
		{
			int i, x, y;

			for (i = 0; i < NUMBER; i++) {
				x = rand() % RADIX;
				y = rand() % RADIX;
				if (x * x + y * y <= RADIX * RADIX)
					area_circle_4++;
			}
			printf("Thrad %d finished: %d\n",
				omp_get_thread_num(), area_circle_4);
		}
	}
	double pi;

	area_circle = area_circle_1 + area_circle_2 +
		area_circle_3 + area_circle_4;
	pi = (double) area_circle / area_square;
	printf("%g\n", pi);
	return 0;
}
