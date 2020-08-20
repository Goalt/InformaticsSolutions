#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> tokens;
    string cl;
    int i = 0;
    while(s[i] != ' ') {
        cl.push_back(s[i]);
        i++;
    }
    tokens.push_back(cl);
    
    cl.clear();
    i++;
    while(i != s.size()) {
        cl.push_back(s[i]);
        i++;
    }
    tokens.push_back(cl);

    return tokens;
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("49/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("49/output.txt");

    queue<string> class9;
    queue<string> class10;
    queue<string> class11;

    string line;
    while (getline(inputFile, line)) {
        vector<string> results;
        results = split(line);
        if (results[0] == "9")
            class9.push(results[1]);
        if (results[0] == "10")
            class10.push(results[1]);
        if (results[0] == "11")
            class11.push(results[1]);
    }

    while(class9.size()) {
        outputFile << "9 ";
        outputFile << class9.front() << endl;
        class9.pop();
    }

    while(class10.size()) {
        outputFile << "10 ";
        outputFile << class10.front() << endl;
        class10.pop();
    }

    while(class11.size()) {
        outputFile << "11 ";
        outputFile << class11.front() << endl;
        class11.pop();
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}