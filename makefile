EVERYDOTO = *.o

test1: Maze.o Node.o Stack.o Arbol.o test_Maze_1.cpp
	g++ Node.o Stack.o Arbol.o Maze.o test_Maze_1.cpp -o testg

Maze.o: Maze.cpp Maze.h Arbol.cpp Arbol.o Node.o Node.h Node.cpp Stack.o Stack.cpp Stack.h
	g++ -c Maze.cpp

Arbol.o: Arbol.cpp Node.o Node.h Node.cpp Stack.o Stack.cpp Stack.h
	g++ -c Arbol.cpp

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm $(EVERYDOTO)

run:
	./testg