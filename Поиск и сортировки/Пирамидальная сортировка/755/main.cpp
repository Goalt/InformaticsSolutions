#include <iostream>
#include <fstream>

#define MAXSIZE 100010
// #define MAXSIZE 10

using namespace std;
ofstream outputFile;

struct Heap {
    int data[MAXSIZE];
    int size = 0;
};

void heapify(Heap &h, int i) {
    int left = i * 2 + 1;
    int right = i * 2 + 2;

    int largest = i;
    if ((left < h.size) && (h.data[largest] < h.data[left]))
        largest = left;
    if ((right < h.size) && (h.data[largest] < h.data[right]))
        largest = right;
    if (largest != i) {
        swap(h.data[i], h.data[largest]);
        heapify(h, largest);
    }
}

int Extract(Heap &h) {
    int maxNumber = h.data[0];
    
    h.data[0] = h.data[h.size - 1];
    h.size--;

    heapify(h, 0);
    return maxNumber;
}

void insert(Heap &h, int k) {
    h.data[h.size] = k;
    h.size++;

    int i = h.size - 1;
    int parent = (i - 1) / 2;
    while ((i > 0) && (h.data[parent] < h.data[i])) {
        swap(h.data[i], h.data[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void printHeap(Heap &h) {
    for (int i = 0; i < h.size ; i++) {
        outputFile << h.data[i] << " ";
    }
    outputFile << endl;
}

int main() {
    ifstream inputFile;
    inputFile.open("input.txt");
    // inputFile.open("755/input.txt");
    
    outputFile.open("output.txt");
    // outputFile.open("755/output.txt");

    Heap h;
    int N;
    inputFile >> N;
    for (int i = 0; i < N; i++)
    {
        int command;
        inputFile >> command;
        if (!command) {
            int tmp;
            inputFile >> tmp;
            insert(h, tmp);
        } else {
            outputFile << Extract(h) << endl;
        }
    }

    inputFile.close();
    outputFile.close();
    
    return 0;
}