# Assignment 4 - Process Synchronization

In this assignment, you will implement the Reader-Writer problem. In this
system, you have two readers who read from a shared buffer and one writer
who updates the buffer. The buffer contains a variable VAR , which is initialized
to zero. After each access, the writer reads the content of the buffer, prints
it along with its own PID, and increments the content by one. Each reader
also periodically reads the content of the buffer, and prints the current value
along with its own PID. The writer and reader should be implemented as separate
processes. Use shared memory to implement the shared buffer and use
semaphore(s) in order to ensure proper synchronization between the reader and
writer processes. The program terminates when the writer writes MAX to VAR.
Notice that both readers can access the shared content together. The reader
who first makes a read operation should lock the shared content for reading.
During the time the shared content is locked for reading, the other reader can
read it. The last reader done with reading releases the lock. The writer can
write only when no reader is reading the shared content. Finally, before the
writer finishes writing, no reader can read.  

You can insert appropriate delays, e.g., sleep() , so that the messages become
visible. Here is a sample run for the writer with PID 123, and the readers with
PIDs 124 and 125:

```
The first reader acquires the lock.
The reader (124) reads the value 0
The last reader releases the lock.
The writer acquires the lock.
The writer (123) writes the value 1
The writer releases the lock.
The first reader acquires the lock.
Reader (125) reads the value 1
Reader (124) reads the value 1
The last reader releases the lock.
```
