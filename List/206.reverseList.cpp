#include<bits/stdc++.h>


using namespace std;


// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    // ListNode* reverseList(ListNode* head) {
    //     ListNode* cur = head;
    //     ListNode* prev = NULL;

    //     while( cur != NULL ) {
    //         ListNode* tem = cur->next;
    //         cur->next = prev;
    //         prev = cur;
    //         cur = tem;
    //     }
    //     return prev;
    // }

    ListNode* reverseList(ListNode* head) {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* last = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return last;
    }

    void printLinkedList(ListNode* h) {
        ListNode* cur = h;
        while (cur != NULL) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};



int main() {

    vector<int> a = {1,2,3,4,5};
    int val = 2;

    ListNode* head = new ListNode();
    
    if ( a.size() > 1 ){
        head->val = a[0];
    }
    ListNode* cur = head;

    
    if (a.size() > 1) {
        for ( int i=1; i < a.size(); i++) {
            cur->next = new ListNode (a[i]);
            cur = cur->next;
        }
    }

    Solution s;
    ListNode* ss = s.reverseList(head);
    s.printLinkedList(ss);


    return 0;
}
