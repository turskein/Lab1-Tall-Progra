EVERYDOTO = *.o

test_Heap_1: Node.o NodeH.o Heap.o Arbol.o Maze.o test_Heap_1.cpp
	g++ Node.o NodeH.o Heap.o Arbol.o Maze.o test_Maze_1.cpp -o a

Maze.o: Maze.h Maze.cpp
	g++ -c Maze.cpp

Arbol.o: Arbol.h Arbol.cpp
	g++ -c Arbol.cpp
	
Heap.o: Heap.cpp Heap.h
	g++ -c Heap.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

NodeH.o: NodeH.cpp NodeH.h
	g++ -c NodeH.cpp

clean:
	rm $(EVERYDOTO)

run:
	./a
