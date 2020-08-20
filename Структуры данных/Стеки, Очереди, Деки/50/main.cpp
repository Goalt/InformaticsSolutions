#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("50/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("50/output.txt");

    queue<int> firstPlayerHand;
    queue<int> secondPlayerHand;
    
    for(int i = 0; i < 5; i++) {
        int tmp;
        inputFile >> tmp;
        firstPlayerHand.push(tmp);
    }

    for(int i = 0; i < 5; i++) {
        int tmp;
        inputFile >> tmp;
        secondPlayerHand.push(tmp);
    }

    int i = 0;
    while ((i < 10e6) && (firstPlayerHand.size()) && (secondPlayerHand.size())) {
        int c1, c2;
        c1 = firstPlayerHand.front();
        c2 = secondPlayerHand.front();
        firstPlayerHand.pop();
        secondPlayerHand.pop();
        bool firstWin = true;
        if ((c2 == 0) && (c1 == 9))
            firstWin = false;
        if (c2 > c1)
            firstWin = false;
        if ((c1 == 0) && (c2 == 9))
            firstWin = true;
        
        if (firstWin) {
            firstPlayerHand.push(c1);
            firstPlayerHand.push(c2);
        } else {
            secondPlayerHand.push(c1);
            secondPlayerHand.push(c2);
        }

        i++;
    }

    if (i == 10e6)
        outputFile << "botva";
    else if (firstPlayerHand.size())
        outputFile << "first " << i;
    else
        outputFile << "second " << i;

    inputFile.close();
    outputFile.close();
    
    return 0;
}