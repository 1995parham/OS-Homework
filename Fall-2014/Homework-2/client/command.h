#ifndef COMMAND_H
#define COMMAND

void command_dispatcher(const char* command);

void join_command(int group_id);

void send_command(int group_id, const char* message_body);

void leave_command(int group_id);

void show_command(char show_c);

void quit_command();

#endif
