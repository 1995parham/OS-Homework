/*
 * In The Name Of God
 * ========================================
 * [] File Name : page_table.h
 *
 * [] Creation Date : 09-02-2015
 *
 * [] Last Modified : Mon 09 Feb 2015 11:18:25 PM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef PAGE_TABLE_H
#define PAGE_TABLE_H

#include <stdint.h>

// Page table entry structure
// 32                  16          9 8 7               0
// |-------------------|------------|-|-----------------|
// |   Access          |  Reserved  |V| Physical  Base  |
// |           Times   |            |N|     Address     |
// |-------------------|------------|-|-----------------|
//
// * VN : Valid/Invalid
//

typedef struct{
	uint8_t base;
	uint8_t flag;
	uint16_t access;
} __attribute__((packed)) page_table_entry;

// Page fault handler must set for handling page faults.
//
//
typedef void (*page_fault_handler)(uint8_t* base, uint8_t index);

void add_page_table_entry(uint8_t index, uint8_t base, uint8_t flag);
uint8_t get_base_addr(uint8_t index);
void set_handler(page_fault_handler pf_handler);
void invalid_page_table_entry(uint8_t index);

#endif
