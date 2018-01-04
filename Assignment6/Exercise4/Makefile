a.out: main.o
	c++ main.o

main.o: main.cc insert.h
	c++ -c main.cc

clean:
	rm -f *.o core a.out
