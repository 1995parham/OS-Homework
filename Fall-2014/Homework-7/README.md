# Assignment 7 - Kernel Module Programming

The goal of this assignment is to create a special file in the /dev and make
it behave like a FIFO. Data written to this special file is stored in an internal
buffer. When a user space program reads from the corresponding device file,
the data in the buffer is returned in a first-in-first-out fashion. Your task is to
write a kernel module that handles the read and write operations of this special
file. To implement the buffer, it is sufficient to use a static array of a fixed size.
Take care of boundary conditions like empty or full buffers and handle them in
a sensible way. You can test your module via the new device file using cat (for
reading) and echo (for writing):

```bash
echo "123" > /dev/myfifo # Write "123" to the FIFO device file
echo "456" > /dev/myfifo # Wrtie "456" to the FIFO device file
cat /dev/myfifo
# Read from the FIFO file
# The cat output:
123
456
```
