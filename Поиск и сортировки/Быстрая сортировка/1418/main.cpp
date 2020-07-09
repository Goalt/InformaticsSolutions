#include <iostream>
#include <fstream>
#include <set>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1418/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1418/output.txt");

    int N;
    inputFile >> N;
    set<int> setOfNumbers;
    for (int i = 0; i < N; i++) {
        int tmp;
        inputFile >> tmp;
        setOfNumbers.insert(tmp);
    }
    
    outputFile << setOfNumbers.size();

    inputFile.close();
    outputFile.close();
    
    return 0;
}