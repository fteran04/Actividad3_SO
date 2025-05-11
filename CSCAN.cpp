#include "CSCAN.h"


using namespace std;

int CSCAN(vector<int>& requests, int init, bool barrido_hacia_arriba = true) {
    sort(requests.begin(), requests.end());
    int posIni = 0, total_movement = 0, distance;
    ofstream outFile("ordenMovimientosCSCAN.txt");

    // Búsqueda binaria para posIni (igual que antes)
    int low = 0, high = requests.size() - 1;
    while (low <= high) {
        posIni = (low + high) / 2;
        if (requests[posIni] < init) low = posIni + 1;
        else high = posIni - 1;
    }
    posIni = low;

    if (barrido_hacia_arriba) {
        // En este sentido se hace el barrido de abajo hacia arriba
        // Por lo que se hace de posIni hasta 4999
        for (int i = posIni; i < requests.size(); ++i) {
            int distance = abs(init - requests[i]);
            total_movement += distance;
            outFile << "De " << init << " a " << requests[i] << " = |" << init << " - " << requests[i] << "| = " << distance << endl;
            init = requests[i];
        }

        // Acá se vuelve se termina de llegar a 4999
        // y se vuelve a 0 para después ir hacia arriba
        distance = abs(init - 4999);
        total_movement += distance;
        outFile << "De " << init << " a 4999 = |" << init << " - 4999| = " << distance << endl;
        distance = 4999 - 0;
        total_movement += distance;
        outFile << "De 4999 a 0 = |4999 - 0| = " << distance << endl;
        init = 0;
    

        // Barrido hacia arriba justo después de posIni
        // Segundo barrido: 0 -> posIni y finalmente hasta 4999
        for (int i = 0; i < posIni; ++i) {
            int distance = abs(init - requests[i]);
            total_movement += distance;
            outFile << "De " << init << " a " << requests[i] << " = |" << init << " - " << requests[i] << "| = " << distance << endl;
            init = requests[i];
        }

        // Desplazamiento final hasta 4999
        distance = abs(init - 4999);
        total_movement += distance;
        outFile << "De " << init << " a 4999 = |" << init << " - 4999| = " << distance << endl;

    } else {
        // En este sentido se hace el barrido de arriba hacia abajo
        // Por lo que se hace de posIni hasta 0
        for (int i = posIni - 1; i >= 0; --i) {
            int distance = abs(init - requests[i]);
            total_movement += distance;
            outFile << "De " << init << " a " << requests[i] << " = |" << init << " - " << requests[i] << "| = " << distance << endl;
            init = requests[i];
        }

        // Acá se vuelve a 4999 para después ir hacia abajo
        distance = abs(init - 0);
        total_movement += distance;
        outFile << "De " << init << " a 0 = |" << init << " - 0| = " << distance << endl;
        distance = 4999 - 0; 
        total_movement += distance;
        outFile << "De 0 a 4999 = |0 - 4999| = " << distance << endl;
        init = 4999;

        // Barrido hacia abajo justo antes de posIni
        // Segundo barrido: 4999 -> posIni y finalmente hasta 0
        for (int i = requests.size() - 1; i >= posIni; --i) {
            int distance = abs(init - requests[i]);
            total_movement += distance;
            outFile << "De " << init << " a " << requests[i] << " = |" << init << " - " << requests[i] << "| = " << distance << endl;
            init = requests[i];
        }

        // Desplazamiento final hasta 0
        if (init != 0) {
            int distance = abs(init - 0);
            total_movement += distance;
            outFile << "De " << init << " a 0 = |" << init << " - 0| = " << distance << endl;
        }
    }

    outFile.close();
    return total_movement;
}
