#include "Node.h"

class Heap{
private:
    int dim;
    Node **matriz;
public:
    Heap(int dim);
    ~Heap();
    bool addCoor(int x, int y);
    bool exist(int x, int y);
};