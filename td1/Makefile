all:

run:
	./main

main:  main.o test.o td1.o
	g++ -o main main.o td1.o test.o

test.o: test.cc td1.h
	g++ -o test.o -c test.cc -Wall

td1.o: td1.cc class.h
	g++ -o td1.o -c td1.cc -Wall

main.o: main.cc test.h
	g++ -o main.o -c main.cc -Wall
clean:
	rm -rf *.o
