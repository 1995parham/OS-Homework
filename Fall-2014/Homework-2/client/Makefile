GCC = gcc -gstabs+
RM = rm -f
TAR = tar

HW_NO  = 2

all:
	${MAKE} client
client:
	${GCC} -c *.c
	${GCC} -o client *.o
clean:
	${RM} *.o
	${RM} client
