#include <iostream>
#include <fstream>

using namespace std;

int binarySearch(int* mas, int N, int x) {
    int l = 0;
    int r = N - 1;

    while(r - l > 1) {
        int cnt = (r + l) / 2;
        if (mas[cnt] == x) return x;

        if (mas[cnt] > x) r = cnt;
        else l = cnt;
    }

    long long left = mas[l];
    long long right = mas[r];
    if (abs(left - x) <= abs(right - x))
        return mas[l];
    else
        return mas[r];
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("2/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("2/output.txt");

    int N, K;
    inputFile >> N;
    inputFile >> K;

    int* mas = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];
        
    for (int i = 0; i < K; i++) {
        int x;
        inputFile >> x;
        outputFile << binarySearch(mas, N, x) << endl;
    }

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}