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
// //方法1：暴力迭代，将所有对比可能罗列
    // ListNode *detectCycle(ListNode *head) {
    //     if (head==NULL) return head;//边界条件

    //     ListNode* cur = head;
    //     ListNode* tail = head->next;
    //     while( tail != NULL ) {
    //         while(cur!=tail)
    //         {   
    //             if (cur == tail->next) return cur;
    //             cur = cur->next;
    //         }
    //         if (cur == tail->next ) return cur;
    //         tail = tail->next;
    //         cur = head;
    //     } 

    //     return NULL;

    // }


/* 方法2：通过快慢指针，快指针fast每次走两步，慢指针slow每次走一步,
    1.x为相遇节点长度，y为环内相遇节点数(x->相遇节点的节点数),z为环内剩余节点数
    2.当快慢指针相遇，则必有
        - x + y = x + y + n*(y + z)
        - 2*(x + y) =  x + y + n*(y + z) -> x = (n-1)*(y+z) + z
    3.假设n=1, x = z，此时设相遇节点为index1， 头节点为index2，两指针相遇时便是z的长度
    5.当n>1 同样成立，因为n>1的情况时index1多走了n-1圈而已，不影响index2的计数
    利用相遇条件 x+y = (n-1)(x+y)
*/
    ListNode *detectCycle(ListNode *head) { 
        ListNode* fast = head;
        ListNode* slow = head;
        while ( fast!=NULL && fast->next!=NULL) {
            fast = fast->next->next;
            slow = slow->next;

            if (fast == slow) {
                ListNode* index1 = head;
                ListNode* index2 = slow;
                while ( index1 != index2 ) {
                    index1 = index1->next;
                    index2 = index2->next;
                }
                return index1;
            } 
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

void printLinkedList(ListNode* h) {
        ListNode* cur = h;
        int cunt = 10;
        while (cur != NULL && cunt--) {
            cout << cur->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }

int main() {

    vector<int> a = {-1,-7,7,-4,19,6,-9,-5,-2,-5};
    int pos =  9;
    int count = pos;

    ListNode* head = initList(a);
    ListNode* cur = head;
    ListNode* cur2 = head;
    while (cur->next!=NULL){
        cur = cur->next;
    }
    
    if (count > -1 ){
        while (count--){
            cur2 = cur2->next;
        }
        cur->next  = cur2;
    }

    
    Solution S ;

    printLinkedList(head);

    ListNode* ans = S.detectCycle(head);
    cout << "pos = " << cur2->val << endl; 
    cout << "ans = " << ans->val << endl;


    return 0;
}

