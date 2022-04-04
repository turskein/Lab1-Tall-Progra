#include "Container.h"

Container::Container(int size) {
    Container::size = size;
    Container::count = 0;
    arr = new NodeH[size];
}

Container::~Container() {
    delete[] arr;
}

int Container::getSize() {
    return size;
}

void Container::insert(NodeH *NodeH) {
    if (count == size) {
        cout << "Container is full" << endl;
        return;
    }
    arr[count] = *NodeH; // Notice: copy the NodeH
    count++;
    bubbleUp();
}

int Container::isEmpty() {
    return count == 0;
}

int Container::peek() {
    if (isEmpty()) {
        cout << "Container is empty" << endl;
        return(-1);
    }
    return arr[0].getValue();
}

// printing by levels
void Container::print() {
/* 
    a: index of the level in the Container. Root is at level 0.
    b: index of the column in the level. Root is at column 0.
    k: index of the NodeH in the Container.
    (1<<a) = 2^a. Each row has 2^a NodeHs.
    (1<<a)-1 + b is the index of the NodeH in the Container.
    k = (1<<a)-1 + b
    The height of the Container is log2(count)=log(count)/log(2).
*/
    int h = (int)(log(count)/log(2));
    
    for(int a=0;a <= h;a++){
        for(int b=0;b<(1<<a) && ((1<<a)-1+b)<count;b++){
            int k=(1<<a)-1+b;
            cout<<arr[k].getValue()<<" ";
        }
        cout << endl;
    }
}

NodeH* Container::pull() {
    if (isEmpty()) {
        cout << "Container is empty" << endl;
        return NULL;
    }
    NodeH *nodeH = new NodeH(arr[0]);
    arr[0] = arr[count - 1];
    count--;
    bubbleDown();
    return nodeH;
}

void Container::swap(int i, int j) {
    NodeH temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void Container::bubbleUp(){
    int index = count - 1;
    int parentIndex =  (index - 1) / 2;
    while (index > 0 &&
        parentIndex >= 0 && 
        arr[index].getValue() > arr[parentIndex].getValue()) {
        swap(index, parentIndex);
        index = parentIndex;
        parentIndex =  (index - 1) / 2;
    }
}

void Container::bubbleDown(){
    int index = 0;
    int leftChildIndex = 1;
    int rightChildIndex = 2;
    while (leftChildIndex < count) {
        // Find the largest child for swapping
        if (arr[leftChildIndex].getValue() > arr[index].getValue() || 
            arr[rightChildIndex].getValue() > arr[index].getValue()) {
            if (arr[leftChildIndex].getValue() > arr[rightChildIndex].getValue()) {
                swap(index, leftChildIndex);
                index = leftChildIndex; // Move to the left child
            } else {
                swap(index, rightChildIndex);
                index = rightChildIndex; // Move to the right child
            }
            // Update the child index
            leftChildIndex = index * 2 + 1;
            rightChildIndex = index * 2 + 2;        
        } else {
            break; // no need to bubble down
        }
    }
}

