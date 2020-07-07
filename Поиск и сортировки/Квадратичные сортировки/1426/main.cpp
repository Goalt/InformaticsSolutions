#include <iostream>
#include <fstream>

using namespace std;

void selectionSort(int* mas, int N) {
    for(int i = N - 1; i > 0; i--) {
        int max = 0;
        for (int j = 0; j <= i; j++)
            if (mas[max] < mas[j]) max = j;
        swap(mas[i], mas[max]);
    }
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1426/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1426/output.txt");

    int N, M, L;
    inputFile >> N >> M;
    int* plot = (int*) malloc(sizeof(int) * N * M);
    for (int i = 0; i < N * M; i++)
        inputFile >> plot[i];
    L = N * M;

    int K;
    inputFile >> K;
    int* mel = (int*) malloc(sizeof(int) * K);
    for (int i = 0; i < K; i++)
        inputFile >> mel[i];
    
    selectionSort(plot, L);
    selectionSort(mel, K);

    int i = 0, j = 0, cnt = 0;
    while((i < L) && (j < K)) {
        if (mel[j] <= plot[i]) {
            j++;
            cnt++;
            i++;
        } else {
            i++;
        }
    }

    outputFile << cnt;

    free(mel);
    free(plot);
    inputFile.close();
    outputFile.close();
    
    return 0;
}