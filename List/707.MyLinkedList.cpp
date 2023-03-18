#include<bits/stdc++.h>


using namespace std;




// // 单链表方式
// class MyLinkedList_Single_linked {


// public:

// // Definition for singly-linked list.
//     struct ListNode {
//         int val;
//         ListNode *next;
//         ListNode() : val(0), next(nullptr) {}
//         ListNode(int x) : val(x), next(nullptr) {}
//         ListNode(int x, ListNode *next) : val(x), next(next) {}
//     };
// private:
//     int _size;
//     ListNode* header;
// public:
//     //默认构造
//     MyLinkedList() {
//         header = new ListNode(0);
//         _size = 0;
//     }
    
//     int get(int index) {
//         if (index < 0 || index >= _size )
//             return -1;
//         else {
//             ListNode* cur = header->next;//这个地方指向头节点，则下面index就与链表下标对应起来了

//             while (index--) {
//                 cur = cur->next;
//             }
//             return cur->val;
//         }
//     }
    
//     // 链表最前面插入一个新节点，插入完成后，新插入的节点作为链表的新的头节点
//     void addAtHead(int val) {
//         ListNode* NewNode = new ListNode(val);//创建元素为val的新节点
//         NewNode->next = header->next;//将原头节点链接在新头节点后
//         header->next = NewNode;//更新头节点
//         _size++;
//     }
    
//     void addAtTail(int val) {
//         ListNode* cur = header;
//         int size = _size;
//         while (size--) {
//             cur = cur->next;
//         }//退出循环时，cur指向最后一个节点
        
//         ListNode* NewNode = new ListNode(val);
//         cur->next = NewNode;
//         _size++;
//     }
    
//     void addAtIndex(int index, int val) {
        
//         if ( index < _size+1 && index > -1 ) {
//             ListNode* cur = header;
//             while(index--) {
//                 cur = cur->next;
//             }

//             ListNode* newNode = new ListNode(val);

//             newNode->next = cur->next;
//             cur->next = newNode;

//             _size++;
//         }
//     }
    
//     void deleteAtIndex(int index) {
//         if ( index < _size && index > -1 ) {
//             //下标有效
//             ListNode* cur = header;
//             for (int i = 0; i < index; i++) {
//                 cur = cur->next;
//             }
//             ListNode* tmp = cur->next;
//             cur->next = cur->next->next;
//             delete tmp;
//             _size--;
//         }
//     }

//     void printLinkedList() {
//         ListNode* cur = header;
//         while (cur->next != NULL) {
//             cout << cur->next->val;
//             cur = cur->next;
//         }
//         cout << endl;
//     }


// };

class MyLinkedList {


public:

// Definition for double-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode *prev;
        ListNode() : val(0), next(nullptr), prev(nullptr) {}
        ListNode(int x, ListNode *next=nullptr, ListNode *prev=nullptr) : val(x), next(next), prev(prev) {}
    };

private:
    int _size;
    ListNode* header;
    ListNode* tailer;

public:
    //默认构造
    MyLinkedList() {
        header = new ListNode(-1);
        tailer = new ListNode(-1);
        _size = 0;
        header->next = tailer;
        tailer->prev = header;
    }
    
    int get(int index) {
        if (index < 0 || index >= _size )
            return -1;
        else {
            ListNode* cur = header->next;//这个地方指向头节点，则下面index就与链表下标对应起来了

            while (index--) {
                cur = cur->next;
            }
            return cur->val;
        }
    }
    
    // 链表最前面插入一个新节点，插入完成后，新插入的节点作为链表的新的头节点
    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);//创建元素为val的新节点
        newNode->next = header->next;//将原头节点链接在新头节点后
        header->next->prev = newNode;
        header->next = newNode;
        newNode->prev = header;
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = header;
        int size = _size;
        while (size--) {
            cur = cur->next;
        }//退出循环时，cur指向最后一个节点
        
        ListNode* NewNode = new ListNode(val);
        NewNode->next = tailer;
        tailer->prev = NewNode;

        cur->next = NewNode;
        NewNode->prev = cur->next;
        _size++;
    }
    
    void addAtIndex(int index, int val) {
        
        if ( index < _size+1 && index > -1 ) {
            ListNode* cur = header;
            while(index--) {
                cur = cur->next;
            }

            ListNode* newNode = new ListNode(val);

            newNode->next = cur->next;
            cur->next->prev = newNode;

            cur->next = newNode;
            newNode->prev = cur;

            _size++;
        }
    }
    
    void deleteAtIndex(int index) {
        if ( index < _size && index > -1 ) {
            //下标有效
            ListNode* cur = header;
            for (int i = 0; i < index; i++) {
                cur = cur->next;
            }
            ListNode* tmp = cur->next;
            cur->next = tmp->next;
            tmp->next->prev = cur;
            delete tmp;
            _size--;
        }
    }

    void printLinkedList() {
        ListNode* cur = header;
        while (cur->next != tailer) {
            cout << cur->next->val;
            cur = cur->next;
        }
        cout << endl;
    }


};


int main() {

    MyLinkedList m;

    m.addAtHead(1);
    m.printLinkedList();
    m.addAtTail(3);
    m.printLinkedList();

    m.addAtIndex(1, 2);
    m.printLinkedList();
    int x = m.get(1); 
    cout << x << endl;
    m.deleteAtIndex(0);
    m.printLinkedList();

    return 0;
}
