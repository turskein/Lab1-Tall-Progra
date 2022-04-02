#ifndef Nodo_
#define Nodo_
#include <iostream>

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
    //Constructores
    Node();
    Node(int c, int prevX, int prevY);
    Node(int c, int prevX, int prevY, int nextX, int nextY);
    ~Node();

    //Getters
    int getC();
    int getPrevX();
    int getPrevY();
    int getState();
    
    //Cuestionadores
    bool isVisited();
    /*
    bool canGoNorth();
    bool canGoSouth();
    bool canGoEast();
    bool canGoWest
    bool canGoNorth();
    bool canGoNorth();
    */

    //Setters
    void setPrev(int prevX, int prevY);
    void setState(int newState);
    void setVisited();
    void setC(int newc);
    void betterPrev(int theC, int prevX, int prevY);
};

#endif