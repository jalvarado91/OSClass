default: simple12
synced: simple12sync

simple12: simple12.o
	gcc -o simple12 simple12.o -lpthread

simple12.o: simple12.c
	gcc -c simple12.c

simple12sync: simple12sync.o
	gcc -o simple12 simple12.o -lpthread

simple12sync.o: simple12.c
	gcc -D PTHREAD_SYNC -c simple12.c

clean:
	rm simple12 *.o
