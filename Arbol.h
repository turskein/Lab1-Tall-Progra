#include "Node.h"

using namespace std;

class Arbol{
private:
    int dim;
    Node **matriz;
public:
    Arbol(int dim);
    ~Arbol();
    bool addCoor(int x, int y, int c, Node *previous);
    bool exist(int x, int y);
    void getWay(int lastx, int lasty);
    void show();
};