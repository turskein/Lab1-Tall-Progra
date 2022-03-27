#include "Heap.h"

Heap::Heap(int dim){
    Heap::dim = dim;
    Heap::matriz = new Node*[dim];
    for(int i = 0; i < dim; i ++){
        Heap::matriz[i] = new Node[dim];
    }
}

/*Se agrega una coordenada al heap, en caso de existir un par ordenado,
identico no sera posible agregarlo.

Se entiende que la busqueda es O(n)*/
bool Heap::addCoor(int x, int y){
    /*Se inicializa un recorrido de la primera 
    fila para verificar similitud en coordenada x*/
    int j = 0;
    for(int i = 0; i < dim; i ++){
        switch(matriz[i][j].sameCoor(x,y)){
            /*En caso de existir la misma coordenada
            no es posbile agregarlo, por lo que es falso*/
            case SAME:
                return false;
            /*En caso de encontrar una coordenada que coincida en x 
            se recorre la columna*/
            case SAMEX:
                while(j < dim){
                    /*En caso de encontrar algun par igual, se retorna false*/
                    if(matriz[i][j].sameCoor(x,y)==SAME)return false;
                    /*En caso de estar vacio se agrega como corresponde*/
                    if(matriz[i][j].isVoid()){
                        matriz[i][j].setCoor(x,y);
                        return true;
                        }
                    j++;
                }
                return false;
        }
        /*Aqui se verifica si en el recorrido de la fila inicial,
        algun par ordenado esta vacio*/
        if(matriz[i][j].isVoid()){
            matriz[i][j].setCoor(x,y);
            return true;
        }
    }
    return false;
}

bool Heap::exist(int x, int y){
    /*Se inicializa un recorrido de la primera
    fila para verificar similitud en coordenada x*/
    int j = 0;
    for (int i = 0; i < dim; i++)
    {
        switch (matriz[i][j].sameCoor(x, y))
        {
        /*En caso de existir la misma coordenada se retorna true*/
        case SAME:
            return true;
        /*En caso de encontrar una coordenada que coincida en x
        se recorre la columna*/
        case SAMEX:
            while (j < dim){
                /*En caso de encontrar algun par igual se retorna true*/
                if (matriz[i][j].sameCoor(x, y) == SAME) return true;
                /*En caso de encontrar algun vacio, entonces ya no sera
                posible encontrarlo*/
                if (matriz[i][j].isVoid())return false;
                j++;
            }
            return false;
        }
        /*Aqui se verifica si en el recorrido de la fila inicial,
        algun par ordenado esta vacio*/
        if (matriz[i][j].isVoid()) return false;
    }
    return false;
}

