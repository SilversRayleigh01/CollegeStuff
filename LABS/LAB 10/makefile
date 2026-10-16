client.exe : client.o tree.o queue.o
	gcc client.o tree.o queue.o -o client.exe

queue.o : queue.c queue.h
	gcc -Wall -c queue.c

tree.o : tree.c tree.h queue.h
	gcc -Wall -c tree.c

client.o : client.c tree.h
	gcc -Wall -c client.c

clean:
	rm -f *.o client.exe