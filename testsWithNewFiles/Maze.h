#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Arbol.h"
#include "Heap.h"


using namespace std;

// best practice:
#define IN_DOOR 2
#define OUT_DOOR 3
#define WALL 1
#define EMPTY 0

class Maze {
public:
    Maze(int dim, int p);
    ~Maze();
    void print();
    bool solve(); // solve best path
    void generate(); // generate random maze
    void showRoute();
    bool analyseNode(Heap *xVisit, int x, int y, int c);
    void goDown(Heap *xVisit, int x, int y, int c);
    void goRight(Heap *xVisit, int x, int y, int c);
    void goUp(Heap *xVisit, int x, int y, int c);
    void goLeft(Heap *xVisit, int x, int y, int c);

private : int dim;
    int **arr;
    int void_percentage;
    Arbol route;
};