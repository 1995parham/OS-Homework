# Assignment 3 - Threads and Mutexes

In this assignment you need to write a program that creates three threads.
These threads access a shared integer, called buffer, one at a time. The buffer
will initially be set to 0. Each thread should print its thread ID, process ID
and the buffer’s current value in one statement, then increment the buffer by
one. Use a mutex to ensure this whole process is not interrupted. Have the
threads modify the buffer a total of 15 times. When each thread is done, it
should return the number of times it modified the buffer to the main thread.

```bash
$ ./assignment3
```

```
TID: 3077897072, PID: 30656,
TID: 3069504368, PID: 30656,
TID: 3059014512, PID: 30656,
TID: 3077897072, PID: 30656,
TID: 3069504368, PID: 30656,
TID: 3077897072, PID: 30656,
TID: 3059014512, PID: 30656,
TID: 3069504368, PID: 30656,
TID: 3077897072, PID: 30656,
TID: 3059014512, PID: 30656,
TID: 3069504368, PID: 30656,
TID: 3077897072, PID: 30656,
TID: 3069504368, PID: 30656,
TID: 3059014512, PID: 30656,
TID: 3069504368, PID: 30656,
TID 3077897072 worked on the
TID 3069504368 worked on the
TID 3059014512 worked on the
Total buffer accesses: 15
Buffer: 0
Buffer: 1
Buffer: 2
Buffer: 3
Buffer: 4
Buffer: 5
Buffer: 6
Buffer: 7
Buffer: 8
Buffer: 9
Buffer: 10
Buffer: 11
Buffer: 12
Buffer: 13
Buffer: 14
buffer 5 times
buffer 6 times
buffer 4 times
```
