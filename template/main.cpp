#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile;
    // inputFile.open("input.txt");
    inputFile.open("template/input.txt");
    
    ofstream outputFile;
    // outputFile.open("output.txt");
    outputFile.open("template/output.txt");



    inputFile.close();
    outputFile.close();
    
    return 0;
}