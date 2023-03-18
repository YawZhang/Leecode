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
     ListNode* swapPairs(ListNode* head) {
        //尝试使用双指针法进行求解
        //当前指针和前指针
        //前进步数为2

        if (!head) return head;

        ListNode* header = new ListNode(-1);
        header->next = head;
        ListNode* cur = header;

        while (cur->next!=NULL && cur->next->next != NULL) {
            //即链表为偶数
            ListNode* next1 = cur->next;         //保存当前节点的下个节点
            ListNode* next3 = cur->next->next->next;   //保存当前节点的下下个节点

            //开始交换相邻节点位置
            cur->next = cur->next->next ; //-1节点的下一节点指向2
            cur->next->next = next1;    //2节点指向1
            cur->next->next->next = next3;        // 1节点指向3
            cur = cur->next->next; //当前节点向前走两步

        }//此时要么剩余一个尾节点有值，要么没有剩余节点

        head = header->next;//重新定义头节点
        delete header;
        
        return  head;

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

    // vector<int> a = {};
    vector<int> a = {1,2,3,4,5};


    ListNode* head = new ListNode();
    
    if ( a.size() >= 1 ){
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
    s.printLinkedList(head);
    head = s.swapPairs(head);
    s.printLinkedList(head);


    return 0;
}

