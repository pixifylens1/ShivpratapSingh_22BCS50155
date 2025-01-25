#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

struct compare {
    bool operator()(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }
};

ListNode* mergeKLists(vector<ListNode*>& lists) {
    priority_queue<ListNode*, vector<ListNode*>, compare> pq;
    
    for (auto list : lists) {
        if (list) {
            pq.push(list);
        }
    }
    
    ListNode* dummy = new ListNode(0);
    ListNode* tail = dummy;
    
    while (!pq.empty()) {
        ListNode* top = pq.top();
        pq.pop();
        tail->next = top;
        tail = tail->next;
        
        if (top->next) {
            pq.push(top->next);
        }
    }
    
    return dummy->next;
}

int main() {
    ListNode* l1 = new ListNode(1);
    l1->next = new ListNode(4);
    l1->next->next = new ListNode(5);

    ListNode* l2 = new ListNode(1);
    l2->next = new ListNode(3);
    l2->next->next = new ListNode(4);

    ListNode* l3 = new ListNode(2);
    l3->next = new ListNode(6);

    vector<ListNode*> lists = {l1, l2, l3};
    ListNode* result = mergeKLists(lists);

    while (result) {
        cout << result->val << " ";
        result = result->next;
    }

    return 0;
}