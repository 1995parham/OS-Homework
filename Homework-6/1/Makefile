OBJ=hdd.o main.o show.o
CFLAGS=-Wall -std=c99
HDD: $(OBJ)
	gcc $(CFLAGS) -o HDD.out $(OBJ)
main.o: main.c hdd.h
	gcc $(CFLAGS) -c main.c
hdd.o: hdd.c hdd.h show.h
	gcc $(CFLAGS) -c hdd.c
show.o: show.c show.h hdd.h
	gcc $(CFLAGS) -c show.c
.PHONY:clean
clean:
	rm $(OBJ) HDD.out
