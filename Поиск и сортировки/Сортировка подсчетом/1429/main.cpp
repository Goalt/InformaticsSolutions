#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1429/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1429/output.txt");

    int N, L, M;
    inputFile >> L >> N >> M;
    int table[L];
    memset(table, 0, sizeof(int) * L);

    for(int i = 0; i < N; i++) {
        int x1, x2;
        inputFile >> x1 >> x2;
        x1--;
        x2--;
        for(int j = x1; j <= x2; j++)
            table[j]++;
    }

    for(int i = 0; i < M; i++) {
        int tmp;
        inputFile >> tmp;
        tmp--;
        outputFile << table[tmp] << endl;
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}