#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("229/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("229/output.txt");

    int N;
    inputFile >> N;

    int first, second;
    inputFile >> first;
    inputFile >> second;
    if (first > second)
        swap(first, second);
    
    for(int i = 2; i < N; i++) {
        int tmp;
        inputFile >> tmp;
        if (tmp < first) {
            second = first;
            first = tmp;
        }
        else if (tmp < second)
            second = tmp;
    }

    outputFile << first << " " << second;

    inputFile.close();
    outputFile.close();
    
    return 0;
}