default: simple11

simple11: simple11.o
	gcc -o simple11 simple11.o -lpthread

simple11.o: simple11.c
	gcc -c simple11.c

clean:
	rm simple11 *.o