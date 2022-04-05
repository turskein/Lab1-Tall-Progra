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
    /*Obtiene el valor del nodo superior*/
    int peek();
    /*Consigue el tamanio del container*/
    int getSize();
    /*muestra en pantalla como se encuentra el container*/
    void print();
private:
    NodeH *arr; // array que contendra todos los nodos
    int size; // tamanio del arreglo
    int count; // contador de elementos
    void swap(int i, int j); // realizador de intercambios dentro del contenedor entre dos nodos en particular
    void bubbleUp(); // Desplaza de hacia arriba datos en particular dentro del arbol
    void bubbleDown(); // Desplaza de hacia abajo datos en particular dentro del arbol
};
