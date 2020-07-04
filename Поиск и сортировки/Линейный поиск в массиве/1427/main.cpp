#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1427/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1427/output.txt");

    int N, M;
    inputFile >> N;
    inputFile >> M;
    int** mas = (int**) malloc(sizeof(int*) * N);
    for(int i = 0; i < N; i++)
        mas[i] = (int*) malloc(sizeof(int) * M);
    
    int* minI = (int*) malloc(sizeof(int) * N);
    int* maxJ = (int*) malloc(sizeof(int) * M);
    memset(minI, 10000, sizeof(int) * N);
    memset(maxJ, -10000, sizeof(int) * M);

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            inputFile >> mas[i][j];
            if (mas[i][j] < minI[i])
                minI[i] = mas[i][j];
            if (mas[i][j] > maxJ[j])
                maxJ[j] = mas[i][j];
        }

    int res = 0;
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            if ((mas[i][j] == minI[i]) && (mas[i][j] == maxJ[j]))
                res += 1;
    
    outputFile << res;

    free(minI);
    free(maxJ);
    for(int i = 0; i < N; i++)
        free(mas[i]);
    free(mas);

    inputFile.close();
    outputFile.close();
    
    return 0;
}