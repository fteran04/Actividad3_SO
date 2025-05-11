#include "CSCAN.h"

using namespace std;

int CSCAN(vector<int> &requests, int init){
    int i,posIni,ans = 0;

    // Ordenar el vector de peticiones
    sort(requests.begin(), requests.end());

    for(i = 0; i < requests.size();i++)
        cout << requests[i] << endl;

    // Encontrar la posición inicial
    int low = 0;
    int high = requests.size() - 1;
    while (low <= high) {
        posIni = (low + high) / 2;
        if (requests[posIni] < init)
            low = posIni + 1;
        else
            high = posIni - 1;
    }
    posIni = low;
    cout << "Posicion inicial: " << init << endl;
    cout << "Posicion inicial: " << posIni << endl;
    cout << "Posicion inicial: " << requests[posIni] << endl;

    return ans;
}
