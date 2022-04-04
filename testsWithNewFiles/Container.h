#include <iostream>
#include <math.h>
#include "NodeH.h"
using namespace std;

/*
Contenedor que mantendra con un criterio determinado diferentes nodos dentro de el, este criterio se basa en mantener el nodo con mayor valor en la parte superior
*/    
class Container {
public:
    /*Constructor de container*/
    Container(int size);
    /*Destructor de container*/
    ~Container();
    /*Verifica si esta vacio o no*/
    int isEmpty();
    /*Inserta un nuevo nodo dentro del container*/
    void insert(NodeH *NodeH);
    /*Retirar el elemento de la cima*/
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
