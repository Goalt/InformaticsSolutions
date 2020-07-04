#include <iostream>
#include <fstream>
 #include <iomanip>

using namespace std;

double myPow(double x, int n) {
    double res = x;
    for (int i = 0; i < n-1; i++)
        res = res * x;
    return res;
}

double binSearch1(double a, int n) {
    double l = 0;
    double r = a;

    while(r - l > 1e-6) {
        double cnt = (r + l) / 2;
        if (myPow(cnt, n) < a) l = cnt;
        else r = cnt;
    }

    return l;
}

double binSearch2(double a, int n) {
    double l = 0;
    double r = 1;

    while(r - l > 1e-6) {
        double cnt = (r + l) / 2;
        if (myPow(cnt, n) < a) l = cnt;
        else r = cnt;
    }

    return l;
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("3570/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("3570/output.txt");

    double a;
    int n;
    inputFile >> a >> n;
    if (a >= 1)
        outputFile << std::fixed << std::setprecision(8) << binSearch1(a, n);
    else
        outputFile << std::fixed << std::setprecision(8) << binSearch2(a, n);

    inputFile.close();
    outputFile.close();
    
    return 0;
}