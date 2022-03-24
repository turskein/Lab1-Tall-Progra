#include <iostream>
#include <stdlib.h>

#define RIGHT 0
#define LEFT 1
#define UP 2
#define DOWN 3

class Node{
private:
    int x, y, r, l ,u, d;
public:
    Node();
    Node(int x, int y);
    void setOpen(int adre, int kind);
};