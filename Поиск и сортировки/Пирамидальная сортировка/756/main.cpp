#include <iostream>
#include <fstream>
#include <limits>
#include <queue>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("756/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("756/output.txt");

    int N, K;
    inputFile >> N >> K;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    int i = 0;
    while(i < K) {
        int tmp;
        inputFile >> tmp;
        q.push(pair<int, int>(tmp, i));
        i++;        
    }

    while(i <= N) {
        pair<int, int> tmp;
        tmp = q.top();
        if (tmp.second < (i - K)) {
            q.pop();
            continue;
        } else {
            outputFile << tmp.first << endl;
        }

        int tmp2;
        inputFile >> tmp2;
        q.push(pair<int, int>(tmp2, i));
        i++;
    }



    inputFile.close();
    outputFile.close();
    
    return 0;
}