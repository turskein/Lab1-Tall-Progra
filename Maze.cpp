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
    route = new Arbol(dim);
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
    StackNode xVisit(dim*dim);
    /*Se genera un arbol que contendra los nodos visitados*/
    /*route, representara los nodos visitados;*/
    /*Se ingresa dentro del stack el nodo (0,0) */
    Node *toAnalizar = new Node(0,0,0,NULL);
    xVisit.push(toAnalizar);
    /*Se asume como visitado*/
    route->addCoor(0,0,0,NULL);
    while(!xVisit.isEmpty()){
        /*Se obtienen las coordendas del nodo tope*/
        toAnalizar = xVisit.top();
        /*Se esta visitando por lo que se retira del stack*/
        xVisit.pop();
        /*Movimiento hacia la izquierda*/
        if (toAnalizar->getX() > 0){
            /*En caso de ser hacia una PARED el movimiento, sencillamente no se realiza*/
            if (arr[toAnalizar->getX() - 1][toAnalizar->getY()] != WALL){
                /*Considerando que addCoor() es un metodo de tipo booleano se
                emplea para verificar si se pudo o no ingresar el nuevo nodo
                y por lo tanto en agregar por visitar o no*/
                if (route->addCoor(toAnalizar->getX() - 1, toAnalizar->getY(), toAnalizar->getC() + 1, toAnalizar))
                {
                    xVisit.push(new Node(toAnalizar->getX() - 1, toAnalizar->getY(), toAnalizar->getC() + 1,toAnalizar));
                    //cout << (toAnalizar->getX() - 1) << " - " << toAnalizar->getY() << " - " << (toAnalizar->getC() + 1) << " - " << toAnalizar->getX() << " - " << toAnalizar->getY() << "\n";
                }
            }
        }
        /*Movimiento hacia la derecha*/
        if (toAnalizar->getX() < (dim -1))
        {
            if (arr[toAnalizar->getX() + 1][toAnalizar->getY()] != WALL)
            {
                if (route->addCoor(toAnalizar->getX() + 1, toAnalizar->getY(), toAnalizar->getC() + 1,toAnalizar))                {
                    xVisit.push(new Node(toAnalizar->getX() + 1, toAnalizar->getY(), toAnalizar->getC() + 1,NULL));
                    //cout << (toAnalizar->getX() + 1) << " - " << toAnalizar->getY() << " - " << (toAnalizar->getC() + 1) << " - " << toAnalizar->getX() << " - " << toAnalizar->getY() << "\n";
                }
            }
        }
        /*Movimiento hacia arriba*/
        if (toAnalizar->getY() > 0)
        {
            if (arr[toAnalizar->getX()][toAnalizar->getY() - 1] != WALL)
            {
                if (route->addCoor(toAnalizar->getX(), toAnalizar->getY() - 1, toAnalizar->getC() + 1, toAnalizar))
                {
                    xVisit.push(new Node(toAnalizar->getX(), toAnalizar->getY() - 1, toAnalizar->getC() + 1, toAnalizar));
                    //cout << toAnalizar->getX() << " - " << (toAnalizar->getY()-1) << " - " << (toAnalizar->getC() + 1) << " - " << toAnalizar->getX() << " - " << toAnalizar->getY() << "\n";
                }
            }
        }
        /*Movimiento hacia abajo*/
        if (toAnalizar->getY() < (dim -1))
        {
            if (arr[toAnalizar->getX()][toAnalizar->getY()+1] != WALL)
            {
                if (route->addCoor(toAnalizar->getX(), toAnalizar->getY() + 1, toAnalizar->getC() + 1, toAnalizar))
                {
                    xVisit.push(new Node(toAnalizar->getX(), toAnalizar->getY() + 1, toAnalizar->getC() + 1, toAnalizar));
                    //cout << toAnalizar->getX() << " - " << (toAnalizar->getY() + 1) << " - " << (toAnalizar->getC() + 1) << " - " << toAnalizar->getX() << " - " << toAnalizar->getY() << "\n";
                }
            }
        }
    }
    xVisit.~StackNode();
    if(route->exist(dim-1,dim-1)){
        cout << "Se encontro un camino :D\n";
        route->getWay(dim-1,dim-1);
    }else{
        cout << "No se encontro un camino )':\n";
    }
    return;
}

void Maze::showRoute(){
    route->getWay(dim-1,dim-1);
}