#include "Maze.h"
#include <ctime>

int main(){
    unsigned t0, t1;
    double time;
    int k = 1, option;
    Maze m(100,85);
    while (k)
    {
        cout << "--------------\n";
        cout << "[1] Print maze\n[2] Solve Maze\n[3] Get Route\n[0] Exit()\nEnter some option: ";
        cin >> option;
        cout << "\n";
        switch (option)
        {
        case 0:
            k = 0;
            cout << "byebye\n";
            break;
        case 1:
            m.print();
            cout << "\n";
            break;
        case 2:
            t0 = clock();
            m.solve();
            t1 = clock();
            time = (double(t1 - t0) / CLOCKS_PER_SEC);
            cout << "Solved in: " << time << "[s]" << endl;
            cout << "\n";
            break;
        case 3:
            m.showRoute();
        }
    }
}


