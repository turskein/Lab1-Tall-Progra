#ifndef Nodo_
#define Nodo_
#include <iostream>

using namespace std;

#define RIGHT   0
#define LEFT    1
#define UP      2
#define DOWN    3
#define SAMEX   1
#define SAMEY   2
#define SAME    3
#define DIFF    0
#define OPEN    1
#define CLOSE   0

/*Representacion abstracta de dos coordenadas
en un nodo*/
class Node {
private:
    int c; //costo del nodo
    int prevX; // Coordenada x del nodo anterior a este
    int prevY; // Coordenada y del nodo anterior a este
    int state;  // Se refiere a si es parte del camino o no
    bool visited; // Fue visitado o no, 1 o 0 respectivamente
public:
    //Constructor con valores vacios
    Node();
    // Constructor con c costo del nodo, prevX coordenada x de nodo anterior y prevY coordenada y del nodo anterior
    Node(int c, int prevX, int prevY);
    //Destructor del nodo
    ~Node();

    //getter costo
    int getC();
    // getter coordenada x del previo
    int getPrevX();
    // getter coordenada y del previo
    int getPrevY();
    // getter estado del nodo
    int getState();
    
    //Cuestiona si el nodo ha sido visitado o no
    bool isVisited();

    //Setea los valores del nodo como si fuera nuevo
    void reset();
    // Setea las coordenadas del nodo anterior
    void setPrev(int prevX, int prevY);
    // setea el estado del nodo
    void setState(int newState);
    // setea como visitado el nodo
    void setVisited();
    // Setea el costo del nodo
    void setC(int newc);
};

#endif