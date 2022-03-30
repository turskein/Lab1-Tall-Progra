#include <iostream>

using namespace std;

// needs an explanation of the class, please always comment your code
class Node {
public:
    Node();
    ~Node();
    Node(Node* node);
    Node(int i, int j, int value, Node* previous);

    // NOT best practice to have a getter for the private member!
    int get_i();
    int get_j();
    Node *getPrevious();
    Node *getNext();
    int getValue();
    int getDepth();
    
    // NOT best practice to have a getter for the private member!
    void setPrevious(Node *previous);
    void setNext(Node *previous);
    void setDepth(int depth);
    
    // main methods
    int isRoot();
    string getPathPrevious();
    string getPathNext();
    void print();

private:
    // particular variables of this problem
    int i; // row
    int j; // column
    int value; // a value representing a cost for choosing this node
    int depth; // the depth of this node in the tree

    // structural variables: meaning relationships between nodes
    Node *previous; // the previous node in the path
    Node *next; // the next node in the path
};  // end class Node

