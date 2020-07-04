#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1440/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1440/output.txt");

    int N;
    inputFile >> N;

    int first, second = -1;
    inputFile >> first;
    
    for(int i = 1; i < N; i++) {
        int tmp;
        inputFile >> tmp;
        if (tmp == first)
            continue;
        if (tmp > first) {
            second = first;
            first = tmp;
        }
        else if (tmp > second)
            second = tmp;
    }

    outputFile << second;

    inputFile.close();
    outputFile.close();
    
    return 0;
}