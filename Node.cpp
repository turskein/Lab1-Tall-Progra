#include "Node.h"


/*Constructor de nodos con coordenadas
ingresadas*/
Node::Node(){
    Node::c = -1;
    Node::prevX = -1;
    Node::prevY = -1;
    Node::nextX = -1;
    Node::nextY = -1;
    Node::visited = false;
}

Node::Node(int c, int prevX, int prevY){
    Node::c = c;
    Node::prevX = prevX;
    Node::prevY = prevY;
    Node::nextX = -1;
    Node::nextY = -1;
    Node::visited = false;
}

Node::Node(int c, int prevX, int prevY, int nextX, int nextY){
    Node::c = c;
    Node::prevX = prevX;
    Node::prevY = prevY;
    Node::nextX = nextX;
    Node::nextY = nextY;
    Node::visited = false;
}

Node::~Node(){
}

/*Verifica si las coordenadas ingresadas coinciden
con las del nodo. En caso de ser ambas coordenadas
iguales se retorna SAME (3); solo x igual, SAMEX 
(1); solo y igual, SAMEY (2) y, si ninguno es igual
DIFF (0)*/

/*Verifica si el nodo esta vacio, si el nodo tiene
los valores de x=-1 e y=-1 se asume vacio*/
bool Node::isVisited(){
    return this->visited;
}

/*Vacia el nodo, es decir, los valores de x e y
los igual a -1*/

void Node::setPrev(int prevX, int prevY){
    this->prevX = prevX;
    this->prevY = prevY;
}

void Node::setNext(int nextX, int nextY){
    this->nextX = nextX;
    this->nextY = nextY;
}

void Node::setC(int newc){
    c = newc;
}

void Node::setVisited(){
    this->visited = true;
}

void Node::betterPrev(int theC, int prevX, int prevY){
    if(theC < c){
        setPrev(prevX, prevY);
        this->c = theC;
    }
}

/*Retorna la coordenada x del nodo que precede a este*/
int Node::getPrevX(){
    return prevX;
}

int Node::getPrevY(){
    return prevY;
}

int Node::getNextX(){
    return nextX;
}

int Node::getNextY(){
    return nextY;
}
/*retorna el costo de este nodo*/
int Node::getC(){return c;}
