// In The Name Of God
// ========================================
// * File Name : show.c
// 
// * Creation Date : 13-12-2014
//
// * Last Modified : Tue Jan 20 08:11:33 2015
//
// * Created By : Parham Alvani (parham.alvani@gmail.com)
// =======================================
#include <stdio.h>
#include "hdd.h"
#include "show.h"

void show_header()
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

void show_footer()
{
	int i = 0;
	for (i = 0; i < MAX_CYLINDERS; i++)
		printf("-----");
	printf("\n");
}
