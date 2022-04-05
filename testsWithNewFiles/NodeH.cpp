#include "NodeH.h"
//Constructor vacio
NodeH::NodeH() {
    this->i = 0;
    this->j = 0;
    this->value = 0;
}
// Constructor segun valores senialados
NodeH::NodeH(int i, int j, int value) {
    this->i = i;
    this->j = j;
    this->value = value;
}
//Destructor
NodeH::~NodeH () {
}

//Getter de la coordenada x
int NodeH::get_i()
{
    return this->i;
}
// Getter de la coordenada y
int NodeH::get_j() {
    return this->j;
}

// Getter del costo correspondiente a este nodo
int NodeH::getValue() {
    return this->value;
}