#include <iostream>
#include <vector>
#include <chrono>
#include "ThreadPool.h"
#include <time.h>
#include <stdlib.h>
#include <ctime>

using namespace   std;

int CELDAS = 1000;


void LlenarMatriz(int matriz[][1000]){
    //srand(time(NULL));
    int size = sizeof(matriz[0])/sizeof(matriz[0][0]); 
    cout<<"Este es el tamaño ->>>>"<<size<<endl;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            matriz[i][j] = rand()%(3);
        }
    }
}
// Imprimir Matriz
void printMatriz(int matriz[][1000]){
    int size = sizeof(matriz[0])/4;
    for (int i=0; i<size; i++){
        for (int j=0; j<size; j++){
            cout<<matriz[i][j]<<" ";
        }
            cout<<endl;
    }
}


vector<future<int>> multPorCeldas(int firstMatrix [][1000], int secondMatrix[][1000]){
    int size = sizeof(firstMatrix[0])/4;
    ThreadPool pool (4);
    vector<future<int>> results;
    for (int i = 0; i< size; i++){
        for (int j = 0; j < size; j++){
            results.emplace_back(
                //Here going to write the function for thread
                pool.enqueue([size, firstMatrix, secondMatrix, i, j] {
                    int cell = 0;
                    for (int k = 0; k < size; k++){
                        cell = cell + (firstMatrix[i][k] * secondMatrix[k][j]);  
                    }
                    return cell;
               
                })
            );
        
        }
    }
    return results;
}
int firstMatrix[1000][1000];
int secondMatrix[1000][1000];

int main()
{   
    LlenarMatriz(firstMatrix);
    printMatriz(firstMatrix);
    cout<<endl<<"- - - Multiplicada por - - -"<<endl<<endl;
    LlenarMatriz(secondMatrix);
    printMatriz(secondMatrix); 
    cout<<endl<<"- - -    Resultado - - -"<<endl<<endl;  
    double promTimes = 0;
    unsigned t0, t1; 
    t0 = clock();
    multPorCeldas(firstMatrix,secondMatrix);
    t1 = clock();    
    double time = (double(t1-t0)/CLOCKS_PER_SEC);
    promTimes = promTimes + time;   
    cout << "Execution time "<< promTimes << endl;
    return 0;
}
