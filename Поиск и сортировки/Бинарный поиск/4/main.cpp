#include <iostream>
#include <fstream>

using namespace std;

bool binSearch(int* mas, int N, int x) {
    int l = 0;
    int r = N - 1;
    while(r - l > 1) {
        int cnt = (r + l) / 2;
        if (mas[cnt] == x) return true;
        
        if(mas[cnt] < x) l = cnt;
        else r = cnt;
    }

    if ((mas[l] == x) || (mas[r] == x))
        return true;
    
    return false;
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("4/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("4/output.txt");

    int N, K;
    inputFile >> N;
    inputFile >> K;

    int* mas = (int*) malloc(sizeof(int) * N);
    for (int i  = 0; i < N; i++) 
        inputFile >> mas[i];

    for (int i = 0; i < K; i++) {
        int x;
        inputFile >> x;
        if (binSearch(mas, N, x)) outputFile << "YES" << endl;
        else outputFile << "NO" << endl;
    }

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}