a.out: EX1.o Number.o
	c++ EX1.o Number.o

EX1.o: EX1.cpp Number.h
	c++ -c EX1.cpp

Number.o: Number.h Number.cpp
	c++ -c Number.cpp

clean:
	rm -f *.o core a.out
