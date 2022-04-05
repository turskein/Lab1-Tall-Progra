#include "Maze.h"
#include <ctime>

void encontrado(bool d)
{
    if (d)
    {
        cout << GREEN << "ENCONTRADO" << RESET;
        return;
    }
    cout << RED << "NO ENCONTRADO" << RESET;
}

int main(){
    unsigned t0, t1;
    int encontrados = 0, noncontrados = 0;
    bool d;
    double time, te = 0, tn = 0;

    Maze m(1000, 90);
    double acum = 0;
    for (int i = 0; i < 100; i++)
    {
        /*Calculo tiempo por resolucion de laberinto*/
        t0 = clock();
        d = m.solve();
        t1 = clock();
        time = (double(t1 - t0) / CLOCKS_PER_SEC);

        /*Bloque impresion por ciclo*/
        cout << "[" << i + 1 << "]"
             << "Solved in: " << time << "[s] - ";
        encontrado(d);
        cout << endl;

        d ? te += time : tn += time;
        d ? encontrados += 1 : noncontrados += 1;

        acum += time;
        // regeneracion de laberinto completo
        m.generate();
    }
    cout << "Average time to solve: " << acum / 100 << "[s]" << endl;
    cout << "Average 'Founded' time to solve: " << te / encontrados << "[s]" << endl;
    cout << "Average 'Not Founded' time to solve: " << tn / noncontrados << "[s]" << endl;

    system("pause");
    return 0;
}