# In The Name Of God
# ========================================
# [] File Name : Makefile
#
# [] Creation Date : 09-02-2015
#
# [] Created By : Parham Alvani (parham.alvani@gmail.com)
# =======================================

P=1
OBJ=main.o logical.o page_table.o memory.o mmu.o
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
	./memory.sh

main.o: logical.h mmu.h page_table.h memory.h logical.o mmu.o page_table.h memory.o
logical.o: logical.c logical.h
page_table.o: page_table.h
memory.o: memory.h
mmu.o: mmu.h logical.h logical.o

.PHONY: clean
clean:
	rm $(P) $(OBJ) memory
