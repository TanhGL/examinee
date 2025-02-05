#include <iostream>
using namespace std;

struct Node {
    int value;
    Node* next;
};
bool KtSNT(int x)
{
	if(x<2)
		return false;
	for(int i=2; i<=x/2; i++)
		if(x%i==0)
			return false;
	return true;

}
struct LinkedList {
    Node* head;
    Node* tail;

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

    void printReverseUtil(Node* node) {
        if (node == NULL) {
            return;
        }
        printReverseUtil(node->next);
        cout << node->value << " ";
    }
    
    void printNumberNode(){
        int i = 0;
        Node* pCur = head;
        while (pCur != NULL) {
            i++;
            pCur = pCur->next;
        }
        cout << "Số lượng phần tử trong mảng: " << i <<endl; 
    }
    
    void printNumberNodeOld(){
        int i = 0;
        Node* pCur = head;
        while (pCur != NULL) {
            if(pCur->value%2 !=0)
                    i++;
            pCur = pCur->next;
        }
        cout << "Số lượng phần tử lẻ trong mảng: " << i <<endl; 
    }
    void printNumberNodeEven(){
        int i = 0;
        Node* pCur = head;
        while (pCur != NULL) {
            if(pCur->value%2 ==0)
                i++;
            pCur = pCur->next;
        }
        cout << "Số lượng phần tử chẵn trong mảng: " << i <<endl; 
    }
    void printSNT(){
        int i = 0,tmp = 0, x = 0;
        Node* pCur = head;
        while (pCur != NULL) {

            if(KtSNT(pCur->value) == true){
                tmp = i;
                x = pCur->value;
                break;
            }
            i++;
            pCur = pCur->next;
            
        }
        if(tmp != 0){
            cout << "Vị trí số nguyên tố đầu tiên trong mảng là " << tmp  << " với giá trị là: " <<x << endl;
        }
        else
         cout << "Không có số nguyên tố trong mảng" << endl;
    }
    
    void printListOld(){
        LinkedList listold;
        Node* pCur = head;
        while (pCur != NULL) {
            if(pCur->value%2!=0){
                listold.addTail(pCur->value);
            }
            pCur = pCur->next;
        }
        listold.print();
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
    
    list.printNumberNode();
    
    list.printNumberNodeEven();
    
    list.printNumberNodeOld();
    
    list.printSNT();
    cout << "Danh sách phần tử lẻ trong mảng: ";
    list.printListOld();
    return 0;
}
