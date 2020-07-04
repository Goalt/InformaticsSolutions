#include <iostream>
#include <fstream>

using namespace std;

int leftBinSearch(int* mas, int N, int x) {
    int l = 0;
    int r = N - 1;
    while(r - l > 1) {
        int cnt = (r + l) / 2;
        if(mas[cnt] >= x) r = cnt;
        else if(mas[cnt] < x) l = cnt;
    }

    if (mas[l] == x) return l;
    if (mas[r] == x) return r;
    else return -1;
}

int rightBinSearch(int* mas, int N, int x) {
    int l = 0;
    int r = N - 1;
    while(r - l > 1) {
        int cnt = (r + l) / 2;
        if(mas[cnt] <= x) l = cnt;
        else if(mas[cnt] > x) r = cnt;
    }

    if (mas[r] == x) return r;
    if (mas[l] == x) return l;
    else return -1;
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("111728/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("111728/output.txt");

    int N, M;
    inputFile >> N;
    inputFile >> M;
    
    int* mas = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];
    
    for (int i = 0; i < M; i++) {
        int x;
        inputFile >> x;
        int leftRes = leftBinSearch(mas, N, x);
        if (leftRes != -1) {
            outputFile << leftRes + 1 << " ";
            outputFile << rightBinSearch(mas, N, x) + 1 << endl;
        } else {
            outputFile << 0 << endl;
        }
        
    }

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}