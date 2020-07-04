#include <iostream>
#include <fstream>
#include <cmath>

using namespace std;

long long calcCountOfDiplomas(long long sizeOfSide, long long w, long long h) {
    return (sizeOfSide / w) * (sizeOfSide / h);
}

long long binSearchSize(int minSizeOfSide, long long maxSizeOfSide, int w, int h, int N) {
    long long l = 0;
    long long r = maxSizeOfSide;

    while (r - l > 1) {
        long long cnt = (l + r) / 2;
        long long tmp = calcCountOfDiplomas(cnt, w, h);
        
        if (tmp < N) l = cnt;
        else r = cnt;
    }

    if (calcCountOfDiplomas(l, w, h) >= N)
        return l;
    if (calcCountOfDiplomas(r, w, h) >= N)
        return r;
    return -1;
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1923/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1923/output.txt");

    int w, h, N;
    inputFile >> w >> h >> N;
    
    int minSizeOfSide = min(w, h);
    long long tmp = int(sqrt(N)) + 1;
    long long maxSizeOfSide = tmp * max(w, h);

    outputFile << binSearchSize(minSizeOfSide, maxSizeOfSide, w, h, N);

    inputFile.close();
    outputFile.close();
    
    return 0;
}