#include <iostream>
#include <fstream>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("229/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("229/output.txt");

    int N;
    inputFile >> N;
    int* mas =(int*) malloc(sizeof(int) * N);
    int max = 0;
    for (int i = 0; i < N; i++) {
        inputFile >> mas[i];
        if (mas[i] > mas[max])
            max = i;
    }
    
    swap(mas[0], mas[max]);
    
    for (int i = 0; i < N; i++)
        outputFile << mas[i] << " ";

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}