# Assignment 1 - Process Management

1. The purpose of this assignment is to work with fork , exec , and wait to
create new processes and use pipe to communicate between parent/child
processes. You should implement a code to illustrate the following com-
mand: ls / | wc -l . This command prints out the number of files in the
root path: ls / shows the files/directories in the root path, and its output
will be piped through | to wc -l , which counts the number of lines.
Hint1: Use fork to make a child process. The child process, then, exe-
cutes ls / , and it passes the result (i.e., the list files/directories) through
a pipe to the parent process. The parent executes wc -l to print out the
number of lines for the list passed by the child.
Hint2: You can use dup2 to redirect the output of the exec to the input
descriptor made by pipe .

2. In this assignment, you will work with message queues. You need to
implement two processes, such that the first process reads the content of a
file, e.g., file.txt , and passes it to the second process through a message
queue. Upon receipt of the file content, the second process should count
and print out the number of words in the file.
