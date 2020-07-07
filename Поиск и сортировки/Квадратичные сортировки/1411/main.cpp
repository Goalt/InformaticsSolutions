#include <iostream>
#include <fstream>

using namespace std;

int countBubleSort(int* mas, int N) {
    int count = 0;
    for(int i = N - 1; i > 0; i--)
        for (int j = 0; j < i; j++)
            if (mas[j] > mas[j + 1]) {
                swap(mas[j], mas[j + 1]);
                count += 1;
            }
    return count;
}


int main() {
    // ifstream inputFile;
    // inputFile.open("input.txt");
    // inputFile.open("1411/input.txt");
    
    // ofstream outputFile;
    // inputFile.open("output.txt");
    // outputFile.open("1411/output.txt");

    int N;
    cin >> N;
    int* mas =(int*) malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++)
        cin >> mas[i];

    cout << countBubleSort(mas, N);

    // for (int i = 0; i < N; i++)
    //     outputFile << mas[i] << " ";

    free(mas);
    // inputFile.close();
    // outputFile.close();
    
    return 0;
}