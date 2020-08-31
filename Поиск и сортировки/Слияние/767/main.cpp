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
    // inputFile.open("767/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("767/output.txt");

    int N1;
    inputFile >> N1;
    int* mas1 = (int*) malloc(sizeof(int) * N1);
    
    for (int i = 0; i < N1; i++)
        inputFile >> mas1[i];
    
    int N2;
    inputFile >> N2;
    int* mas2 = (int*) malloc(sizeof(int) * N2);
    for (int i = 0; i < N2; i++)
        inputFile >> mas2[i];

    mergeSort(mas1, 0, N1-1);
    mergeSort(mas2, 0, N2-1);

    bool flag = true;
    int i = 0;
    int j = 0;
    while((i < N1) && (j < N2)) {
        if(mas1[i] != mas2[j]) {
            flag = false;
            break;
        }

        int tmp = mas1[i];
        while((mas1[i] == tmp) && (i < N1))
            i++;
        while((mas2[j] == tmp) && (j < N2))
            j++;
    }

    if ((i != N1) || (j != N2))
        flag = false;

    if (flag)
        outputFile << "YES";
    else
        outputFile << "NO";
    
    free(mas1);
    free(mas2);
    inputFile.close();
    outputFile.close();
    
    return 0;
}