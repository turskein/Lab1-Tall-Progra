#include "Maze.h"

/*Constructor de */
Maze::Maze(int dim, int p) {
        srand(time(NULL)); // set seed for random number generator
    Maze::dim = dim;
    Maze::void_percentage=p;
    Maze::arr = nullptr;
    Maze::generate();
}

Maze::~Maze() {
    for (int i = 0; i < dim; i++) {
        delete[] arr[i];
    }
    delete[] arr;
}

void Maze::generate() {
    if(arr == NULL){
        arr = new int *[dim];
        route.generate(dim);
        for (int i = 0; i < dim; i++)
        {
            arr[i] = new int[dim];
            for (int j = 0; j < dim; j++)
            {
                arr[i][j] = rand() % 100 < void_percentage ? EMPTY : WALL;
            }
        }
    }else{
        for (int i = 0; i < dim; i++)
        {
            for (int j = 0; j < dim; j++)
            {
                route.resetNode(i,j);
                arr[i][j] = rand() % 100 < void_percentage ? EMPTY : WALL;
            }
        }
    }
    arr[0][0] = IN_DOOR;
    arr[dim-1][dim-1] = OUT_DOOR;
}

void Maze::print(){
    for(int i = 0; i < dim; i++){
        for(int j = 0; j < dim; j++){
            if(arr[j][i] == EMPTY){
                cout << "O";
            }else if(arr[j][i] == WALL){
                cout << RED <<"X"<< RESET;
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

void Maze::goUp(Container *xVisit, int x, int y, int c)
{
    
    if(y > 0){
        if(arr[x][y-1] != WALL){
            if(route.addCoor(x,y-1,c+1,x,y)){
                xVisit->insert(new NodeH(x, y - 1, -(c+1),NULL));
            }
        }
    }
}

void Maze::goRight(Container *xVisit, int x, int y, int c)
{
    if (x < dim-1)
    {
        if (arr[x+1][y] != WALL)
        {
            if (route.addCoor(x+1, y, c, x, y))
            {
                xVisit->insert(new NodeH(x+1, y, -c, NULL));
            }
        }
    }
}

void Maze::goDown(Container *xVisit, int x, int y, int c)
{
    if (y < dim-1)
    {
        
        if (arr[x][y +1] != WALL)
        {
            
            if (route.addCoor(x, y +1, c, x, y))
            {
                
                xVisit->insert(new NodeH(x, y +1, -c, NULL));
            }
        }
    }
}

void Maze::goLeft(Container *xVisit, int x, int y, int c)
{
    if (x > 0)
    {
        if (arr[x-1][y] != WALL)
        {
            if (route.addCoor(x-1, y, c + 1, x, y))
            {
                xVisit->insert(new NodeH(x-1, y, -c - 1, NULL));
            }
        }
    }
}

bool Maze::analyseNode(Container *xVisit, int x, int y, int c)
{
    if (x == (dim - 1) && y == (dim - 1)) return true;
    
    goDown(xVisit,x,y,c);
    goUp(xVisit, x,y,c);
    goRight(xVisit, x,y,c);
    goLeft(xVisit, x,y,c);
    
    return false;
}

bool Maze::solve(){
    /*Se genera un container de los nodos por visitar*/
    Container xVisit(dim*dim);
    /*Se genera un arbol que contendra los nodos visitados*/
    /*route, representara los nodos visitados;*/
    /*Se ingresa dentro del container el nodo (0,0) */
    xVisit.insert(new NodeH(0,0,0,NULL));
    /*Se asume como visitado*/
    route.addCoor(0,0,0,-1,-1);
    int currX, currY, currC;
    NodeH *nodo;
    while(!xVisit.isEmpty()){
        nodo = xVisit.pull();
        currX = nodo->get_i();
        currY = nodo->get_j();
        currC = nodo->getValue();
        if(analyseNode(&xVisit, currX,currY,currC)) return true;
    }
    //xVisit.~Container();
    return false;
}

/*Muestra la ruta relacionada al laberinto*/
void Maze::showRoute(){
    route.getWay(arr);
}