#include "Arbol.h"

string op(bool d){
    if(d) return "agregado";
    return "no agregado";
};

int main(){
    Arbol my(3);
    /*Se setean una serie de nodos como visitados*/
    cout << "Se agrega el [0,0]?: " << op(my.addCoor(0,0,0,0,0)) << endl;
    cout << "Se agrega el [1,0]?: " << op(my.addCoor(1,0,0,0,0)) << endl;
    cout << "Se agrega el [2,0]?: " << op(my.addCoor(2,0,0,0,0)) << endl;
    cout << "Se agrega el [2,2]?: " << op(my.addCoor(2,2,0,0,0)) << endl;
    cout << "Se agrega el [0,0]?: " << op(my.addCoor(0,0,0,0,0)) << endl;
    cout << "Se agrega el [2,0]?: " << op(my.addCoor(2,0,0,0,0)) << endl;
    my.show();

    cout << "Se resetea el 0,0" << endl;
    my.resetNode(0,0);
    my.show();

    return 0;
}