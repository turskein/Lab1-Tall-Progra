#include "Heap.h"

Heap::Heap(int dim){
    Heap::dim = dim;
    Heap::matriz = new Node*[dim];
    for(int i = 0; i < dim; i ++){
        Heap::matriz[i] = new Node[dim];
    }
}
bool Heap::addCoor(int x, int y){
    int j = 0;
    for(int i = 0; i < dim; i ++){
        switch(matriz[i][j].sameCoor(int x, int y)){
            case SAME:
                return false;
            case SAMEX:
                while(j < dim){
                    if(matriz[i][j].sameCoor()==SAME)return false;
                    j++;
                }
                
        }

    }
}

bool exist(int x, int y){
    return true;
}

