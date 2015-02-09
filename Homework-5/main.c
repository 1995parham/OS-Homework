/*
 * In The Name Of God
 * ========================================
 * [] File Name : main.c
 *
 * [] Creation Date : 09-02-2015
 *
 * [] Last Modified : Mon 09 Feb 2015 11:18:22 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include "logical.h"
#include "mmu.h"
#include "page_table.h"
#include "memory.h"
#include <stdio.h>
#include <stdint.h>

#define MAX 1000*1000

void pf_handler(uint8_t* base, uint8_t index);

static int tlb_hit_n = 0;
static int page_fault_n = 0;

int main(int argc, char* argv[]){
	FILE* logical_addrs = fopen("assignment5/addresses.txt", "r");
	uint32_t number;
	int index = 0;
	logical_addr addrs[MAX];
	while(fscanf(logical_addrs, "%u", &number) > 0){
		logical_addr_parser(number, &addrs[index]);
		index++;
	}
	fclose(logical_addrs);

	for(int i = 0; i < 256; i++){
		add_page_table_entry(i, i, 0x0);
	}
	set_handler(pf_handler);
	
	init_frames();

	for(int i = 0; i < index; i++){
		int tlb_hit_result;
		uint8_t physical_addr;
		int8_t mem = mem_read((physical_addr = l_to_p(&addrs[i], &tlb_hit_result)), addrs[i].page_offset);
		printf("Virtual address: %u Physical address: %u Value: %d\n", addrs[i].page_number * 256 + addrs[i].page_offset, physical_addr, mem);
		tlb_hit_n += tlb_hit_result;	
	}

	printf("Page-fault-rate : %lf\n", (double) page_fault_n / index);
	printf("TLB hit rate : %lf\n", (double) tlb_hit_n / index);
}

void pf_handler(uint8_t* base, uint8_t index){
	page_fault_n++;
	
	*base = free_lru(index);
	
	FILE* hard_disk = fopen("assignment5/BACKING_STORE.bin", "r");
	uint8_t frame[256];
	fseek(hard_disk, index * 256, SEEK_SET);
	fread(frame, sizeof(uint8_t), 256, hard_disk);
	for(int i = 0; i < 256; i++){
		mem_write(*base, i, frame[i]);
	}
}
