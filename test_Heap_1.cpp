#include "Heap.h"
#include "Stack.h"

using namespace std;

int main(){
    char string[0];
    Heap mynewheap(10); // Se genera un heap
    cout << mynewheap.addCoor(1,1) << " agregar (1,1)\n"; // Se agrega un nuevo nodo 
    cout << mynewheap.addCoor(1, 2) << " agregar (1,2)\n"; // Se agrega un nuevo nodo
    cout << mynewheap.addCoor(1, 2) << " agregar (1,2)\n"; // NO es posible agregarlo porque ya existe
    cout << mynewheap.addCoor(3,1) << " agregar (3,1)\n";
    cout << mynewheap.addCoor(3, 3) << " agregar (3,3)\n";
    cout << mynewheap.addCoor(3, 3) << " agregar (3,3)\n";
    cin >>string;
    return 0;
}