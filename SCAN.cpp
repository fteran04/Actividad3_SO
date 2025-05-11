#include "SCAN.h"

using namespace std;
/*Implementación del algoritmo de control del brazo del disco duro moviendose inicialmente hacia abajo*/
int SCAN(vector<int> &requests, int init){
    sort(requests.begin(), requests.end());
    ofstream archivo("ordenMovimientosScan.txt");
    int i = 0, ans = 0, pos;
    bool flag = true;
    while(i < requests.size() && flag){
        if(requests[i] == init)
        flag = false;

        i++;
    }
    pos = i;
    // bajada
    for(i = pos - 1; i > 0; i --){
        ans += abs(requests[i] - requests[i - 1]);
        archivo << "De " << requests[i] << " a " << requests[i - 1] << " = |" << requests[i] << " - " << requests[i - 1] << "| = " << abs(requests[i] - requests[i - 1]) << endl;
    }
    ans += requests[0];
    archivo << "De " << requests[i] << " a " << 0 << " = |" << requests[i] << " - " << 0 << "| = " << requests[i] << endl;
    
    // subida
    archivo << "De " << 0 << " a " << requests[pos] << " = |" << 0 << " - " << requests[pos] << "| = " << requests[pos] << endl;
    ans += requests[pos];

    for(i = pos + 1; i < requests.size(); i++){
        ans += abs(requests[i - 1] - requests[i]);
        archivo << "De " << requests[i - 1] << " a " << requests[i] << "= |" << requests[i - 1] << " - " << requests[i] << "| = " << abs(requests[i] - requests[i - 1]) << endl;
    }
    ans += 4999 - requests[i - 1];
    archivo << "De " << requests[i - 1] << " a " << 4999 << " = |" << 4999 << " - " << requests[i - 1] << "| = " << abs(4999 - requests[i - 1]) << endl;

    archivo << "Cantidad total de movimientos = " << ans << endl;
    archivo.close();

    return ans;
}