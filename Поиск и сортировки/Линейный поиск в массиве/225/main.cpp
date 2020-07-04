#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("225/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("225/output.txt");

    int N;
    inputFile >> N;
    int* mas = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];
    int x;
    inputFile >> x;

    int nearest = 0;
    for (int i = 1; i < N; i++)
        if (abs(mas[nearest] - x) > abs(mas[i] - x)) nearest = i;

    outputFile << mas[nearest];

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}