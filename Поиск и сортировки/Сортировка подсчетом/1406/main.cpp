#include <iostream>
#include <fstream>
#include <string.h>

using namespace std;

bool isAnagram(string s, string t) {
        int mas[256];
        memset(mas, 0, sizeof(int) * 256);
        
        for(int i = 0; i < s.size(); i++)
            mas[s[i]]++;
        for(int i = 0; i < s.size(); i++)
            mas[t[i]]--;
        
        bool flag = true;
        for (int i = 0; i < 256; i++) {
            if (mas[i] != 0) {
                flag = false;
                break;
            }
        }
        
        return flag;
    }

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("1406/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("1406/output.txt");

    // int mas[256];
    // memset(mas, 0, sizeof(int) * 256);
    // char c;
    // inputFile.get(c);
    // while(c != '\n') {
    //     mas[c] += 1;
    //     inputFile.get(c);
    //     // inputFile >> c;
    // }
    
    // while (inputFile.get(c)) {
    //     mas[c] -= 1;
    // }

    // bool flag = true;
    // for (int i = 0; i < 256; i++) {
    //     if (mas[i] != 0) {
    //         flag = false;
    //         break;
    //     }
    // }

    string s1, s2;
    getline(inputFile, s1);
    getline(inputFile, s2);
    bool flag = isAnagram(s1, s2);

    if (flag)
        outputFile << "YES";
    else
        outputFile << "NO";
    

    inputFile.close();
    outputFile.close();
    
    return 0;
}