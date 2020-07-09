#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void mergeSort(int* mas, int l, int r) {
    if (r - l <= 1) {
        if (mas[r] < mas[l])
            swap(mas[r], mas[l]);
        return;
    }

    int center = (r + l) / 2;
    mergeSort(mas, l, center);
    mergeSort(mas, center + 1, r);

    int* mergedMas = (int*) malloc(sizeof(int) * (r - l + 1));
    int i = 0, j = 0, cnt = 0;
    int N1 = center - l + 1;
    int N2 = r - center;
    while((i < N1) && (j < N2)) {
        if (mas[l + i] < mas[center + j + 1]) {
            mergedMas[cnt] = mas[l + i];
            i++;
        }
        else {
            mergedMas[cnt] = mas[center + j + 1];
            j++;
        }
        cnt++;
    }

    while(i < N1) {
        mergedMas[cnt] = mas[l + i];
        i++;
        cnt++;
    }

    while(j < N2) {
        mergedMas[cnt] = mas[center + j + 1];
        j++;
        cnt++;
    }

    memcpy(mas + l, mergedMas, sizeof(int) * (r - l + 1));
    
    free(mergedMas);
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("766/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("766/output.txt");

    int N;
    inputFile >> N;
    int* mas = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];
    
    mergeSort(mas, 0, N-1);

    for (int i = 0; i < N; i++)
        outputFile << mas[i] << " ";
    
    int;

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}