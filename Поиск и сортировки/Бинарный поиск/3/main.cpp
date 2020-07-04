#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("3/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("3/output.txt");

    int N;
    inputFile >> N;
    if (N <= 2)
        outputFile << 1;
    else
        outputFile << ceil(log2(N));

    inputFile.close();
    outputFile.close();
    
    return 0;
}