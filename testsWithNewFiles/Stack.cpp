#include "Stack.h"

/*Constructor de stack, se ingresa el largo
del stack y su largo sera el cuadrado del ingresado*/
Stack::Stack(int large){
    Stack::pila = new int[3*large];
    Stack::l = large;
    Stack::p = 0;
    Stack::pila[p] = -1;
    Stack::pila[p+1] = -1;
    Stack::pila[p + 2] = -1;
}

Stack::~Stack(){
    delete[] pila;
}

void Stack::push(int x, int y, int c){
    if(pila[p] != -1){
        p = p + 3;
        pila[p] = x;
        pila[p+1] = y;
        pila[p+2] = c;
        return;
    }
    pila[p] = x;
    pila[p + 1] = y;
    pila[p + 2] = c;
}

void Stack::pop(){
    if(p != 0) {
        p = p - 3;
        return;
    }
    pila[p] = -1;
    pila[p + 1] = -1;
    pila[p + 2] = -1;
}

int Stack::topX(){
    return pila[p];
}

int Stack::topY(){
    return pila[p+1];
}
int Stack::topC(){
    return pila[p+2];
}

bool Stack::isVoid(){
    return pila[p] == -1;
}

void Stack::show(){
    for(int i = p; i >= 0; i = i - 3){
        cout << pila[i] << " - " << pila[i+1] << " ; ";
    }
    cout << "\n";
}