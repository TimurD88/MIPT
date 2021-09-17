main.o: main.c
	gcc -c  main.c -lm

func.o: func.c
	gcc -c  func.c -lm

test.o: test.c
	gcc -c test.c
	
run: main.o func.o test.o
	gcc -o  run main.o  func.o test.o -lm
	rm  -rf *.o

all: run
