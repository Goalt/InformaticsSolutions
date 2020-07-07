#include <iostream>
#include <fstream>

using namespace std;

void bubleSort(int* mas, int N) {
    for(int i = N - 1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (mas[j] > mas[j + 1])
                swap(mas[j], mas[j + 1]);
        }
    }
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("233/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("233/output.txt");

    int N;
    inputFile >> N;
    int* mas = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];
    
    bubleSort(mas, N);

    for (int i = 0; i < N; i++)
        outputFile << mas[i] << " ";

    free(mas);

    inputFile.close();
    outputFile.close();
    
    return 0;
}