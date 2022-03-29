#include "Node.h"

using namespace std;

class Heap{
private:
    int dim;
    Node **matriz;
public:
    Heap(int dim);
    ~Heap();
    bool addCoor(int x, int y, int c, int px, int py);
    bool exist(int x, int y);
    void getWay(int lastx, int lasty);
    void show();
};