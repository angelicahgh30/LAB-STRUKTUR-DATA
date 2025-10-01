#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

Node* top = NULL;  

void push(int value) {
    Node *newNode = new Node;
    newNode->value = value;
    newNode->next = top;
    top = newNode;
    cout << value << " Masuk ke stack.\n";
}

void pop() {
    if (top == NULL) {
        cout << "Stack kosong!\n";
    } else {
        cout << top->value << " Keluar dari stack.\n";
        Node *temp = top;
        top = top->next;
        delete temp;
    }
}

void display() {
    if (top == NULL) {
        cout << "Stack kosong!\n";
    } else {
        cout << "Isi stack: ";
        Node *temp = top;
        while (temp != NULL) {
            cout << temp->value << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}

int main() {
    push(7);
    push(21);
    push(35);

    cout << "\nSetelah push 3 angka:\n";
    display();
    pop();

    cout << "\nSetelah pop 1 angka:\n";
    display();

    return 0;
}
