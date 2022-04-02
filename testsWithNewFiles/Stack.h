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
    void push(int x, int y, int c);
    void pop();
    int topX();
    int topY();
    int topC();
    bool isEmpty();
    void show();
};