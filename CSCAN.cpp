#include "CSCAN.h"


using namespace std;

int CSCAN(vector<int> &requests, int init) {
    sort(requests.begin(), requests.end());
    int total_movement = 0;
    ofstream outFile("orderMovimientosCSCAN.txt");

    // Busqueda binaria para encontrar la posición inicial
    // de la cabeza en el vector de peticiones
    int pos = lower_bound(requests.begin(), requests.end(), init) - requests.begin();
    
    // Barrido de posición inicial hacia arriba, es decir, de init a 4999
    for (int i = pos; i < requests.size(); ++i) {
        int distance = abs(init - requests[i]);
        total_movement += distance;
        outFile << "De " << init << " a " << requests[i] << " = |" << init << " - " << requests[i] << "| = " << distance << endl;
        init = requests[i];
    }

    // Terminar de llegar a 4999 y volver a 0
    if (!requests.empty()) {
        int distance = abs(init - 4999); 
        total_movement += distance;
        outFile << "De " << init << " a 4999 = |" << init << " - 4999| = " << distance << endl;
        init = 0;
        distance = 4999 - 0;
        total_movement += distance;
        outFile << "De 4999 a 0 = |4999 - 0| = " << distance << endl;
    }

    //Barrido de 0 hasta la última petición y finalmente hasta arriba 
    // de 0 a 4999
    for (int i = 0; i < pos; ++i) {
        int distance = abs(init - requests[i]);
        total_movement += distance;
        outFile << "De " << init << " a " << requests[i] << " = [" << init << " - " << requests[i] << "] = " << distance << endl;
        init = requests[i];
    }

    // Terminar de llegar a 4999
    if (!requests.empty()) {
        int distance = abs(init - 4999);
        total_movement += distance;
        outFile << "De " << init << " a 4999 = |" << init << " - 4999| = " << distance << endl;
    }

    outFile.close();

    return total_movement;
}
