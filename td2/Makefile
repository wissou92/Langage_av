MAIN=main

.PHONY: compile main clean

compile: $(MAIN)

$(MAIN): main.o vector.o
	g++ -o $(MAIN) main.o vector.o
	
vector.o: vector.cc
	g++ -c vector.cc -o vector.o -Wall

main.o: main.cc vector.h
	g++ -c main.cc -o main.o -Wall
	
clean:
	rm -rf *.o
