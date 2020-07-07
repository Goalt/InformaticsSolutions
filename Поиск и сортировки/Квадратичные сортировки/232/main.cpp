#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

// Assumption: pos1 > pos2
void insert(int* mas, int N, int pos1, int pos2) {
    int tmp = mas[pos1];
    // memcpy(mas + pos2 * sizeof(int), );
    for(int i = pos1; i > pos2; i--)
        mas[i] = mas[i - 1];
    mas[pos2] = tmp;
}

void insertSort(int* mas, int N) {
    for(int i = 1; i < N; i++) {
        int pos = -1;
        for (int j = 0; j < i; j++)
            if (mas[j] > mas[i]) { 
                pos = j;
                break;
            }
        if (pos != -1)
            insert(mas, N, i, pos);
    }
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("232/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("232/output.txt");

    int N;
    inputFile >> N;
    int* mas = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];
    
    insertSort(mas, N);

    for (int i = 0; i < N; i++)
        outputFile << mas[i] << " ";

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}