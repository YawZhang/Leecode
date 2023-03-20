#include<bits/stdc++.h>

using namespace std;


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0;
        int lenB = 0;

        ListNode* curA = headA;
        ListNode* curB = headB;

        while( curA ) {
            lenA++;
            curA = curA->next;
        }
        while( curB ) {
            lenB++;
            curB = curB->next;
        }
        cout << lenA  << " " << lenB << endl;

        if (lenA < lenB) {
            swap(lenA, lenB);
            swap(headA, headB);
        }

        int gap = lenA - lenB;
        curA = headA;
        curB = headB;
        while ( gap-- ) {
            curA = curA->next;
        }
        
        while(curA!=NULL){
            if(curA == curB){
                return curA;
            }
            curA = curA->next;
            curB = curB->next;
        }
    
        return NULL;
    }
};


ListNode* initList(vector<int> v) {
    ListNode* head = new ListNode();
    
    if ( v.size() >= 1 ){
        head->val = v[0];
    }
    ListNode* cur = head;

    
    if (v.size() > 1) {
        for ( int i=1; i < v.size(); i++) {
            cur->next = new ListNode (v[i]);
            cur = cur->next;
        }
    }
    return head;
}


int main() {

    vector<int> a = {1,9,1,2,4};
    vector<int> b = {3,2,4};
    ListNode* headA = initList(a);
    ListNode* headB = initList(b);
    int skipA = 2;
    int skipB = 0;

    ListNode* curA = headA;
    ListNode* curB = headB;
    
    while(skipA--){
        curA = curA->next;
    }
    while( skipB--) {
        curB = curB->next;
    }
    curA->next = curB->next;

    Solution S;
    ListNode* ans = S.getIntersectionNode(headA, headB);
    if (ans != NULL) {
        cout << ans->val << endl;

    }

    return 0;
}
