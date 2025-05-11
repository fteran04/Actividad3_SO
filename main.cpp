#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include "FCFS.h"
#include "SCAN.h"
#include "C-SCAN.h"

using namespace std;

int main(){
    int randomNum, num, posicionInicial, movFcfs, movScan, movCscan;
    srand(time(nullptr));
    ofstream archivoEscritura("randomRequest.txt");
    vector<int> requests;
    
    // generación de 1000 consultas random
    for(int i = 0; i < 1000; i++){
        randomNum = rand() % 5000;
        archivoEscritura << randomNum << endl;
    }
    archivoEscritura.close();

    // lectura del archivo con 1000 consultas
    ifstream archivoLectura("randomRequest.txt");
    while(archivoLectura >> num){
        requests.push_back(num);
    }
    archivoLectura.close();

    // Posicion inicial de la cabeza
    posicionInicial = 2637;

    movFcfs = FCFS(requests, posicionInicial);
    movScan = SCAN(requests, posicionInicial);
    movCscan = CSCAN(requests, posicionInicial);

    cout << "La cantidad de movimientos para cada algoritmo es:" << endl;
    cout << "FCFS = " << movFcfs << endl;
    cout << "SCAN = " << movScan << endl;
    cout << "C-SCAN = " << movCscan << endl;
    return 0;
}