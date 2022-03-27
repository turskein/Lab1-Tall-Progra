#include "Maze.h"

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
    Stack xVisit(2*dim);
    Heap visited(dim);
    xVisit.push(0,0);
    visited.addCoor(0,0);
    int avisitarX, avisitarY;
    while(!xVisit.isVoid()){
        avisitarX = xVisit.topX();
        avisitarY = xVisit.topY();
        xVisit.pop();

         if (arr[avisitarX][avisitarY] == OUT_DOOR)
        {
            cout << "Se encontro la salidaaaa\n";
            return;
        }
        /*Movimiento hacia la izquierda*/
        if (avisitarX > 0){
            if (arr[avisitarX - 1][avisitarY] != WALL){
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
    cout << "No hay camino :(\n";
}