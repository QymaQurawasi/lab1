#include <cstdlib>
#include <iostream>
#include "time.h"
#include <fstream>

using namespace std;


// Matrix output
template <typename T> int matrixOutput(T* Mat, int size, string name)
{
    cout << "\"" << name << "\" matrix output:" << endl;
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            cout << Mat[i * size + j] << " ";
        }
        cout << endl;
    }

    return 1;
}
// Matrix output to file
template <typename T>
void matrixToFile(T* Mat, int size, string filename)
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cout << "Error opening file: " << filename << endl;
        return;
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            file << Mat[i * size + j] << " ";
        }
        file << endl;
    }

    file.close();
}

int main(int argc, char* argv[])
{
    clock_t start;
    if (argc != 2)
    {
        cout << "Program usage: " << endl << "./" << argv[0] << " <n>" << endl << "where <n> is the size of square matrix" << endl;
        return -1;
    }

    const int N = atoi(argv[1]);

    cout << "Begin initializing ..." << endl;

    float* A, * B;

    // Allocating memory for 2 initial matrices
    A = new float[N * N];
    B = new float[N * N];

    // initializing matrix A and B with random numbers
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            A[i * N + j] = (i + 1) * (j + 1);
            B[i * N + j] = (i + 1) + 2 * (j + 1);
        }
    matrixToFile(A, N, "matrix_A10.txt");
    matrixToFile(B, N, "matrix_B10.txt");
    //matrixOutput<float>(A, N, "A");
    //matrixOutput<float>(B, N, "B");    

    float* C = new float[N * N];

    cout << "Begin calculating ..." << endl;

    start = clock();

    // Sequantial matrix multiplication
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            C[i * N + j] = 0;
            for (int k = 0; k < N; k++)
            {
                C[i * N + j] += A[i * N + k] * B[k * N + j];
            }
        }
    matrixToFile(C, N, "matrix_C10.txt");
    cout << endl << "Calculation time: " << double(clock() - start) / CLOCKS_PER_SEC << " seconds" << endl;

    //matrixOutput<float>(C, N, "resulting C");

    // free memory
    delete[] A;
    delete[] B;
    delete[] C;

    return 0;
}
