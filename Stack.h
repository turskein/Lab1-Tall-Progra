#include <iostream>

using namespace std;

/*Stack de memoria statica*/
class Stack{
private:
    int l, p;
    int *pila;
public:
    Stack(int large);
    ~Stack();
    void push(int x, int y);
    void pop();
    int topX();
    int topY();
    bool isVoid();
    void show();
};