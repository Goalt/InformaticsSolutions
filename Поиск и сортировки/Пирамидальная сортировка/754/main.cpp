#include <iostream>
#include <fstream>

#define MAXSIZE 100010
// #define MAXSIZE 20

using namespace std;

struct Heap {
    int data[MAXSIZE];
    int size = 0;
};

void heapify(Heap &h, int i) {
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    int smallest = i;
    if ((left < h.size) && (h.data[smallest] > h.data[left]))
        smallest = left;
    if ((right < h.size) && (h.data[smallest] > h.data[right]))
        smallest = right;
    if (smallest != i) {
        swap(h.data[i], h.data[smallest]);
        heapify(h, smallest);
    }
}

int Extract(Heap &h) {
    int minNumber = h.data[0];
    
    h.data[0] = h.data[h.size - 1];
    h.size--;

    heapify(h, 0);
    return minNumber;
}

void insert(Heap &h, int k) {
    h.data[h.size] = k;
    h.size++;

    int i = h.size - 1;
    int parent = (i - 1) / 2;
    while ((i > 0) && (h.data[parent] > h.data[i])) {
        swap(h.data[i], h.data[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("754/input.txt");
    
    ofstream outputFile;
    outputFile.open("output.txt");
    // outputFile.open("754/output.txt");

    Heap h;
    int N;
    inputFile >> N;
    for(int i = 0; i < N; i++) {
        int tmp;
        inputFile >> tmp;
        insert(h, tmp);
    }

    for(int i = 0; i < N; i++)
        outputFile << Extract(h) << " ";

    inputFile.close();
    outputFile.close();
    
    return 0;
}