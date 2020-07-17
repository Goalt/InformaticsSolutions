#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("3044/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("3044/output.txt");

    int count[20001];
    memset(count, 0, sizeof(int) * 20001);
    int N;
    inputFile >> N;
    for (int i = 0; i < N; i++) {
        int tmp;
        inputFile >> tmp;
        int pos = 10000 + tmp;
        count[pos]++;
    }
    
    for (int i = 0; i < 20001; i++) {
        if (count[i] != 0) {
            for (int j = 0; j < count[i]; j++)
                outputFile << (-10000 + i) << " ";
        }
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}