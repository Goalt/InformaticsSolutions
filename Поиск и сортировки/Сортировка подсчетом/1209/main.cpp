#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1209/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1209/output.txt");

    int N;
    inputFile >> N;
    int* c = (int*) malloc(sizeof(int) * N);
    for(int i = 0; i < N; i++) {
        inputFile >> c[i];
    }

    int K;
    inputFile >> K;
    for(int i = 0; i < K; i++) {
        int tmp;
        inputFile >> tmp;
        c[tmp - 1] -= 1;
    }

    for(int i = 0; i < N; i++) {
        if (c[i] < 0) {
            outputFile << "yes" << endl;
        } else
            outputFile << "no" << endl;
    }

    free(c);

    inputFile.close();
    outputFile.close();
    
    return 0;
}