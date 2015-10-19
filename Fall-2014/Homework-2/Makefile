GCC = gcc
LINUX_LIB = -lpthread
RM = rm -f
TAR = tar

HW_NO  = 2

all:
	${MAKE} -B client server
	${MAKE} tar 
client:
	cd client/; ${MAKE}
server:
	cd server/; ${MAKE}
tar:
	${RM} *.tgz
	${TAR} cvfz os_assigment${HW_NO}_group20.tgz client/ server/ Makefile
clean:
	cd client/; ${MAKE} clean
	cd server/; ${MAKE} clean
	${RM} *.tgz
