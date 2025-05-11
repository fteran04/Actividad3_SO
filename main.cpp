#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <set>
#include "FCFS.h"
#include "SCAN.h"
#include "CSCAN.h"

using namespace std;

int main(){
    int randomNum, num, posicionInicial, movFcfs, movScan, movCscan;
    srand(time(nullptr));
    ofstream archivoEscritura("randomRequest.txt");
    vector<int> requests1, requests2, requests3;
    set<int> nums;

    // generación de 1000 consultas random
    while(nums.size() != 1000){
        randomNum = rand() % 5000;
        if(nums.find(randomNum) == nums.end()){
            archivoEscritura << randomNum << endl;
            nums.insert(randomNum);
        }
        
    }
    archivoEscritura.close();

    // lectura del archivo con 1000 consultas
    ifstream archivoLectura("randomRequest.txt");
    while(archivoLectura >> num){
        requests1.push_back(num);
        requests2.push_back(num);
        requests3.push_back(num);
    }
    archivoLectura.close();

    // Posicion inicial de la cabeza, se toma un valor arbitrario que se encuentre en vector de consultas
    posicionInicial = requests1[0];
    posicionInicial = requests2[0];
    posicionInicial = requests3[0];

    movFcfs = FCFS(requests1, posicionInicial);
    movScan = SCAN(requests2, posicionInicial);
    movCscan = CSCAN(requests2, posicionInicial, false);

    cout << "La cantidad de movimientos para cada algoritmo es:" << endl;
    cout << "FCFS = " << movFcfs << endl;
    cout << "SCAN = " << movScan << endl;
    cout << "C-SCAN = " << movCscan << endl;
    return 0;
}