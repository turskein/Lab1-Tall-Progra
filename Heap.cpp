#include "Heap.h"

Heap::Heap(int dim){
    Heap::dim = dim;
    Heap::matriz = new Node*[dim];
    for(int i = 0; i < dim; i ++){
        Heap::matriz[i] = new Node[dim];
    }
}