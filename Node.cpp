#include "Node.h"


/*Constructor de nodos con coordenadas
ingresadas*/
Node::Node(int x, int y){
    Node::x = x;
    Node::y = y;
    Node::c = -1;
    Node::previous = NULL;
    Node::next = NULL;
}

Node::Node(int x, int y, int c, Node *previous){
    Node::x = x;
    Node::y = y;
    Node::c = c;
    Node::previous = previous;
    Node::next = NULL;
}

/*Constructor de nodos asumiendolo como vacio*/
Node::Node(){
    Node::x = -1;
    Node::y = -1;
    Node::c = -1;
    Node::previous = NULL;
    Node::next = NULL;
}

Node::Node(int x, int y, Node *previous){
    Node::x = x;
    Node::y = y;
    Node::c = -1;
    Node::previous = previous;
    Node::next = NULL;
}

Node::Node(int x, int y, Node *previous, Node *next){
    Node::x = x;
    Node::y = y;
    Node::c = -1;
    Node::previous = previous;
    Node::next = next;
}

Node::~Node(){
}

/*
void Node::setOpen(int adre, int kind){
    switch (adre){
    case RIGHT:
        r = kind;
        break;
    case LEFT:
        l = kind;
        break;
    case UP:
        u = kind;
        break;
    case DOWN:
        d = kind;
        break;
    default:
        break;
    }
}
*/
/*Verifica si las coordenadas ingresadas coinciden
con las del nodo. En caso de ser ambas coordenadas
iguales se retorna SAME (3); solo x igual, SAMEX 
(1); solo y igual, SAMEY (2) y, si ninguno es igual
DIFF (0)*/
int Node::sameCoor(int thex, int they){
    if(thex == x && they == y){
        return SAME;
    }
    if(thex == x)return SAMEX;
    if(they == y)return SAMEY;
    return DIFF;
}

/*Verifica si el nodo esta vacio, si el nodo tiene
los valores de x=-1 e y=-1 se asume vacio*/
bool Node::isVoid(){
    if(x == -1 || y == -1) return true;
    return false;
}

/*Cambio las coordenadas de este nodo por los
ingresado*/
void Node::setCoor(int newx, int newy){
    x = newx;
    y = newy;
}

/*Vacia el nodo, es decir, los valores de x e y
los igual a -1*/
void Node::setVoid(){
    x = -1;
    y = -1;
}

void Node::setPrevious(Node *previous){
    this->previous = previous;
}

void Node::setNext(Node *next){
    this->previous = previous;
}

void Node::setC(int newc){
    c = newc;
}

void Node::betterPrevious(int c, Node *previous){
    if(c < this->c){
        this->previous = previous;
        this->c = c;
    }
}

/*retorna la coordenada x*/
int Node::getX(){ return x;}

/*retorna la coordenada y*/
int Node::getY(){ return y;}
/*Retorna la coordenada x del nodo que precede a este*/
Node* Node::getPrevious(){
    return this->previous;
}

Node* Node::getNext(){
    return this->next;
}

/*retorna el costo de este nodo*/
int Node::getC(){return c;}
