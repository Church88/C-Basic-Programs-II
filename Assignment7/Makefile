a.out: main.o ai.o move.o board.o
	c++ main.o ai.o move.o board.o
	
main.o: main.cc ai.h board.h
	c++ -c -g main.cc
	
move.o: move.cc move.h
	c++ -c -g move.cc
	
board.o: board.cc board.h
	c++ -c -g board.cc
	
ai.o: ai.cc ai.h
	c++ -c -g ai.cc
	
clean:
	rm -f *.o core a.out