CC = g++

all: Board.o Snake.o Square.o basics.o main.o
	$(CC) Board.o Snake.o Square.o basics.o main.o -lglut -lGL -o glutSnake

basics.o: basics.h basics.cc
	$(CC) basics.cc -c -lglut -lGL -o basics.o

Square.o: Square.cc Square.h
	$(CC) Square.cc -c -lglut -lGL -o Square.o

Snake.o: Snake.cc Snake.h
	$(CC) Snake.cc -c -lglut -lGL -o Snake.o

Board.o: Board.cc Board.h
	$(CC) Board.cc -c -lglut -lGL -o Board.o

main.o: main.cc
	$(CC) main.cc -c -lglut -lGL -o main.o

clean: 
	rm *.o
