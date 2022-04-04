EVERYDOTO = *.o

main: Node.o NodeH.o Heap.o Arbol.o Maze.o main.cpp
	g++ Node.o NodeH.o Heap.o Arbol.o Maze.o main.cpp -o main

maze: Node.o NodeH.o Heap.o Arbol.o Maze.o test_Maze_1.cpp
	g++ Node.o NodeH.o Heap.o Arbol.o Maze.o test_Maze_1.cpp -o maze

arbol: Node.o Arbol.o test_Arbol_1.cpp
	g++ Node.o Arbol.o test_Arbol_1.cpp -o arbol

heap: Heap.o NodeH.o test_Heap_1.cpp
	g++ Heap.o NodeH.o test_Heap_1.cpp -o heap

node: Node.o
	g++ Node.o test_Node_1.cpp -o node

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

runmain:
	./main

runheap:
	./heap

runnode:
	./node

runheap:
	./arbol
