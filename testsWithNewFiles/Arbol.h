#include "Node.h"

using namespace std;


#define GREEN "\033[32m" // Colores que definen paredes y caminos
#define RED "\033[31m"
#define RESET "\033[0m"

/*Matriz que expresa el estado en el que se encuentra,
el estado en el que se encuentra cada nodo, si hay sido
recorrido o no y, ademas cuales son sus nodos anteriores*/
class Arbol{
private:
    int dim; //tamanio de la matriz
    Node **matriz; // matriz donde se presentan los nodos correlativos al laberinto
public:
    Arbol(); //constructor vacio
    Arbol(int dim); // contructor relleno
    ~Arbol(); // destructor
    void resetNode(int i, int j);
    void generate(int dim);
    bool addCoor(int x, int y, int c, int prevX, int prevY);
    bool isVisited(int x, int y);
    void getWay(int **maze);
    void show();
};