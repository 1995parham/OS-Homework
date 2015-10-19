/*
 * In The Name Of God
 * ========================================
 * [] File Name : hdd.h
 *
 * [] Creation Date : 20-01-2015
 *
 * [] Last Modified : Tue 20 Jan 2015 08:27:09 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#define MAX_CYLINDERS 10
/*
 * Comment it if you don't want showing feature
*/
#define SHOW

void set_head(int position);

/*
 * Please remeber use set_head before using the following algorithm
*/

int fcfs(int req[], int n);

int sstf(int req[], int n);

int scan(int req[], int n);

int c_scan(int req[], int n);

int look(int req[], int n);

int c_look(int req[], int n);
