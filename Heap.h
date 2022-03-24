#include "Node.h"

class Heap{
private:
    int dim;
    Node **matriz;
public:
    Heap(int dim);
    void addCoor(int x, int y);
    bool exist(int x, int y);
};