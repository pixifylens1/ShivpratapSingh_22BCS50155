#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next || k == 0) return head;

        ListNode* current = head;
        int length = 1;
        while (current->next) {
            current = current->next;
            length++;
        }

        current->next = head;

        k = k % length;
        int stepsToNewHead = length - k;
        ListNode* newTail = current;
        while (stepsToNewHead--) {
            newTail = newTail->next;
        }
        ListNode* newHead = newTail->next;

        newTail->next = nullptr;

        return newHead;
    }
};

void printList(ListNode* head) {
    while (head) {
        cout << head->val << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution solution;
    int k = 2;
    ListNode* newHead = solution.rotateRight(head, k);

    printList(newHead);

    return 0;
}
