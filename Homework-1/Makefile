# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 06-02-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P1=1
P2=2
OBJ1=1.o
OBJ2=2.o
LIB=
MLIB=-lrt

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=$(MLIB)
endif
ASFLAGS=-Wall -O0 -g

HW_NO=1

all: $(P1) $(P2) archive
$(P1): $(OBJ1)
$(P2): $(OBJ2)

.PHONY: archive
archive:
	tar cvfz os_assigment${HW_NO}_group20.tgz \
		1.c 2.c 2.help file.txt Makefile
.PHONY: clean
clean:
	rm 1.o 2.o 1 2
