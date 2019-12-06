MAIN=main

all: compile run

run:
	./$(MAIN)

compile: fonction.o main.o
	g++ -o $(MAIN) main.o fonction.o
	
main.o: main.cpp
	g++ -o main.o -c main.cpp -Wall

clean:
	rm -rf *.o
	rm -f $(MAIN)
