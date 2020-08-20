#include <iostream>
#include <fstream>

using namespace std;
ofstream outputFile;

struct Node {
    Node* next;
    int data;
};

Node* head, *endNode, *center;
int sizeOfList = 0;
int positionOfCenter = -1;

void pop() {
    if(sizeOfList == 0)
        return;
    
    if(sizeOfList == 1) {
        head = NULL;
        center = NULL;
        endNode = NULL;
        sizeOfList = 0;
        positionOfCenter = -1;
        return;
    }

    head = head->next;
    sizeOfList--;
    while(positionOfCenter != ((sizeOfList - 1) / 2)) {
        center = center->next;
        positionOfCenter++;
    }
}

void push(int data) {
    if(head == NULL) {
        // Список пуст
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->data = data;
        newNode->next = NULL;
        head = newNode;
        endNode = newNode;
        center = newNode;
        sizeOfList++;
        positionOfCenter = 0;
        return;
    }

    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    endNode->next = newNode;
    endNode = newNode;

    sizeOfList++;
    while(positionOfCenter != ((sizeOfList - 1) / 2)) {
        center = center->next;
        positionOfCenter++;
    }
}

// void insertInTheCenter()

void print() {
    Node* cursor = head;
    while(cursor != NULL) {
        outputFile << cursor->data << " ";
        cursor = cursor->next;
    }
    outputFile << endl;
}


int main() {
    // This task is not complete
    ifstream inputFile;
    // inputFile.open("input.txt");
    inputFile.open("112984/input.txt");
    
    // outputFile.open("output.txt");
    outputFile.open("112984/output.txt");

    push(1);
    print();
    outputFile << center->data << endl;

    push(2);
    print();
    outputFile << center->data << endl;

    push(3);
    print();
    outputFile << center->data << endl;

    push(4);
    print();
    outputFile << center->data << endl;

    push(5);
    print();
    outputFile << center->data << endl;

    inputFile.close();
    outputFile.close();
    
    return 0;
}