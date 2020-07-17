#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

void swap(int &a, int &b) {
    int tmp = a;
    a = b;
    b = tmp;
}


void selectionSort(int* mas, int N) {
    for(int i = N - 1; i > 0; i--) {
        int max = 0;
        for (int j = 0; j <= i; j++)
            if (mas[max] < mas[j]) max = j;
        swap(mas[i], mas[max]);
    }
}


// Assumption: pos1 > pos2
void insert(int* mas, int N, int pos1, int pos2) {
    int tmp = mas[pos1];
    // memcpy(mas + pos2 * sizeof(int), );
    for(int i = pos1; i > pos2; i--)
        mas[i] = mas[i - 1];
    mas[pos2] = tmp;
}

void insertSort(int* mas, int N) {
    for(int i = 1; i < N; i++) {
        int pos = -1;
        for (int j = 0; j < i; j++)
            if (mas[j] > mas[i]) { 
                pos = j;
                break;
            }
        if (pos != -1)
            insert(mas, N, i, pos);
    }
}


void bubleSort(int* mas, int N) {
    for(int i = N - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (mas[j] > mas[j + 1])
                swap(mas[j], mas[j + 1]);
}


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


void quickSort(int* mas, int l, int R) {

}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");

    int N;
    inputFile >> N;
    int* mas =(int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        inputFile >> mas[i];

    selectionSort(mas, N);

    for (int i = 0; i < N; i++)
        outputFile << mas[i] << " ";

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}