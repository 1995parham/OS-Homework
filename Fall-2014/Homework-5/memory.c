/*
 * In The Name Of God
 * ========================================
 * [] File Name : memory.c
 *
 * [] Creation Date : 09-02-2015
 *
 * [] Last Modified : Mon 09 Feb 2015 11:30:27 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "memory.h"
#include "mmu.h"

#include <stdio.h>
#include <stdint.h>

void mem_write(uint8_t frame, uint8_t offset, uint8_t input)
{
	FILE *memory = fopen("memory", "r+");

	fseek(memory, frame * 256 + offset, SEEK_SET);
	fwrite(&input, sizeof(uint8_t), 1, memory);
	fclose(memory);
	access_to_frame(frame);
}

uint8_t mem_read(uint8_t frame, uint8_t offset)
{
	FILE *memory = fopen("memory", "r");
	uint8_t ret;

	fseek(memory, frame * 256 + offset, SEEK_SET);
	fread(&ret, sizeof(uint8_t), 1, memory);
	fclose(memory);
	access_to_frame(frame);
	return ret;
}
