#include <iostream>

using namespace std;

class Stack{
private:
    int l, p;
    int *pila;
public:
    Stack(int large);
    void push(int x, int y);
    void pop();
    int topX();
    int topY();
    bool isVoid();
    void show();
};