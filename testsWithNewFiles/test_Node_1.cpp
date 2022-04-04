#include "Node.h"

int main(){
    Node my(32,0,0);
    cout << "-- Valores iniciales" << endl;
    cout << "Value: "<< my.getC() << " " <<
    "Visited: " << (my.isVisited()? "YES ": "NO ") <<
    "Previous X,Y: "<< my.getPrevX()<<"," << my.getPrevY() << endl;

    cout << "-- Seteos " << endl;
    my.setPrev(2,3);
    my.setVisited();
    my.setC(12);

    cout << "Value: " << my.getC() << " "<<
    "Visited: " << (my.isVisited() ? "YES " : "NO ")<<
    "Previous X,Y: " << my.getPrevX() << "," << my.getPrevY() << endl;

    cout << "-- Reset " << endl;
    my.reset();
    cout << "Value: " << my.getC() << " "<<
    "Visited: " << (my.isVisited() ? "YES " : "NO ")<<
    "Previous X,Y: " << my.getPrevX() << "," << my.getPrevY() << endl;
    system("pause");
    return 0;
}