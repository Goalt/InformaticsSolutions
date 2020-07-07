#include <iostream>
#include <fstream>

using namespace std;

int* id;

// return true if first record less then second
bool myCmp(int id1, int id2, int score1, int score2) {
    if (score1 < score2)
        return true;
    if (score1 > score2)
        return false;
    if (id1 > id2)
        return true;
    return false;
}

// Assumption: pos1 > pos2
void insert(int* mas, int N, int pos1, int pos2) {
    int tmp = mas[pos1];
    // memcpy(mas + pos2 * sizeof(int), );
    for(int i = pos1; i > pos2; i--)
        mas[i] = mas[i - 1];
    mas[pos2] = tmp;
}

void insertSort(int* mas, int N, bool (*op)(int, int, int, int)) {
    for(int i = 1; i < N; i++) {
        int pos = -1;
        for (int j = 0; j < i; j++)
            if (!op(id[i], id[j], mas[i], mas[j])) { 
            // if (mas[j] > mas[i]) { 
                pos = j;
                break;
            }
        if (pos != -1) {
            insert(mas, N, i, pos);
            insert(id, N, i, pos);
        }
    }
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1446/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1446/output.txt");

    int N;
    inputFile >> N;
    id = (int*) malloc(sizeof(int) * N);
    int* scores = (int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        inputFile >> id[i] >> scores[i];

    insertSort(scores, N, myCmp);

    for (int i = 0; i < N; i++)
        outputFile << id[i] << " " << scores[i] << endl;
    

    free(scores);
    free(id);
    inputFile.close();
    outputFile.close();
    
    return 0;
}