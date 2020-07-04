#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int* insert(int* mas, int N, int x, int pos) {
    int* tmp = (int*) malloc(sizeof(int) * (N + 1));
    memcpy(tmp, mas, N * sizeof(int));
    free(mas);
    for(int i = N; i > pos; i--)
        tmp[i] = tmp[i - 1];
    tmp[pos] = x;

    return tmp;
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("231/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("231/output.txt");

    int N;
    inputFile >> N;
    int* mas = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];
    
    int pos, x;
    inputFile >> x >> pos;
    mas = insert(mas, N, x, pos - 1);
    for (int i = 0; i < N + 1; i++)
        outputFile << mas[i] << " ";

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}