#include <iostream>
#include <fstream>
#include <limits>

using namespace std;

// #define MAXSIZE 150010
#define MAXSIZE 10
ofstream outputFile;
int* positions;
int tmp;

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
        swap(positions[i], positions[smallest]);
        heapify(h, smallest);
    }
}

void shiftMas(int* mas, int N) {
    for (int i = 0; i < N - 1; i++)
        mas[i] = mas[i + 1];   
}

int extract(Heap &h) {
    int minNumber = h.data[0];
    
    h.data[0] = tmp;
    // swap(positions[0], positions[h.size - 1]);
    shiftMas(positions, h.size);
    positions[h.size - 1] = 0;

    heapify(h, 0);
    return minNumber;
}

void deleteByIndex(Heap &h, int index) {
    h.data[index] = std::numeric_limits<int>::min();
    
    int i = index;
    int parent = (i - 1) / 2;
    while ((i > 0) && (h.data[parent] > h.data[i])) {
        swap(h.data[i], h.data[parent]);
        swap(positions[i], positions[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }

    extract(h);
}

void makeHeap(Heap &h, int* data, int N) {
    h.size = N;
    for(int i = 0; i < N; i++)
        h.data[i] = data[i];
    
    for (int i = h.size / 2; i >= 0; i--)
        heapify(h, i);
}

void printHeap(Heap &h) {
    for (int i = 0; i < h.size ; i++) {
        outputFile << h.data[i] << " ";
    }
    outputFile << endl;
}

int insert(Heap &h, int k) {
    h.data[h.size] = k;
    h.size++;

    int i = h.size - 1;
    int parent = (i - 1) / 2;
    int key = i;
    while ((i > 0) && (h.data[parent] > h.data[i])) {
        swap(h.data[i], h.data[parent]);
        swap(positions[i], positions[parent]);
        i = parent;
        parent = (i - 1) / 2;
        key = i;
    }

    return key;
}

int main() {
    // This task is not complete !!!

    ifstream inputFile;
    // inputFile.open("input.txt");
    inputFile.open("756/input.txt");
    
    // outputFile.open("output.txt");
    outputFile.open("756/output.txt");

    int N, K;
    inputFile >> N >> K;
    positions = (int*) malloc(sizeof(int) * K);
    for (int i = 0; i < K; i++)
        positions[i] = i;
    int* data = (int*) malloc(sizeof(int) * K);
    for (int i = 0; i < K; i++)
        inputFile >> data[i];

    Heap h;
    makeHeap(h, data, K);

    outputFile << h.data[0] << " ";

    for (int i = K; i < N; i++) {
        inputFile >> tmp;
        deleteByIndex(h, positions[0]);
        outputFile << h.data[0] << " ";
    }

    free(positions);
    free(data);
    inputFile.close();
    outputFile.close();
    
    return 0;
}