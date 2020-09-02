#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1425/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1425/output.txt");

    int N;
    inputFile >> N;
    int* mas = (int*) malloc(sizeof(int) * N);

    int imin = 0;
    for(int i = 0; i < N; i++) {
        inputFile >> mas[i];
        if (mas[i] < mas[imin])
            imin = i;
    }

    int count[127];
    memset(count, 0, sizeof(int) * 127);

    for(int i = 0; i < N; i++)
        count[mas[i] - mas[imin]] += 1;
    
    for(int i = 0; i < 127; i++) {
        for(int j = 0; j < count[i]; j++) {
            outputFile << i + mas[imin] << " ";
        }
    }

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}