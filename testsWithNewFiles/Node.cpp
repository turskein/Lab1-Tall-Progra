#include "Node.h"

Node::Node() {
    this->i = 0;
    this->j = 0;
    this->value = 0;
    this->depth = -1;
    this->previous = NULL;
    this->next = NULL;
}

Node::Node(Node* node) {
    this->i = node->i;
    this->j = node->j;
    this->value = node->value;
    this->depth = node->depth;
    this->previous = node->previous;
    this->next = node->next;
}

Node::Node(int i, int j, int value, Node* parent) {
    this->i = i;
    this->j = j;
    this->value = value;
    this->previous = parent;
}

Node::~Node () {
}

int Node::get_i() {
    return this->i;
}

int Node::get_j() {
    return this->j;
}

Node* Node::getPrevious() {
    return this->previous;
}

Node* Node::getNext(){
    return this->next;
}

int Node::getValue() {
    return this->value;
}

void Node::setPrevious(Node* previous) {
    this->previous = previous;
}

void Node::setNext(Node* next){
    this->next = next;
}

void Node::setDepth(int depth) {
    this->depth = depth;
}

int Node::isRoot() {
    return this->previous == NULL;
}

void Node::print() {
    cout << "(" << this->i << "," << this->j << ")[" << this->value << "]" << endl;
}

int Node::getDepth() {
    return(this->depth);    
}

// the path from the root to the current node as a string
string Node::getPathPrevious() {
    /*
    string s="("+to_string(this->i)+","+to_string(this->j)+")";
    if (this->previous != NULL) {
        s=s+this->previous->getPath();
    }
    return(s); 
    */

    return "("+to_string(this->i)+","+to_string(this->j)+")"+(this->previous != NULL ? this->previous->getPathPrevious():"");
}

string Node::getPathNext() {
    return "("+to_string(this->i)+","+to_string(this->j)+")"+(this->next != NULL ? this->next->getPathNext():"");
}
