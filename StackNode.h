#include <iostream>
#include "Node.h"

using namespace std;

/*Stack de memoria statica*/
class StackNode{
private:
    int large;
    Node **Nodes;
    int position;
public:
    StackNode(int large);
    ~StackNode();
    void push(Node *newNode);
    void pop();
    Node* top();
    bool isEmpty();
    void show();
};