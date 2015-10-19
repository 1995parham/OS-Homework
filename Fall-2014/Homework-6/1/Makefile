# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 20-01-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=HDD
OBJ=main.o show.o hdd.o
LIB=
MLIB=

ifdef LIB
CFLAGS=-Wall -O0 -g -std=gnu11 \
       $(shell pkg-config --cflags $(LIB))
LDLIBS=$(shell pkg-config --libs $(LIB)) $(MLIB)
else
CFLAGS=-Wall -O0 -g -std=gnu11
LDLIBS=$(MLIB)
endif
ASFLAGS=-Wall -O0 -g

$(P): $(OBJ)
	$(CC) -o $(P) $(OBJ) $(LDLIBS)
main.o: hdd.h
show.o: show.h hdd.h
hdd.o: hdd.h show.h

.PHONY: clean
clean:
	rm $(OBJ) $(P)
