#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Heap.h"
#include "Stack.h"

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
    void solve(); // solve best path
    void generate(); // generate random maze
    void showRoute();
private:
    int dim;
    int **arr;
    int void_percentage;
    Heap route = Heap(1);
};