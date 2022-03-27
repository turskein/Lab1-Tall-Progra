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

class Node {
private:
    int x, y;//, r, l ,u, d;
public:
    Node();
    Node(int x, int y);
    int getX();
    int getY();
    bool isVoid();
    void setOpen(int adre, int kind);
    int sameCoor(int thex, int they);
    void setCoor(int newx, int newy);
    void setVoid();
};