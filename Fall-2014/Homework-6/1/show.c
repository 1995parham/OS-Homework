/*
 * In The Name Of God
 * ========================================
 * [] File Name : show.c
 *
 * [] Creation Date : 20-01-2015
 *
 * [] Last Modified : Tue 20 Jan 2015 08:26:11 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdio.h>
#include "hdd.h"
#include "show.h"

void show_header(void)
{
	int i = 0;

	for (i = 0; i < MAX_CYLINDERS; i++)
		printf("-----");
	printf("\n");
	for (i = 0; i < MAX_CYLINDERS; i++)
		printf("%04d ", i);
	printf("\n");
}

void show_head(int position)
{
	int index = 0;

	for (index = 0; index < position; index++)
		printf("     ");
	printf("  *\n");
}

void show_footer(void)
{
	int i = 0;

	for (i = 0; i < MAX_CYLINDERS; i++)
		printf("-----");
	printf("\n");
}
