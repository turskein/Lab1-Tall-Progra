#include "Node.h"

using namespace std;

class Arbol{
private:
    int dim;
    Node **matriz;
public:
    Arbol();
    Arbol(int dim);
    ~Arbol();

    void generate(int dim);
    bool addCoor(int x, int y, int c, int prevX, int prevY);
    bool isVisited(int x, int y);
    void getWay();
    void show();
};