CC=gcc
TARGET=main 

all: try run
try: main.o BST.o Stack.o
	$(CC) main.o BST.o Stack.o -o $(TARGET)
main.o: main.c BST.h Stack.h
	$(CC) -c main.c
BST.o: BST.c Stack.c
	$(CC) -c BST.c
Stack.o: Stack.c
	$(CC) -c Stack.c
run: $(TARGET)
	./main
clean:
	rm -rvf *.o $(TARGET)

