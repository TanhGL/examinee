#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};

class LinkedList {
    Node* head;
    Node* tail;

public:
    LinkedList() {
        head = NULL;
        tail = NULL;
    }

    void addTail(int value) {
        Node* newNode = new Node;
        newNode->value = value;
        newNode->next = NULL;

        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    void print() {
        Node* pCur = head;
        while (pCur != NULL) {
            cout << pCur->value << " ";
            pCur = pCur->next;
        }
        cout << endl;
    }

    void printReverse() {
        printReverseUtil(head);
        cout << endl;
    }

private:
    void printReverseUtil(Node* node) {
        if (node == NULL) {
            return;
        }
        printReverseUtil(node->next);
        cout << node->value << " ";
    }
};

int main() {
    LinkedList list;
    int value;

    //cout << "Nhập các số nguyên theo thứ tự tăng dần (dừng khi gặp -1):\n";
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        list.addTail(value);
    }

    cout << "Danh sách từ đầu đến cuối: ";
    list.print();

    cout << "Danh sách từ cuối đến đầu: ";
    list.printReverse();

    return 0;
}
