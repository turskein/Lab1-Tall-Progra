#include "Maze.h"
#include <ctime>

int main() {
    unsigned t0, t1;

    t0 = clock();
    
    Maze m(1000, 90);
    //m.print();
    t1 = clock();
    double time = (double(t1 - t0) / CLOCKS_PER_SEC);
    m.solve();
    cout << "Finalized in: " << time << "[s]" << endl ;
    return 0;
}