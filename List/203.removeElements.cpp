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
    ListNode* removeElements(ListNode* head, int val) {
        //解法一：单独处理头节点的方式
        //删除头节点
        while (head!=NULL && head->val == val) {
            ListNode* temp = head;//创建临时变量存储头结点
            head = head->next;//头结点移到下一节点
            delete temp;//删除原始头结点, 释放内存
        }

        //删除非头结点
        ListNode* cur = head;//备份当前节点
        while ( cur !=- NULL && cur->next != NULL) {
            //当当前节点和下一节点非空时，判断下一个节点是否满足删除要求
            //若满足，则删除下一节点，当前节点指向下下节点
            //否则，当前节点指向下一节点
            if (cur->next->val == val) {
                //如果下一节点满足删除要求
                ListNode* temp = cur->next;
                cur->next = cur->next->next;
                delete temp;//释放该节点内存
            }
            else {
                cur = cur->next;
            }
        }

        return head;

        // 解法二
        // //初始化一个前头哨兵，从而不用单独处理头节点的机制
        // //初始化哨兵
        // ListNode* header = new ListNode();
        // header->next = head;

        // //开始遍历链表，删除相应元素
        // ListNode* cur = header;
        // while (cur->next != NULL) {
        //     //由于已经有哨兵的存在，因此不用考虑头节点是否为空的时候
        //     if (cur->next->val == val) {
        //         ListNode* temp = cur->next;
        //         cur->next = cur->next->next;
        //         delete temp;
        //     }
        //     else {
        //         cur = cur->next;
        //     }
        // }
        // head = header->next;
        // delete header;
        // return head;
        
    }
};


void printList(ListNode* head) {
    ListNode* temp = head;
    while ( temp != NULL ) {
        cout << (temp->val) << " ";
        temp = temp->next;
    }
}


int main() {
    vector<int> a = {1,2,2,3,4,5};
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

    Solution S ;
    ListNode* ans = S.removeElements(head, val);
    printList(ans);


    return 0;
}
