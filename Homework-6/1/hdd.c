/*
 * In The Name Of God
 * ========================================
 * [] File Name : hdd.c
 *
 * [] Creation Date : 20-01-2015
 *
 * [] Last Modified : Tue 20 Jan 2015 08:25:09 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#include <stdlib.h>
#include <memory.h>
#include "show.h"
#include "hdd.h"

static int head;

void set_head(int position)
{
	head = position;
}

int fcfs(int req[], int n)
{
	#ifdef SHOW	
		show_header();
	#endif

	int index = 0;
	int seek = 0;
	while(index != n){	
		seek += abs(head - req[index]);
		head = req[index];
		index++;
		
		#ifdef SHOW
			show_head(head);
		#endif
	}
	#ifdef SHOW
		show_footer();
	#endif

	return seek;
}

int sstf(int req[], int n)
{
	#ifdef SHOW
		show_header();
	#endif

	int seek = 0;
	int done = 0;
	int single_done[n];
	memset(&single_done, 0, n * sizeof(int));
	while(done != n){
		int min = MAX_CYLINDERS;
		int min_index = -1;
		for(int i = 0; i < n; i++){
			if(!single_done[i] && min > abs(head - req[i])){
				min = abs(head - req[i]);
				min_index = i;
			}
		}
		seek += abs(head - req[min_index]);
		head = req[min_index];
		done++;
		single_done[min_index] = 1;

		#ifdef SHOW
			show_head(head);
		#endif
	}
	#ifdef SHOW
		show_footer();
	#endif

	return seek;
}

int scan(int req[], int n)
{
	#ifdef SHOW
		show_header();
	#endif

	int seek = 0;
	int done = 0;
	int single_done[n];
	int direction = 0;
	memset(&single_done, 0, n * sizeof(int));
	while (done != n) {
		for (int i = 0; i < n; i++) {
			if ((!single_done[i]) && req[i] == head) {
				#ifdef SHOW
					show_head(head);
				#endif

				single_done[i] = 1;
				done++;
			}
		}
		seek++;
		if(direction) {
			head++;
			if (head == MAX_CYLINDERS) {
				head -= 2;
				direction = 0;
			}
		} else {
			head--;
			if(head == -1) {
				head += 2;
				direction = 1;
			}
		}
	}
	#ifdef SHOW
		show_footer();
	#endif
	
	return seek;
}

int c_scan(int req[], int n)
{
	#ifdef SHOW
		show_header();
	#endif

	int seek = 0;
	int done = 0;
	int single_done[n];
	memset(&single_done, 0, n * sizeof(int));
	while(done != n){
		for(int i = 0; i < n; i++){
			if((!single_done[i]) && req[i] == head){
				#ifdef SHOW
					show_head(head);
				#endif

				single_done[i] = 1;
				done++;
			}
		}
		seek++;
		head = (head + 1) % (MAX_CYLINDERS);
	}

	#ifdef SHOW
		show_footer();
	#endif

	return seek;
}

int look(int req[], int n)
{
	#ifdef SHOW
		show_header();
	#endif
	
	int seek = 0;
	int done = 0;
	int single_done[n];
	int direction = 0;
	memset(&single_done, 0, n * sizeof(int));
	while(done != n){
		for(int i = 0; i < n; i++){
			if((!single_done[i]) && req[i] == head){
				#ifdef SHOW
					show_head(head);
				#endif
				
				single_done[i] = 1;
				done++;
			}
		}
		int find = 0;
		if(direction){
			for(int i = 0; i < n; i++){
				if((!single_done[i]) && req[i] > head){
					find = 1;
					seek++;
					head++;
					break;
				}
			}
			if(!find){
				direction = 0;
				seek++;
				head--;
			}
		}else{
			for(int i = 0; i < n; i++){
				if((!single_done[i]) && req[i] < head){
					find = 1;
					seek++;
					head--;
					break;
				}
			}
			if(!find){
				direction = 1;
				seek++;
				head--;
			}
		}
	}
	#ifdef SHOW
		show_footer();
	#endif

	return seek;
}

int c_look(int req[], int n)
{
	#ifdef SHOW
		show_header();
	#endif

	int seek = 0;
	int done = 0;
	int single_done[n];
	memset(&single_done, 0, n * sizeof(int));
	while(done != n){
		for(int i = 0; i < n; i++){
			if((!single_done[i]) && req[i] == head){
				#ifdef SHOW
					show_head(head);
				#endif

				single_done[i] = 1;
				done++;
			}
		}
		seek++;
		int find = 0;
		for(int i = 0; i < n; i++){
			if((!single_done[i]) && req[i] > head){
				find = 1;
				head++;
				break;
			}
		}
		if(!find){
			int min = MAX_CYLINDERS;
			int min_index = -1;
			for(int i = 0; i < n; i++){
				if(!single_done[i] && min > req[i]){
					min = req[i];
					min_index = i;
				}
			}
			if(min_index != -1)
				head = req[min_index];
		}
	}
	#ifdef SHOW
		show_footer();
	#endif

	return seek;

}
