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
    route.generate(dim);
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
    Heap xVisit(dim*dim);
    /*Se genera un arbol que contendra los nodos visitados*/
    /*route, representara los nodos visitados;*/
    /*Se ingresa dentro del stack el nodo (0,0) */
    xVisit.insert(new NodeH(0,0,0,NULL));
    /*Se asume como visitado*/
    route.addCoor(0,0,0,-1,-1);
    int currX, currY, currC;
    NodeH *nodo;
    while(!xVisit.isEmpty()){
        nodo = xVisit.pull();
        currX = nodo->get_i();
        currY = nodo->get_j();
        currC = -nodo->getValue();
        /*Se esta visitando por lo que se retira del stack*/
        /*Movimiento hacia la izquierda*/
        if (currX > 0){
            /*En caso de ser hacia una PARED el movimiento, sencillamente no se realiza*/
            if (arr[currX - 1][currY] != WALL){
                /*Considerando que addCoor() es un metodo de tipo booleano se
                emplea para verificar si se pudo o no ingresar el nuevo nodo
                y por lo tanto en agregar por visitar o no*/
                if (route.addCoor(currX - 1, currY, currC + 1, currX, currY))
                {
                    xVisit.insert(new NodeH(currX - 1, currY, currC + 1,NULL));
                    cout << (currX - 1) << "-" << currY << "-" << (currC + 1) << "-" << currX << "-" << currY << ";";
                }
            }
        }
        /*Movimiento hacia la derecha*/
        if (currX < (dim -1))
        {
            if (arr[currX + 1][currY] != WALL)
            {
                if (route.addCoor(currX + 1, currY, currC + 1, currX, currY))                {
                    xVisit.insert(new NodeH(currX + 1, currY, currC + 1,NULL));
                    cout << (currX + 1) << "-" << currY << "-" << (currC + 1) << "-" << currX << "-" << currY << ";";
                }
            }
        }
        /*Movimiento hacia arriba*/
        if (currY > 0)
        {
            if (arr[currX][currY - 1] != WALL)
            {
                if (route.addCoor(currX, currY - 1, currC + 1, currX, currY))
                {
                    xVisit.insert(new NodeH(currX, currY - 1, currC + 1,NULL));
                    cout << currX << "-" << (currY-1) << "-" << (currC + 1) << "-" << currX << "-" << currY << ";";
                }
            }
        }
        /*Movimiento hacia abajo*/
        if (currY < (dim -1))
        {
            if (arr[currX][currY+1] != WALL)
            {
                if (route.addCoor(currX, currY + 1, currC + 1, currX, currY))
                {
                    xVisit.insert(new NodeH(currX, currY + 1, currC + 1,NULL));
                    cout << currX << "-" << (currY + 1) << "-" << (currC + 1) << "-" << currX << "-" << currY << ";";
                }
            }
        }
    }
    cout << "\n";
    xVisit.~Heap();
    if(route.isVisited(dim-1,dim-1)){
        cout << "Se encontro un camino :D\n";
        route.getWay();
    }else{
        cout << "No se encontro un camino )':\n";
    }
    return;
}

void Maze::showRoute(){
    route.getWay();
}