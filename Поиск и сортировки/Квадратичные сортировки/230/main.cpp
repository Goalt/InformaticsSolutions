#include <iostream>
#include <fstream>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}

void selectionSort(int* mas, int N) {
    for(int i = N - 1; i > 0; i--) {
        int max = 0;
        for (int j = 0; j <= i; j++)
            if (mas[max] < mas[j]) max = j;
        swap(mas[i], mas[max]);
    }
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("230/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("230/output.txt");

    int N;
    inputFile >> N;
    int* mas =(int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];

    selectionSort(mas, N);

    for (int i = 0; i < N; i++)
        outputFile << mas[i] << " ";

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}