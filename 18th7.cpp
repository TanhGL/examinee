#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void insert(Node** head_ref, int new_data) {
    Node* new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

void printList(Node* node) {
    while (node != NULL) {
        cout << node->data << " ";
        node = node->next;
    }
}

void printListReverse(Node* node) {
    if (node == NULL) {
        return;
    }
    printListReverse(node->next);
    cout << node->data << " ";
}

int countNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        count++;
        current = current->next;
    }
    return count;
}

int countEvenNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data % 2 == 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

int countOddNodes(Node* head) {
    int count = 0;
    Node* current = head;
    while (current != NULL) {
        if (current->data % 2 != 0) {
            count++;
        }
        current = current->next;
    }
    return count;
}

bool isPrime(int n) {
    if (n <= 1) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if (n % i == 0) {
            return false;
        }
    }
    return true;
}

void printPrimePositions(Node* head) {
    int position = 0;
    bool foundPrime = false;

    while (head != NULL) {
        if (isPrime(head->data)) {
            cout << position << " ";
            foundPrime = true;
            break; // Thêm break ở đây để chỉ xuất vị trí số nguyên tố đầu tiên
        }
        position++;
        head = head->next;
    }

    if (!foundPrime) {
        cout << "Khong co snt";
    }
}

int main() {

    Node* head = NULL;

    // Nhập giá trị từ bàn phím
    int value = 0;

    while (value != -1) {

        cin >> value;

        if (value != -1) {
            insert(&head, value);
        }
    }

    // Xuất từ đầu đến cuối
    cout << "Danh sach cac so trong danh sach: ";
    
    printList(head);

    
     // Xuất từ cuối lên đầu
     cout << "\nDanh sach cac so trong danh sach theo thu tu nguoc lai: ";
     printListReverse(head);

     // Đếm số lượng phần tử trong danh sách
     cout << "\nSo luong phan tu trong danh sach: " << countNodes(head);

     // Đếm số lượng phần tử chẵn trong danh sách
     cout << "\nSo luong phan tu chan trong danh sach: " << countEvenNodes(head);

     // Đếm số lượng phần tử lẻ trong danh sách
     cout << "\nSo luong phan tu le trong danh sach: " << countOddNodes(head);

     // Xuất vị trí của các số nguyên tố trong danh sách
     cout << "\nVi tri cua cac so nguyen to trong danh sach: ";
     printPrimePositions(head);

     return 0;
}
