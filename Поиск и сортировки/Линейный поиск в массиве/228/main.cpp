#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("228/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("228/output.txt");

    int N;
    inputFile >> N;
    int* mas = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];

    int maxIndex = 0;
    for (int i = 0; i < N; i++)
        if (mas[i] > mas[maxIndex]) maxIndex = i;
    
    outputFile << maxIndex + 1;

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}