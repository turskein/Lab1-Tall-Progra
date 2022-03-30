test1: Maze.o Node.o Stack.o Heap.o test_Maze_1.cpp
	g++ Node.o Stack.o Heap.o Maze.o test_Maze_1.cpp -o testg

Maze.o: Maze.cpp Maze.h Heap.cpp Heap.o Node.o Node.h Node.cpp Stack.o Stack.cpp Stack.h
	g++ -c Maze.cpp

Heap.o: Heap.cpp Heap.o Node.o Node.h Node.cpp Stack.o Stack.cpp Stack.h
	g++ -c Heap.cppx

Stack.o: Stack.cpp Stack.h
	g++ -c Stack.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

run:
	./testg