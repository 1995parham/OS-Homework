#include "constants.h"

#ifndef GROUP_ID_H
#define GROUP_ID_H

typedef struct{
	int id;

	int number;	//showing last empty cell and size !! ;-)))

	int socket_fds[MAX_CONN];
} GroupId;

void add_node(int socket_fd, GroupId* group_id);

int remove_node(int socket_fd, GroupId* group_id);

#endif
