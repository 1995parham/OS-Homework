/*
 * In The Name Of God
 * ========================================
 * [] File Name : fifo.h
 *
 * [] Creation Date : 20-01-2015
 *
 * [] Last Modified : Tue 20 Jan 2015 08:40:09 AM IRST
 *
 * [] Created By : Parham Alvani (parham.alvani@gmail.com)
 * =======================================
*/
#ifndef FIFO_H
#define FIFO_H

#ifndef FIFO_MAJOR
#define FIFO_MAJOR 0   /* dynamic major by default */
#endif

#ifndef MAX_BUFF
#define MAX_BUFF 1024
#endif

/*
 * Prototypes for shared functions
 */
static int fifo_open(struct inode *inode, struct file *filp);
static int fifo_release(struct inode* inode, struct file *filp);
static ssize_t fifo_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos);
static ssize_t fifo_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos);

#endif
