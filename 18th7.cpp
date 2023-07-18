#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* createNode(int data) {
    Node* newNode = new Node;
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void addNode(Node*& head, int data) {
    Node* newNode = createNode(data);
    if (newNode == nullptr)
        return;
    if (head == nullptr) {
        head = newNode;
    }
    else {
        Node* tail = head;
        while (tail->next != nullptr)
            tail = tail->next;
        tail->next = newNode;
    }
}

void printList(Node* head) {
    Node* currNode = head;
    while (currNode != nullptr) {
        cout << currNode->data << " ";
        currNode = currNode->next;
    }
    cout << endl;
}

void printReverseList(Node* head) {
    if (head == nullptr)
        return;
    printReverseList(head->next);
    cout << head->data << " ";
}

void deleteList(Node*& head) {
    Node* currNode;
    while (head != nullptr) {
        currNode = head;
        head = head->next;
        delete currNode;
    }
}

int main() {
    Node* head = nullptr;
    int data;z
    while (data != -1) {
        addNode(head, data);
        cin >> data;
    }

    cout << "Danh sach lien ket theo thu tu ban nhap vao: ";
    printList(head);

    cout << "Danh sach lien ket theo thu tu nguoc lai ban nhap vao: ";
    printReverseList(head);

    deleteList(head);
    return 0;
}