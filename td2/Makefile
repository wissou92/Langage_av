MAIN=main

.PHONY: compile main clean

run: compile
	clear
	./$(MAIN)

compile: $(MAIN)

$(MAIN): vector.o main.o
	g++ -o $(MAIN) main.o vector.o
	
vector.o: vector.cc vector.h
	g++ -c vector.cc -o vector.o -Wall

main.o: main.cc vector.h
	g++ -c main.cc -o main.o -Wall
	
clean:
	rm -rf *.o $(MAIN)
