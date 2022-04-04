#include "NodeH.h"

NodeH::NodeH() {
    this->i = 0;
    this->j = 0;
    this->value = 0;
    //this->depth = -1;
    //this->previous = NULL;
}

NodeH::NodeH(NodeH* NodeH) {
    this->i = NodeH->i;
    this->j = NodeH->j;
    this->value = NodeH->value;
    //this->depth = NodeH->depth;
    //this->previous = NodeH->previous;
}

NodeH::NodeH(int i, int j, int value, NodeH* parent) {
    this->i = i;
    this->j = j;
    this->value = value;
    //this->previous = parent;
}

NodeH::~NodeH () {
}

int NodeH::get_i() {
    return this->i;
}

int NodeH::get_j() {
    return this->j;
}

/*
NodeH* NodeH::getPrevious() {
    return this->previous;
}
*/

int NodeH::getValue() {
    return this->value;
}

/*
void NodeH::setPrevious(NodeH* previous) {
    this->previous = previous;
}


void NodeH::setDepth(int depth) {
    this->depth = depth;
}

int NodeH::isRoot() {
    return this->previous == NULL;
}
*/
void NodeH::print() {
    cout << "(" << this->i << "," << this->j << ")[" << this->value << "]" << endl;
}
/*
int NodeH::getDepth() {
    return(this->depth);    
}

// the path from the root to the current NodeH as a string
string NodeH::getPath() {
    string s="("+to_string(this->i)+","+to_string(this->j)+")";
    if (this->previous != NULL) {
        s=s+this->previous->getPath();
    }
    return(s); 
}
*/