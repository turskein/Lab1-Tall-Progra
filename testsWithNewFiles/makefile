EVERYDOTO = *.o

main: Node.o NodeH.o Container.o Arbol.o Maze.o main.cpp
	g++ Node.o NodeH.o Container.o Arbol.o Maze.o main.cpp -o main

maze: Node.o NodeH.o Container.o Arbol.o Maze.o test_Maze_1.cpp
	g++ Node.o NodeH.o Container.o Arbol.o Maze.o test_Maze_1.cpp -o maze

arbol: Node.o Arbol.o test_Arbol_1.cpp
	g++ Node.o Arbol.o test_Arbol_1.cpp -o arbol

container: Container.o NodeH.o test_Container_1.cpp
	g++ Container.o NodeH.o test_Container_1.cpp -o container

node: Node.o
	g++ Node.o test_Node_1.cpp -o node

Maze.o: Maze.h Maze.cpp
	g++ -c Maze.cpp

Arbol.o: Arbol.h Arbol.cpp
	g++ -c Arbol.cpp
	
Container.o: Container.cpp Container.h
	g++ -c Container.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

NodeH.o: NodeH.cpp NodeH.h
	g++ -c NodeH.cpp

clean:
	rm $(EVERYDOTO)

runmaze: maze
	./maze

run: main
	./main

runcontainer: container
	./container

runnode: node
	./node

runarbol: arbol
	./arbol
