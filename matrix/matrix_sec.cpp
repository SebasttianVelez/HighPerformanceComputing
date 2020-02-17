#include <iostream>
#include <time.h>
#include <ctime>
#include <unistd.h>

using namespace std;

void generateMatrix(int **matrix, int rows, int cols)
{
    srand(time(NULL));
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {

            matrix[i][j] = rand() % 3 + 1;
        }
    }
}

void printMatrix(int **matrix, int rows, int cols)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            cout<<matrix[i][j]<<"\t";
        }
        printf("\n");
    }
}

int calculateMult(int **matrix_one, int **matrix_two, int rows, int cols)
{
    int result = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            result = result + (matrix_one[i][j] * matrix_two[j][i]);
        }
    }
    return result;
}


int main()
{
    // Quantity of rows and cols of matrix
    int n;
    printf("Cantidad de Columnas : ");
    cin>>n;
    int rows, cols;
    rows = cols = n;

    // Generate matrix considering the number of columns
    int **matrix_one = new int *[rows];
    int **matrix_two = new int *[rows];
    

    // Generate matrix with random values
    for (int i = 0; i < rows; ++i){
        matrix_one[i] = new int[cols];
        matrix_two[i] = new int[cols];
    }
    generateMatrix(matrix_one, rows, cols);
    sleep(1);
    generateMatrix(matrix_two, rows, cols);

    
    //Print matrix to multiply
    printMatrix(matrix_one, rows, cols);
    cout<<endl<<"------ Multiplicado por --------"<<endl<<endl;
    printMatrix(matrix_two, rows, cols);
    
    //Calculate multiplication
    int result = calculateMult(matrix_one, matrix_two, rows, cols);
    cout<<"Resultado de la multiplicacion: "<<result<<endl;
    return 0;
}

//medir tiempo real de cpu

//medir el tiempo de cpu en ciclos de cpu

//Implementar secuencial, e implementar con hilos