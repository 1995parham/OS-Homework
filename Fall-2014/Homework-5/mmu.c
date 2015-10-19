/*
 * In The Name Of God
 * ========================================
 * [] File Name : mmu.c
 *
 * [] Creation Date : 09-02-2015
 *
 * [] Last Modified : Mon 09 Feb 2015 11:28:34 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "mmu.h"
#include "logical.h"
#include "page_table.h"

#include <stdint.h>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>

static tlb_entry tlb[16];
static int last_entry = 0;

static frame_entry frames[128];

void add_tlb_entry(uint8_t page, uint8_t frame){
	if(last_entry == 16){
		int i = 0;
		int min_index = 0;
		for(i = 0; i < last_entry; i++){
			if(tlb[min_index].access > tlb[i].access){
				min_index = i;
			}
		}
		last_entry--;
		tlb[min_index].page_index = tlb[last_entry].page_index;
		tlb[min_index].frame_index = tlb[last_entry].frame_index;
		tlb[min_index].access = tlb[last_entry].access;
	}
	tlb[last_entry].page_index = page;
	tlb[last_entry].frame_index = frame;
	tlb[last_entry].access = 0;
	last_entry++;

}
void remove_tlb_entry(uint8_t page){
	int i;
	for(i = 0; i < last_entry; i++){
		if(tlb[i].page_index == page){
			last_entry--;
			tlb[i].page_index = tlb[last_entry].page_index;
			tlb[i].frame_index = tlb[last_entry].frame_index;
			tlb[i].access = tlb[last_entry].access;
		}
	}
}

uint8_t l_to_p(const logical_addr* logical, int* tlb_hit){
	short find = 0;
	int i;
	for(i = 0; i < last_entry; i++){
		if(tlb[i].page_index == logical->page_number){
			tlb[i].access++;
			find = 1;
			if(tlb_hit) *tlb_hit = 1;
			return tlb[i].frame_index;
		}
	}
	if(!find){
		if(tlb_hit) *tlb_hit = 0;
		uint8_t frame = get_base_addr(logical->page_number);
		add_tlb_entry(logical->page_number, frame);
		return frame;
	}
	return 0;
}

void access_to_frame(uint8_t frame){
	if(frame >= 128){
		fprintf(stderr, "Memory Exception.\n");
		exit(1);
	}
	frames[frame].access_time = time(NULL);
}

void init_frames(){
	uint8_t i = 0;
	for(i = 0; i < 128; i++){
		frames[i].ref_no = 0;
	}
}

uint8_t free_lru(uint8_t page){
	uint8_t min_index = 0;
	uint8_t i = 0;
	for(i = 0; i < 128; i++){
		if(frames[i].ref_no == 0){
			frames[i].ref_no = 1;
			frames[i].page_index = page;
			return i;
		}
		if(frames[min_index].access_time > frames[i].access_time){
			min_index = i;
		}
	}
	invalid_page_table_entry(frames[min_index].page_index);
	remove_tlb_entry(frames[min_index].page_index);
	frames[min_index].page_index = page;
	return min_index;
}
