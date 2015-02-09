/*
 * In The Name Of God
 * ========================================
 * [] File Name : mmu.h
 *
 * [] Creation Date : 09-02-2015
 *
 * [] Last Modified : Mon 09 Feb 2015 11:18:24 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef MMU_H
#define MMU_H

#include "logical.h"
#include <stdint.h>

// TLB entry structure
// 32              16          8 7          0
// |---------------|------------|------------|
// |  Access       |    Frame   |    Page    |
// |         Times |    Index   |   Index    |
// |---------------|------------|------------|
//
//
typedef struct{
	uint8_t page_index;
	uint8_t frame_index;
	uint16_t access;
}__attribute__((packed)) tlb_entry;

// Frame table entry
// 32               16         8 7        0
// |----------------|-----------|----------|
// |  Last Access   |  Refrence |   Page   |
// |      Time      |    Number |  Index   |
// |----------------|-----------|----------|
//
//
typedef struct{
	uint8_t page_index;
	uint8_t ref_no;
	uint16_t access_time;
}__attribute__((packed)) frame_entry;

uint8_t l_to_p(const logical_addr* l_addr, int* tlb_hit);
uint8_t free_lru(uint8_t page);
void access_to_frame(uint8_t frame);
void init_frames();

#endif
