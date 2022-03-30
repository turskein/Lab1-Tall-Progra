#include "Arbol.h"

Arbol::Arbol(int dim){
    Arbol::dim = dim;
    Arbol::matriz = new Node*[dim];
    for(int i = 0; i < dim; i ++){
        Arbol::matriz[i] = new Node[dim];
    }
}

Arbol::~Arbol(){
    for(int i = 0; i < dim; i ++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

/*Se agrega una coordenada al Arbol, en caso de existir un par ordenado,
identico no sera posible agregarlo.

Se entiende que la busqueda es O(n)*/
bool Arbol::addCoor(int x, int y, int c, Node *previous){
    /*Se inicializa un recorrido de la primera 
    fila para verificar similitud en coordenada x*/
    int j = 0;
    for(int i = 0; i < dim; i ++){
        switch(matriz[i][j].sameCoor(x,y)){
            /*En caso de existir la misma coordenada
            no es posbile agregarlo, por lo que es falso*/
            case SAME:
                /*En caso de que se consiga la misma coordenada
                y el costo ingresado sea menor, se actualiza el costo
                y los nodos anteriores*/
                matriz[i][j].betterPrevious(c, previous);
                return false;
            /*En caso de encontrar una coordenada que coincida en x 
            se recorre la columna*/
            case SAMEX:
                while(j < dim){
                    /*En caso de encontrar algun par igual, se retorna false*/
                    if(matriz[i][j].sameCoor(x,y)==SAME){
                        matriz[i][j].betterPrevious(c, previous);
                        return false;
                        };
                    /*En caso de estar vacio se agrega como corresponde*/
                    if(matriz[i][j].isVoid()){
                        matriz[i][j] = Node(x, y, c, previous);
                        return true;
                        };
                    j++;
                }
                return false;
        }
        /*Aqui se verifica si en el recorrido de la fila inicial,
        algun par ordenado esta vacio*/
        if(matriz[i][j].isVoid()){
            matriz[i][j] = Node(x, y, c, previous);
            return true;
        }
    }
    return false;
}

bool Arbol::exist(int x, int y){
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

void Arbol::show(){
    int j = 0;
    for(int i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            cout << "x=" << matriz[i][j].getX() << "-"
                 << "y=" << matriz[i][j].getY() << "-"
                 << "Px=" << matriz[i][j].getPrevious()->getX() << "-"
                 << "Py=" << matriz[i][j].getPrevious()->getY() << " ; ";
        }
        cout << "\n";
    }
}
void Arbol::getWay(int lastx, int lasty){
    int j, i;
    int count = 0;
    while (lastx != 0 || lasty != 0){
        j = 0;
        for (i = 0; i < dim; i++){
            if(matriz[i][j].sameCoor(lastx,lasty) == SAME){
                lastx = matriz[i][j].getPrevious()->getX();
                lasty = matriz[i][j].getPrevious()->getX();
                cout << lastx << "-" << lasty << "; ";
                count++;
                i = dim;
            }else if(matriz[i][j].sameCoor(lastx,lasty) == SAMEX){
                while (j < dim){
                    if (matriz[i][j].sameCoor(lastx,lasty) == SAME){
                        lastx = matriz[i][j].getPrevious()->getX();
                        lasty = matriz[i][j].getPrevious()->getX();
                        cout << lastx << "-" << lasty << "; ";
                        j = dim;
                        i = dim;
                        count++;
                    }
                    j ++;
                }
            }
        }
    }
    cout <<"Resolverd in: "<< (count) << "\n";
}

