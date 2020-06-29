#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1412/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1412/output.txt");

    int X;
    inputFile >> X;
    int N;
    inputFile >> N;
    bool* masRes = (bool *) malloc(N * sizeof(bool));
    memset(masRes, 0, N * sizeof(bool));

    for(int i = 0; i < N; i++)
        for (int j = 0; j < N; j++) {
            int tmp;
            inputFile >> tmp;
            if (tmp == X) masRes[j] = true;
        }        

    for(int i = 0; i < N; i++) {
        if (masRes[i])
            outputFile << "YES" << endl;
        else
            outputFile << "NO" << endl;
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}