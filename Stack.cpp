#include "Stack.h"

/*Constructor de stack, se ingresa el largo
del stack y su largo sera el cuadrado del ingresado*/
Stack::Stack(int large){
    Stack::pila = new int[2*large];
    Stack::l = large;
    Stack::p = 0;
    Stack::pila[p] = -1;
    Stack::pila[p+1] = -1;
}

Stack::~Stack(){
    delete[] pila;
}

void Stack::push(int x, int y){
    if(pila[p] != -1){
        p = p + 2;
        pila[p] = x;
        pila[p+1] = y;
        return;
    }
    pila[p] = x;
    pila[p + 1] = y;
}

void Stack::pop(){
    if(p != 0) {
        p = p - 2;
        return;
    }
    pila[p] = -1;
    pila[p + 1] = -1;
}

int Stack::topX(){
    return pila[p];
}

int Stack::topY(){
    return pila[p+1];
}

bool Stack::isVoid(){
    return pila[p] == -1 && pila[p+1] == -1;
}

void Stack::show(){
    for(int i = p; i >= 0; i = i - 2){
        cout << pila[i] << " - " << pila[i+1] << " ; ";
    }
}