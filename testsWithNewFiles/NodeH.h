#include <iostream>

using namespace std;

// Nodo con representacion para la cola de prioridad, este guarda las coordenas del nodo junto con su coste realacionado
class NodeH {
public:
    //Constructor vacio
    NodeH();

    //Constructor segun valores senialados
    NodeH(int i, int j, int value);
    //Destructor
    ~NodeH();
    

    // Getter de la coordenada x
    int get_i();
    // Getter de la coordenada y
    int get_j();
    //getter del costo correspondiente a este nodo
    int getValue();

private:
    // particular variables of this problem
    int i; // coordenada x
    int j; // coordenadd y
    int value; // el costo que representan las coordenadas senialadas
};  

