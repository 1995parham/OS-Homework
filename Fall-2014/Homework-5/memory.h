/*
 * In The Name Of God
 * ========================================
 * [] File Name : memory.h
 *
 * [] Creation Date : 09-02-2015
 *
 * [] Last Modified : Mon 09 Feb 2015 11:18:24 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>

uint8_t mem_read(uint8_t frame, uint8_t offset);
void mem_write(uint8_t frame, uint8_t offset, uint8_t input);

#endif
