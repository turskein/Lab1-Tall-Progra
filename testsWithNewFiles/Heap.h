#include <iostream>
#include <math.h>
#include "NodeH.h"
using namespace std;

/*
Please document your code here.
*/    
class Heap {
public:
    Heap(int size);
    ~Heap();
    int isEmpty();
    void insert(NodeH *NodeH);
    NodeH* pull();
    int peek();
    int getSize();
    void print();
private:
    NodeH *arr;
    int size;
    int count;
    void swap(int i, int j);
    void bubbleUp();
    void bubbleDown();
};
