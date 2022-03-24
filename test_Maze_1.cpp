#include "Maze.h"
#include <ctime>

int main() {
    unsigned t0, t1;

    t0 = clock();
    
    Maze m(10000, 50);
    m.print();
    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    cout << "Finalized in: " << time << "[s]" << endl ;
    return 0;
}