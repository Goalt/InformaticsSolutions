#include <iostream>
#include <fstream>

using namespace std;

bool check(int* mas, int N, int K, int x) {
    int cnt = K - 1;
    int i = 0;
    int tmp = 0;
    while ((cnt != 0) && (i < N)) {
        tmp += mas[i];
        if (tmp >= x) {
            cnt--;
            tmp = 0;
        }
        i++;
    }

    if (cnt) return false;
    else return true;
}

int binSearch(int left, int right, int N, int K, int* mas) {
    int l = left;
    int r = right;
    while (r - l > 1) {
        int cnt = (r + l) / 2;
        if (check(mas, N, K, cnt)) l = cnt;
        else r = cnt;
    }

    if (check(mas, N, K, r))
        return r;
    if (check(mas, N, K, l))
        return l;
    return -1;
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1_1/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1_1/output.txt");

    int N, K;
    inputFile >> N >> K;
    int* masDist = (int*) malloc(sizeof(int) * (N - 1));
    int tmp1, tmp2;
    inputFile >> tmp1;
    for (int i = 0; i < N - 1; i++) {
        inputFile >> tmp2;
        masDist[i] = tmp2 - tmp1; 
        tmp1 = tmp2;
    }

    // for (int i = 0; i < N - 1; i++)
    //     outputFile << masDist[i] << " ";
    // outputFile << endl;

    int left = 0;
    int right = 2e9;
    outputFile << binSearch(left, right, N, K, masDist);

    free(masDist);
    inputFile.close();
    outputFile.close();
    
    return 0;
}