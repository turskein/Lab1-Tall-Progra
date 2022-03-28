#include "Maze.h"

/*Constructor de */
Maze::Maze(int dim, int p) {
        srand(time(NULL)); // set seed for random number generator
    Maze::dim = dim;
    Maze::void_percentage=p;
    Maze::generate();
}

Maze::~Maze() {
    for (int i = 0; i < dim; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void Maze::generate() {
    arr = new int*[dim];
    for (int i = 0; i < dim; i++) {
        arr[i] = new int[dim];
        for (int j = 0; j < dim; j++) {
            arr[i][j] = rand() % 100 < void_percentage ? EMPTY : WALL;
        }
    }

    // set the entrance and exit
    
    arr[0][0] = IN_DOOR;
    arr[dim-1][dim-1] = OUT_DOOR;
}

void Maze::print(){
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(arr[j][i] == EMPTY){
                cout << "O";
            }else if(arr[j][i] == WALL){
                cout << "X";
            }
            else if (arr[j][i] == IN_DOOR)
            {
                cout << "E";
            }
            else if (arr[j][i] == OUT_DOOR)
            {
                cout << "S";
            }
        }
        cout << "\n";
    }
}

void Maze::solve(){
    /*Se genera un stack de los nodos por visitar*/
    Stack xVisit(dim*dim);
    /*Se genera un heap que contendra los nodos visitados*/
    Heap visited(dim);
    /*Se ingresa dentro del stack el nodo (0,0) */
    xVisit.push(0,0);
    /*Se asume como visitado*/
    visited.addCoor(0,0);
    int avisitarX, avisitarY;
    while(!xVisit.isVoid()){
        /*Se obtienen las coordendas del nodo tope*/
        avisitarX = xVisit.topX();
        avisitarY = xVisit.topY();
        /*Se esta visitando por lo que se retira del stack*/
        xVisit.pop();
        /*En caso de encontrar el nodo salida se termina la funcion*/
         if (arr[avisitarX][avisitarY] == OUT_DOOR)
        {
            cout << "Se encontro la salidaaaa\n";
            xVisit.~Stack();
            visited.~Heap();
            return;
        }
        /*Movimiento hacia la izquierda*/
        if (avisitarX > 0){
            /*En caso de ser hacia una PARED el movimiento, sencillamente no se realiza*/
            if (arr[avisitarX - 1][avisitarY] != WALL){
                /*Considerando que addCoor() es un metodo de tipo booleano se
                emplea para verificar si se pudo o no ingresar el nuevo nodo
                y por lo tanto en agregar por visitar o no*/
                if (visited.addCoor(avisitarX - 1, avisitarY)){
                    xVisit.push(avisitarX - 1, avisitarY);
                }
            }
        }
        /*Movimiento hacia la derecha*/
        if (avisitarX < (dim -1))
        {
            if (arr[avisitarX + 1][avisitarY] != WALL)
            {
                if (visited.addCoor(avisitarX + 1, avisitarY)){
                    xVisit.push(avisitarX + 1, avisitarY);
                }
            }
        }
        /*Movimiento hacia arriba*/
        if (avisitarY > 0)
        {
            if (arr[avisitarX][avisitarY - 1] != WALL)
            {
                if (visited.addCoor(avisitarX , avisitarY - 1)){
                    xVisit.push(avisitarX, avisitarY - 1);
                }
            }
        }
        /*Movimiento hacia abajo*/
        if (avisitarY < (dim -1))
        {
            if (arr[avisitarX][avisitarY+1] != WALL)
            {
                if (visited.addCoor(avisitarX, avisitarY+1)){
                    xVisit.push(avisitarX, avisitarY + 1);
                }
            }
        }
    }
    /*Considerando que el stack se vacio y no se consiguio camino hacia la salida
    tan solo se termina la funcion*/
    cout << "No hay camino :(\n";
    xVisit.~Stack();
    visited.~Heap();
}