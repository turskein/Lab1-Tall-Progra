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

//Destructor del nodo
Node::~Node(){
}

//Cuestiona si el nodo ha sido visitado o no
bool Node::isVisited()
{
    return this->visited;
}

// Setea los valores del nodo como si fuera nuevo
void Node::reset(){
    c = -1;
    state = 0;
    prevX = -1;
    prevY = -1;
    visited = false;
};


//Setea las coordenadas del nodo anterior
void Node::setPrev(int prevX, int prevY)
{
    this->prevX = prevX;
    this->prevY = prevY;
}

// setea el estado del nodo
void Node::setState(int newState){
    state = newState;
};

// Setea el costo del nodo
void Node::setC(int newc){
    c = newc;
}

//setea como visitado el nodo 
void Node::setVisited()
{
    this->visited = true;
}

//getter estado del nodo
int Node::getState(){
    return state;
}
// getter coordenada x del previo
int Node::getPrevX(){
    return prevX;
}

// getter coordenada y del previo
int Node::getPrevY(){
    return prevY;
}

// getter costo

int Node::getC(){
    return c;
}
