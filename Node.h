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

/*Representacion abstracta de dos coordenadas
en un nodo*/
class Node {
private:
    int x, y, px, py, c;//, r, l ,u, d;
public:
    Node();
    Node(int x, int y);
    Node(int x, int y, int px, int py);
    ~Node();
    int getX();
    int getY();
    int getpX();
    int getpY();
    int getC();
    bool isVoid();
    void setOpen(int adre, int kind);
    int sameCoor(int thex, int they);
    void setCoor(int newx, int newy);
    void setpCoor(int newpx, int newpy);
    void setVoid();
    void setC(int newc);
};