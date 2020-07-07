#include <iostream>
#include <fstream>

using namespace std;

ofstream outputFile;

// void selectionSortPrint(int* mas, int N) {
//     for(int i = 0; i < N; i++) {
//         int min = i;
//         for (int j = i; j < N; j++)
//             if (mas[min] > mas[j]) min = j;
//         swap(mas[i], mas[min]);
//         if (i != min) {
//             for (int i = 0; i < N; i++)
//                 outputFile << mas[i] << " ";
//             outputFile << endl;
//         }
//     }
// }

// Assumption: pos1 > pos2
void insert(int* mas, int N, int pos1, int pos2) {
    int tmp = mas[pos1];
    for(int i = pos1; i > pos2; i--)
        mas[i] = mas[i - 1];
    mas[pos2] = tmp;
}

void insertSortPrint(int* mas, int N) {
    for(int i = 1; i < N; i++) {
        int pos = -1;
        for (int j = 0; j < i; j++)
            if (mas[j] > mas[i]) { 
                pos = j;
                break;
            }
        if (pos != -1) {
            insert(mas, N, i, pos);
            for (int i = 0; i < N; i++)
                outputFile << mas[i] << " ";
            outputFile << endl;
        }
    }
}


int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1436/input.txt");
    
    outputFile.open("output.txt");
    // outputFile.open("1436/output.txt");

    int K;
    inputFile >> K;
    int* mas = (int*) malloc(sizeof(int) * K);
    for (int i = 0; i < K; i++)
        inputFile >> mas[i];
    
    insertSortPrint(mas, K);

    free(mas);
    inputFile.close();
    outputFile.close();
    
    return 0;
}