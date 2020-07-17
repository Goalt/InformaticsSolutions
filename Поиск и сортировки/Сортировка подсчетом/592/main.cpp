#include <iostream>
#include <fstream>
#include <string.h>
#include <vector>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("592/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("592/output.txt");

    int mas[26];
    memset(mas, 0, sizeof(int) * 26);

    int N;
    inputFile >> N;
    int firstOdd = -1;
    for (int i = 0; i < N; i++) {
        char c;
        inputFile >> c;
        mas[c - 'A'] += 1;
    }
    
    vector<char> s;
    for (int i = 0; i < 26; i++) {
        for(int j = 0; j < mas[i] / 2; j++)
            s.push_back(i + 'A');
    }

    bool flag = false;
    for (int i = 0; i < 26; i++) {
        if (mas[i] % 2) {
            flag = true;
            s.push_back(i + 'A');
            break;
        }
    }

    int tmp;
    if (flag)
        tmp = s.size() - 2;
    else
        tmp = s.size() - 1;
    
    while (tmp >= 0) {
        s.push_back(s[tmp]);
        tmp--;
    }
    
    for (int i = 0; i < s.size(); i++)
        outputFile << s[i];

    inputFile.close();
    outputFile.close();
    
    return 0;
}