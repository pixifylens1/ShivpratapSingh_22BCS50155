#include <iostream>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode* deleteMiddle(ListNode* head) {
    if (head == NULL || head->next == NULL) {
        delete head;
        return NULL;
    }

    ListNode* slow = head;
    ListNode* fast = head;
    ListNode* prev = NULL;

    while (fast != NULL && fast->next != NULL) {
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;

    return head;
}

void printList(ListNode* head) {
    ListNode* temp = head;
    while (temp != NULL) {
             cout << temp->val << " ";
        temp = temp->next;
    }
         cout <<      endl;
}

ListNode* createNode(int val) {
    return new ListNode(val);
}

int main() {
    ListNode* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

         cout << "Original list: ";
    printList(head);

    head = deleteMiddle(head);

         cout << "List after deleting middle node: ";
    printList(head);

    return 0;
}
