#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void append(int data) {
        Node* newNode = new Node{data, nullptr};
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void printList() const {
        Node* temp = head;
        while (temp) {
                cout << temp->data << " ";
            temp = temp->next;
        }
            cout <<     endl;
    }

private:
    Node* head;
};

int main() {
    LinkedList list;
    list.append(1);
    list.append(2);
    list.append(3);

        cout << "Linked List: ";
    list.printList();

    return 0;
}