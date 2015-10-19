#ifndef MESSAGE_H
#define MESSAGE_H

#define MESSAGE_SIZE 255 * 4 + 32

typedef struct{			/* message struct size must be less than 4 * 255 byte */
	
	char verb[255];		/* send join leave */
	
	char arg[255];		/* if verb has no argument must be " " */
	
	int group_id;		/* if verb has no group_id must be -1 */
	
	char client_name[255];	/* always must set */

	
} Message;

int serialize_message(char* buffer, const Message* message);

int deserialize_message(char* buffer, Message* message);

#endif
