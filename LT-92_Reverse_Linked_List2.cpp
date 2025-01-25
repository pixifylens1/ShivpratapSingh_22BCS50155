#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (!head) return NULL;
        
        ListNode *prev = NULL, *current = head;
        while (m > 1) {
            prev = current;
            current = current->next;
            m--;
            n--;
        }
        
        ListNode *connection = prev, *tail = current;
        ListNode *next = NULL;
        while (n > 0) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
            n--;
        }
        
        if (connection) {
            connection->next = prev;
        } else {
            head = prev;
        }
        
        tail->next = current;
        return head;
    }
};

void printList(ListNode* node) {
    while (node != NULL) {
        cout << node->val << " ";
        node = node->next;
    }
    cout << endl;
}

ListNode* newNode(int data) {
    ListNode* temp = new ListNode(data);
    temp->next = NULL;
    return temp;
}

int main() {
    ListNode* head = newNode(1);
    head->next = newNode(2);
    head->next->next = newNode(3);
    head->next->next->next = newNode(4);
    head->next->next->next->next = newNode(5);

    cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.reverseBetween(head, 2, 4);

    cout << "Reversed list: ";
    printList(head);

    return 0;
}