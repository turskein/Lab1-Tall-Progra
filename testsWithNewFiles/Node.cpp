#include "Node.h"


/*Constructor de nodos con coordenadas no
ingresadas*/
Node::Node(){
    Node::c = -1;
    Node::state = 0;
    Node::prevX = -1;
    Node::prevY = -1;
    Node::visited = false;
}

/*Constructor de nodos con coordenadas
ingresadas*/
Node::Node(int c, int prevX, int prevY){
    Node::c = c;
    Node::state = 0;
    Node::prevX = prevX;
    Node::prevY = prevY;
    Node::visited = false;
}

/*Destructor*/
Node::~Node(){
}

/*Retorna si el nodo esta visitado o no*/
bool Node::isVisited(){
    return this->visited;
}

void Node::reset(){
    c = -1;
    state = 0;
    prevX = -1;
    prevY = -1;
    visited = false;
};

/*Setea las coordenadas del nodo anterior a este*/
void Node::setPrev(int prevX, int prevY){
    this->prevX = prevX;
    this->prevY = prevY;
}

/*Setea el estado de este*/
void Node::setState(int newState){
    state = newState;
};

/*Setea el costo de este nodo*/
void Node::setC(int newc){
    c = newc;
}

/*Setea true visited*/
void Node::setVisited(){
    this->visited = true;
}

/*Retorna el estado del nodo, es decir, si pertenece o no al camino.
Solo aparecera como parte del camino luego de emplear getWay en la 
ruta del maze*/
int Node::getState(){
    return state;
}
/*Retorna la coordenada x del nodo que precede a este*/
int Node::getPrevX(){
    return prevX;
}

/*Retorna la coordenada y del nodo que precede a este*/
int Node::getPrevY(){
    return prevY;
}

/*retorna el costo de este nodo*/
int Node::getC(){return c;}
