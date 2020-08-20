#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("52/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("52/output.txt");

    stack<int> data;
    string s;
    getline(inputFile, s);
    for (int i = 0; i < s.size(); i+=2) {
        if ((s[i]>= '0') && (s[i] <= '9'))
            data.push(s[i] - '0');
        else {
            if (s[i] == ' ')
                continue;
            int a1, a2;
            a2 = data.top();
            data.pop();
            a1 = data.top();
            data.pop();
            if (s[i] == '+')
                data.push(a1 + a2);
            if (s[i] == '-')
                data.push(a1 - a2);
            if (s[i] == '*')
                data.push(a1 * a2);
        }
    }
    
    outputFile << data.top();

    inputFile.close();
    outputFile.close();
    
    return 0;
}