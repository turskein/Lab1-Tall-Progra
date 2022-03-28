#include "Maze.h"
#include <ctime>

int main() {
    unsigned t0, t1;
    int n, option, k, newn, newperc;
    double time;
    cout<< "Enter one number that will be distance of the maze: ";
    cin >> n;
    Maze m(n, 90);
    k = 1;
    while(k){
        cout << "--------------\n";
        cout << "[1] Print maze\n[2] Solve Maze\n[3] Redimension\n[0] Exit()\nEnter some option: ";
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
        case 2:
            t0 = clock();
            m.solve();
            t1 = clock();
            time = (double(t1 - t0) / CLOCKS_PER_SEC);
            cout << "Solved in: " << time << "[s]" << endl;
            cout << "\n";
            break;
        case 3:
            cout << "Enter new dimensions: ";
            cin >> newn;
            cout << "Enter new void percentage: ";
            cin >> newperc;
            m = Maze(newn, newperc);
            break;
        }
    }
    return 0;
}