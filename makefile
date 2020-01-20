all: SimpleCrypto

SimpleCrypto: main.o crypto.o
	gcc main.o crypto.o -o SimpleCrypto

main.o: main.c
	gcc -c main.c

crypto.o: crypto.c
	gcc -c crypto.c

clean:
	rm *.o SimpleCrypto
