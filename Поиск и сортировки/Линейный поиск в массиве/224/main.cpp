#include <iostream>
#include <fstream>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("224/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("224/output.txt");

    int N;
    inputFile >> N;
    int* mas = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];
    int x;
    inputFile >> x;

    bool flag = false;
    for (int i = 0; i < N; i++)
        if (mas[i] == x) {
            flag = true;
            break;  
        } 

    if (flag)
        outputFile << "YES";
    else
        outputFile << "NO";

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}