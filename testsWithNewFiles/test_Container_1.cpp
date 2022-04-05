#include "Container.h"
#include <stdlib.h>
#include <time.h>

int main() {
    int n=20;
    srand(time(NULL));
    Container h(n);
    
    // inserting random numbers
    for(int i = 0; i < n-2; i++) {
        int val=rand()%n;
        NodeH *node = new NodeH(i, i, val);
        cout<<"inserting "<<val<<endl;
        h.insert(node);
        delete node;
    }
    int i = 2;
    h.insert(new NodeH(i, i, -20));
    h.insert(new NodeH(i, i, -30));

    // printing Container
    cout << "The Container" <<endl;
    h.print();

    // extraccting all element from Container, shoud all appears in order
    cout << "Ordered number:" << endl;
    for(int i=0;i<n; i++){
        NodeH *node = h.pull();
        cout<<"pulling "<<node->getValue()<<endl;
    }
 }