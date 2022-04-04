#include "Arbol.h"
/*Constructor vacio*/
Arbol::Arbol(){
    Arbol::dim = 0;
    Arbol::matriz = nullptr;
}

/*Constructor relleno*/
Arbol::Arbol(int dim){
    Arbol::dim = dim;
    Arbol::matriz = new Node*[dim];
    for(int i = 0; i < dim; i ++){
        Arbol::matriz[i] = new Node[dim];
    }
}

/*Generador de matriz de acuerdo al tamanio ingresado*/
void Arbol::generate(int dim){
    this->dim = dim;
    this->matriz = new Node*[dim];
    for(int i = 0; i < dim; i ++){
        this->matriz[i] = new Node[dim];
    }
}

/*Destructor*/
Arbol::~Arbol(){
    for(int i = 0; i < dim; i ++){
        delete[] matriz[i];
    }
    delete[] matriz;
}

/*Se agrega una coordenada al Arbol, en caso de existir un par ordenado,
identico no sera posible agregarlo.
*/
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

/*Verifica si un nodo esta visitado o no*/
bool Arbol::isVisited(int x, int y){
    return matriz[x][y].isVisited();
}

/*Setea los valores de un nodo en particular como si fuera recién creado*/
void Arbol::resetNode(int i, int j){
    matriz[i][j].reset();
};

/*Recorre las matriz completa mostrando imformacion referente a cada nodo*/
void Arbol::show(){
    int j = 0;
    for(int i = 0; i < dim; i++){
        for(j = 0; j < dim; j++){
            cout << "x =" << i << "-"
                 << "y =" << j << "-"
                 << "c =" << matriz[i][j].getC()
                 << "Px =" << matriz[i][j].getPrevY() << "-"
                 << "Py =" << matriz[i][j].getPrevY() << " ; ";
        }
        cout << "\n";
    }
}

/*Obtiene el camino generado desde el nodo final hasta el inicio*/
void Arbol::getWay(int **maze){
    int newprevX, newprevY;
    int prevX = dim-1;
    int prevY = dim-1;
    matriz[prevX][prevY].setState(1);
    int count = 0;
    while(prevX != 0 || prevY != 0){
        newprevX = matriz[prevX][prevY].getPrevX();
        newprevY = matriz[prevX][prevY].getPrevY();
        prevX = newprevX;
        prevY = newprevY;
        matriz[prevX][prevY].setState(1);
        count ++;
    }
    int i,j;
    for(i=0; i < dim; i++){
        for (j = 0; j < dim; j++)
        {
            if(maze[i][j] == 1){
                cout << RED <<"#"<< RESET;
            }
            else if (maze[i][j] == 2)
            {
                cout << GREEN << "E" << RESET;
            }
            else if (maze[i][j] == 3)
            {
                cout << GREEN << "E" << RESET;
            }
            else if (maze[i][j] == 0)
            {
                if(matriz[i][j].getState() == 0) {
                    cout << "O";
                }else{
                    cout << GREEN <<"O"<< RESET;
                }
            }
        }
        cout << "\n";
    }
    cout << "Resolved in: "<< count << "\n";
}

