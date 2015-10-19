GCC = gcc
LINUX_LIB = -lpthread
RM = rm -f
TAR = tar

HW_NO  = 3

all:
	${MAKE} 1 
	${MAKE} tar
1:
	${GCC} -o 1.o -c 1.c
	${GCC} -o 1 1.o ${LINUX_LIB}
tar:
	${RM} *.tar.gz
	${TAR} cvfz os_assigment${HW_NO}_group20.tgz *.c Makefile
clean:
	${RM} *.o
	${RM} 1
