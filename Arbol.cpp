#include "Arbol.h"

Arbol::Arbol(){
    Arbol::dim = 0;
    Arbol::matriz = nullptr;
}
Arbol::Arbol(int dim){
    Arbol::dim = dim;
    Arbol::matriz = new Node*[dim];
    for(int i = 0; i < dim; i ++){
        Arbol::matriz[i] = new Node[dim];
    }
}

void Arbol::generate(int dim){
    this->dim = dim;
    this->matriz = new Node*[dim];
    for(int i = 0; i < dim; i ++){
        this->matriz[i] = new Node[dim];
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
bool Arbol::addCoor(int x, int y, int c, int prevX, int prevY){
    if(matriz[x][y].isVisited()){
        //matriz[x][y].betterPrev(c,prevY,prevY);
        return false;
    }
    matriz[x][y].setVisited();
    matriz[x][y].setC(c);
    matriz[x][y].setPrev(prevX, prevY);
    return true;
}

bool Arbol::isVisited(int x, int y){
    return matriz[x][y].isVisited();
}

void Arbol::show(){
    int j = 0;
    for(int i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            cout << "x=" << i << "-"
                 << "y=" << j << "-"
                 << "Px=" << matriz[i][j].getPrevY() << "-"
                 << "Py=" << matriz[i][j].getPrevY() << " ; ";
        }
        cout << "\n";
    }
}
void Arbol::getWay(){
    int newprevX, newprevY;
    int prevX = dim-1;
    int prevY = dim-1;
    int count = 0;
    while(prevX != 0 || prevY != 0){
        cout << prevX << "-" << prevY << "-"<<matriz[prevX][prevY].getC()<< ";";
        newprevX = matriz[prevX][prevY].getPrevX();
        newprevY = matriz[prevX][prevY].getPrevY();
        prevX = newprevX;
        prevY = newprevY;
        count ++;
    }
    cout << prevX << "-" << prevY << ";\n";
    cout <<"Resolverd in: "<< count << "\n";
}

