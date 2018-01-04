a.out: main.o
	c++ main.o

main.o: main.cc flatten.h
	c++ -c main.cc

clean:
	rm -f *.o core a.out
