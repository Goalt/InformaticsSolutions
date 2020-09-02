#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <vector>
#include <map>

using namespace std;

void increaseCounter(vector<pair<int, int>> &mas, int i) {
    mas[i].second += 1;
    
    if (i == 0)
        return;
    else
        increaseCounter(mas, mas[i].first);
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("537/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("537/output.txt");

    int N;
    inputFile >> N;
    vector<pair<int, int>> mas(10000);
    map<int, string> topics;

    int messageCounter = 1;
    for (int i = 0; i < N; i++) {
        int parent;
        inputFile >> parent;

        if (!parent) {
            // Создание топика
            string topic, message, tmp;
            getline(inputFile, tmp);
            getline(inputFile, topic);
            getline(inputFile, message);

            mas[messageCounter] = pair<int, int>(0, 1);

            topics.insert({messageCounter, topic});
        } else {
            // Ответ на сообщение
            string message, tmp;
            getline(inputFile, tmp);
            getline(inputFile, message);
            
            mas[messageCounter].first = parent;
            mas[messageCounter].second = 0;
            increaseCounter(mas, messageCounter);
        }

        messageCounter += 1;
    }
    
    int imax = 1;
    for (int i = 1; i < N + 1; i++) {
        if ((mas[i].first == 0) && (mas[imax].second < mas[i].second))
            imax = i;
    }
    
    outputFile << topics[imax];

    inputFile.close();
    outputFile.close();
    
    return 0;
}