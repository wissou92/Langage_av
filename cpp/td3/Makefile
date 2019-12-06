.PHONY: run compile main.o Point.o

run: clean compile
	./main

compile: Point.o main.o  
	g++ Point.o main.o -o main

Point.o: Point.cc
	g++ -c Point.cc -o Point.o -Wall

main.o: main.cc
	g++ -c main.cc -o main.o -Wall

clean:
	rm -rf *.o main