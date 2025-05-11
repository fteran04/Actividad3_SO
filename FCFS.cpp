#include "FCFS.h"

using namespace std;

int FCFS(vector<int> &requests, int init){
    int ans = 0, i;
    ofstream archivo("ordenMovimientosFcfs.txt");
    archivo << "De " << init << " a " << requests[0] << " = |" << init << " - " << requests[0] << "| = " << abs(init - requests[0]) << endl;
    for(i = 1; i < requests.size(); i++){
        ans += abs(requests[i] - requests[i - 1]);
        archivo << "De " << requests[i - 1] << " a " << requests[i] << " = |" << requests[i - 1] << " - " << requests[i] << "| = " << abs(requests[i] - requests[i - 1]) << endl;
    }
    archivo.close();
    return ans;
}