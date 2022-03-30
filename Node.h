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
    int x, y, c;//, r, l ,u, d;
    Node *previous, *next;
public:
    //Constructores
    Node();
    Node(int x, int y);
    Node(int x, int y, int c, Node *previous);
    Node(int x, int y, Node *previous);
    Node(int x, int y, Node *previous, Node *next);
    ~Node();

    //Getters
    int getX();
    int getY();
    int getC();
    Node* getPrevious();
    Node* getNext();
    
    //Cuestionadores
    bool isVoid();
    int sameCoor(int thex, int they);
    /*
    bool canGoNorth();
    bool canGoSouth();
    bool canGoEast();
    bool canGoWest
    bool canGoNorth();
    bool canGoNorth();
    */

    //Setters
    void setCoor(int newx, int newy);
    void setPrevious(Node *newPrevious);
    void setNext(Node *newNext);
    void setVoid();
    void setC(int newc);
    void betterPrevious(int c, Node *previous);
};

#endif