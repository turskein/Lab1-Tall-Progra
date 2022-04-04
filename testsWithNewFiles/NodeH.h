#include <iostream>

using namespace std;

// needs an explanation of the class, please always comment your code
class NodeH {
public:
    NodeH();
    ~NodeH();
    NodeH(NodeH* NodeH);
    NodeH(int i, int j, int value, NodeH* previous);

    // NOT best practice to have a getter for the private member!
    int get_i();
    int get_j();
    NodeH *getPrevious();
    int getValue();
    int getDepth();
    
    // NOT best practice to have a getter for the private member!
    void setPrevious(NodeH *previous);
    void setDepth(int depth);
    
    // main methods
    int isRoot();
    string getPath();
    void print();

private:
    // particular variables of this problem
    int i; // row
    int j; // column
    int value; // a value representing a cost for choosing this NodeH
    //int depth; // the depth of this NodeH in the tree

    // structural variables: meaning relationships between NodeHs
    //NodeH *previous; // the previous NodeH in the path
};  // end class NodeH

