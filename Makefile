main.o: main.c
	gcc -c  main.c

func.o: func.c
	gcc -c  func.c -lm

run: main.o func.o
	gcc -o  run main.o  func.o -lm
	rm  -rf *.o

all: run
