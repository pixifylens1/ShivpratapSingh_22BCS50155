#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if (!head) return nullptr;

        ListNode* current = head;
        while (current->next) {
            if (current->val == current->next->val) {
                ListNode* temp = current->next;
                current->next = current->next->next;
                delete temp;
            } else {
                current = current->next;
            }
        }
        return head;
    }
};

void printList(ListNode* head) {
    while (head) {
            cout << head->val << " ";
        head = head->next;
    }
        cout <<     endl;
}

ListNode* newNode(int data) {
    ListNode* temp = new ListNode(data);
    temp->next = NULL;
    return temp;
}

int main() {
    ListNode* head = newNode(1);
    head->next = newNode(1);
    head->next->next = newNode(2);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(3);

        cout << "Original list: ";
    printList(head);

    Solution sol;
    head = sol.deleteDuplicates(head);

        cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}