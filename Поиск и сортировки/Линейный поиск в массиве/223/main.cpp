#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("223/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");

    int N;
    inputFile >> N;
    int* mas = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];
    int x;
    inputFile >> x;

    int cntX = 0;
    for (int i = 0; i < N; i++)
        if (mas[i] == x) cntX += 1;

    outputFile << cntX;

    free(mas);
    
    inputFile.close();
    outputFile.close();
    
    return 0;
}