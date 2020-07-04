#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1447/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1447/output.txt");

    int N;
    inputFile >> N;
    int* mas = (int*)malloc(sizeof(int) * N);

    int minIndex, maxIndex;
    minIndex = 0;
    maxIndex = 0;

    for(int i = 0; i < N; i++) {
        inputFile >> mas[i];
        if (mas[i] > mas[maxIndex])
            maxIndex = i;
        if (mas[i] < mas[minIndex])
            minIndex = i;
    }

    for(int i = 0; i < N; i++) {
        if(mas[i] == mas[maxIndex])
            outputFile << mas[minIndex] << " ";
        else
            outputFile << mas[i] << " ";
    }

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}