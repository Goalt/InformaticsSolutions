#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("51/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("51/output.txt");

    string line;
    getline(inputFile, line);
    
    bool flag = true;
    stack<int> s;
    for(int i = 0; i < line.size(); i++) {
        if ((line[i] == '(') || (line[i] == '[') || (line[i] == '{'))
            s.push(line[i]);
        else if (line[i] == ')') {
             if ((!s.size()) || (s.top() != '(')) {
                 flag = false;
                 break;
             } else {
                 s.pop();
             }
        } else if (line[i] == '}') {
             if ((!s.size()) || (s.top() != '{')) {
                 flag = false;
                 break;
             } else
                  s.pop();
        } else if (line[i] == ']') {
             if ((!s.size()) || (s.top() != '[')) {
                 flag = false;
                 break;
             } else
                 s.pop();
        }
    }

    if ((s.size()) || (!flag))
        outputFile << "no";
    else
        outputFile << "yes"; 

    inputFile.close();
    outputFile.close();
    
    return 0;
}