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
    int c, prevX, prevY, nextX, nextY;
    bool visited;
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
    int getNextX();
    int getNextY();
    
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

    void setPrev(int prevX, int prevY);
    //Setters
    void setNext(int nextX, int nextY);
    void setVisited();
    void setC(int newc);
    void betterPrev(int theC, int prevX, int prevY);
};

#endif