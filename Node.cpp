#include "Node.h"

Node::Node(int x, int y){
    Node::x = x;
    Node::y = y;
    Node::r = 1;
    Node::l = 1;
    Node::u = 1;
    Node::d = 1;
}
Node::Node(){
    Node::x = -1;
    Node::y = -1;
}

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

int Node::sameCoor(int thex, int they){
    if(thex == x && they == y){
        return SAME;
    }
    if(thex == x)return SAMEX;
    if(they == y)return SAMEY;
    return DIFF;
}