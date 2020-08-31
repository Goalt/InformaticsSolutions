#include <iostream>
#include <fstream>

using namespace std;

long long A(long long i) {
    return i * i;
}

long long B(long long i) {
    return i*i*i;
}


int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1442/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1442/output.txt");

    int x;
    inputFile >> x;

    int i = 0;
    int j = 0;

    for(int k = 0; k < x; k++) {
        if (A(i) < B(j)) {
            i++;
        } else if (A(i) > B(j)) {
            j++;
        } else {
            i++;
            j++;
        }
    }

    if (A(i) < B(i))
        outputFile << A(i);
    else 
        outputFile << B(j);

    inputFile.close();
    outputFile.close();
    
    return 0;
}