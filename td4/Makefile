all: compile run

run:
	./main

compile: fonction.o main.o
	g++ -o main main.o fonction.o

fonction.o: fonction.cc
	g++ -o fonction.o -c fonction.cc -Wall

main.o: main.cc
	g++ -o main.o -c main.cc -Wall

clean:
	rm -rf *.o
	rm -rf main
