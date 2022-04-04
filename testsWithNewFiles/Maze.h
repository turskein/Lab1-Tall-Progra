#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Arbol.h"
#include "Container.h"


using namespace std;

// best practice:
#define IN_DOOR 2
#define OUT_DOOR 3
#define WALL 1
#define EMPTY 0

/*Matriz estatica que representa un laberinto con espacios y paredes
 aleatorias. Su entrada esta siempre seteada en la coordenada (0,0)
  y la salida en (dim-1,dim-1), considerando que dim es el largo de 
  la matriz*/
class Maze {
public:
    /*Contructor de laberinto*/
    Maze(int dim, int p);
    /*Destructor de laberinto*/
    ~Maze();
    /*Imprime el laberinto por pantalla*/
    void print();
    /*Resuelve el laberinto, senialando su camino en los nodos de route*/
    bool solve();
    /*Randomiza el laberinto, resetenado cada nodo y desapareciendo la ruta preexistente*/
    void generate();
    /*Muestra la ruta que existe en la ruta*/
    void showRoute();
    /*Analiza un nodo en particular dentro de la ruta, verificando sus diferentes direcciones*/
    bool analyseNode(Container *xVisit, int x, int y, int c);
    /*Analiza la direccion de abajo, verificando si es distinto de una pared y en caso de ser asi, agregarlo como visitado y agregarlo a la cola*/
    void goDown(Container *xVisit, int x, int y, int c);
    /*Analiza la direccion de la derecha, verificando si es distinto de una pared y en caso de ser asi, agregarlo como visitado y agregarlo a la cola*/
    void goRight(Container *xVisit, int x, int y, int c);
    /*Analiza la direccion de arriba, verificando si es distinto de una pared y en caso de ser asi, agregarlo como visitado y agregarlo a la cola*/
    void goUp(Container *xVisit, int x, int y, int c);
    /*Analiza la direccion de la izquierda, verificando si es distinto de una pared y en caso de ser asi, agregarlo como visitado y agregarlo a la cola*/
    void goLeft(Container *xVisit, int x, int y, int c);

private :
    // largo de la matriz
    int dim;
    // matriz que representa el laberinto
    int **arr;
    // Porcentaje de vacio que se presenta en el laberinto 
    int void_percentage;
    // Nodos visitados y expresion de camino a la salida
    Arbol route;
};