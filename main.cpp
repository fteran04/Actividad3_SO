#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <set>
#include "FCFS.h"
#include "SCAN.h"
#include "CSCAN.h"

using namespace std;

int main(){
    int randomNum, num, posicionInicial, movFcfs, movScan, movCscan;
    srand(time(nullptr));
    ofstream archivoEscritura("randomRequest.txt");
    vector<int> requests;
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
        requests.push_back(num);
    }
    archivoLectura.close();

    // Posicion inicial de la cabeza, se toma un valor arbitrario que se encuentre en vector de consultas
    posicionInicial = requests[0];

    //movFcfs = FCFS(requests, posicionInicial);
<<<<<<< HEAD
    //movScan = SCAN(requests, posicionInicial);
    movCscan = CSCAN(requests, posicionInicial);

    cout << "La cantidad de movimientos para cada algoritmo es:" << endl;
    //cout << "FCFS = " << movFcfs << endl;
    //cout << "SCAN = " << movScan << endl;
    cout << "C-SCAN = " << movCscan << endl;
=======
    movScan = SCAN(requests, posicionInicial);
    //movCscan = CSCAN(requests, posicionInicial);

    cout << "La cantidad de movimientos para cada algoritmo es:" << endl;
    //cout << "FCFS = " << movFcfs << endl;
    cout << "SCAN = " << movScan << endl;
    //cout << "C-SCAN = " << movCscan << endl;
>>>>>>> 1bc28588f554e26d8235daa9b1a42a3336fe4634
    return 0;
}