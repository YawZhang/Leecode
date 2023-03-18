# LIST

## 203 移除链表元素

**题目：**给你一个链表的头节点 `head` 和一个整数 `val` ，请你删除链表中所有满足 `Node.val == val` 的节点，并返回 **新的头节点** 。

**提示：**

- 列表中的节点数目在范围 `[0, 104]` 内
- `1 <= Node.val <= 50`
- `0 <= val <= 50`

**思路：**

该题为链表基础题，考察对链表元素的访问机制及删除节点的指针链接

- 思路一： 直接删除节点

  由于头节点的存在，其与其他节点删除方式不同，需要单独考虑

  ```cpp
  while (head != NULL && head->val = val) {
  	ListNode* temp = head;
  	head = head->next;
  	delete temp;
  }
  ```

  > 这里delete 删除节点是手动释放内存，不添加不会影响leetcode提交判别，但会使内存大

  考虑其他节点删除方式，若当前节点的下一个节点是删除节点，则需将当前节点的next指针指向下下个节点，否则，当前节点后移继续判断

  > 这里需要考虑循环退出的条件
  >
  > - 由于当前节点已判断过是否为删除节点（当前节点从头节点开始）,但当输入为空列表时，需要重复判断当前节点是否为空
  > - 当前节点若为空，需退出循环, 该步仅为空列表准备的判断
  > - 当前节点的下一节点为空，退出循环

```cpp
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
```

- 思路二：初始化一个头哨兵，将头节点与其他节点删除形式保持一致

  ```cpp
  ListNode* header = new ListNode();
  header->next = head;
  ```

  下一步直接删除节点

  > 当前节点一定要从头哨兵开始，剩下过程与思路一解法一致

  ```cpp
  ListNode* cur = header;
  while (cur->next != NULL) {
  	if ( cur->next->val == val ) {
  		ListNode* tmp = cur->next;
  		cur->next = cur->next->next；
  		delete tmp;
  	}
  	esle {
  	cur = cur->next;
  	}
  }		
  ```

  

## 707 设计链表

**题目：**

你可以选择使用单链表或者双链表，设计并实现自己的链表。

单链表中的节点应该具备两个属性：`val` 和 `next` 。`val` 是当前节点的值，`next` 是指向下一个节点的指针/引用。

如果是双向链表，则还需要属性 `prev` 以指示链表中的上一个节点。假设链表中的所有节点下标从 0 开始。

实现 `MyLinkedList` 类：

- `MyLinkedList()` 初始化 `MyLinkedList` 对象。
- `int get(int index)` 获取链表中下标为 `index` 的节点的值。如果下标无效，则返回 -1 。
- `void addAtHead(int val) `将一个值为 `val `的节点插入到链表中第一个元素之前。在插入完成后，新节点会成为链表的第一个节点。
- `void addAtTail(int val)` 将一个值为`val` 的节点追加到链表中作为链表的最后一个元素。
- `void addAtIndex(int index, int val) `将一个值为 `val `的节点插入到链表中下标为 `index` 的节点之前。如果 `index` 等于链表的长度，那么该节点会被追加到链表的末尾。如果 `index` 比长度更大，该节点将 不会插入 到链表中。
- `void deleteAtIndex(int index)` 如果下标有效，则删除链表中下标为 `index` 的节点。

**提示：**

- `0 <= index`, `val <= 1000`
- 请不要使用内置的 `LinkedList` 库。
- 调用 `get`、`addAtHead`、`addAtTail`、`addAtIndex` 和 `deleteAtIndex` 的次数不超过 `2000` 。

**思路：**

创建链表节点有两种方式：

- 单链表
- 双链表
  - 注意：初始化是需要将头哨兵和尾哨兵相链接

解法一：单链表法

```cpp
// 单链表方式
class MyLinkedList_Single_linked {


public:

// Definition for singly-linked list.
    struct ListNode {
        int val;
        ListNode *next;
        ListNode() : val(0), next(nullptr) {}
        ListNode(int x) : val(x), next(nullptr) {}
        ListNode(int x, ListNode *next) : val(x), next(next) {}
    };
private:
    int _size;
    ListNode* header;
public:
    //默认构造
    MyLinkedList() {
        header = new ListNode(0);
        _size = 0;
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
        ListNode* NewNode = new ListNode(val);//创建元素为val的新节点
        NewNode->next = header->next;//将原头节点链接在新头节点后
        header->next = NewNode;//更新头节点
        _size++;
    }
    
    void addAtTail(int val) {
        ListNode* cur = header;
        int size = _size;
        while (size--) {
            cur = cur->next;
        }//退出循环时，cur指向最后一个节点
        
        ListNode* NewNode = new ListNode(val);
        cur->next = NewNode;
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
            cur->next = newNode;

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
            cur->next = cur->next->next;
            delete tmp;
            _size--;
        }
    }

    void printLinkedList() {
        ListNode* cur = header;
        while (cur->next != NULL) {
            cout << cur->next->val;
            cur = cur->next;
        }
        cout << endl;
    }


};
```

解法二：双链表法

```cpp
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
```



## 206 反转链表

**题目：**

给你单链表的头节点 `head` ，请你反转链表，并返回反转后的链表。

**提示：**

- 链表中节点的数目范围是 `[0, 5000]`
- `-5000 <= Node.val <= 5000`

**思路：**

- 双指针法
- 递归法（从前往后递归）
- 递归法（从后往前递归）

解法一：双指针法

- 创建一个prev指针指向当前节点的前一个节点
- 创建当前指针cur
- 创建一个临时指针tmp指向当前指针的下一个指针
  - 这是由于需要改变当前指针`cur`的指向，所以需要保存它的下一个节点位置

​	

```cpp
ListNode* reverseList( ListNode* head) {
	ListNode* cur = head;//初始化当前指针
    ListNode* prev = NULL;//初始化当前指针的前一个指针，即假设尾哨兵，NULL
    ListNode* tmp = NULL;
    while (cur) {
        tmp = cur->next;//保存下一节点地址
        prev = cur;//改变节点方向
        cur = tmp;//转向下一节点
    }
    return prev;
    //需要注意的是，最后退出循环时，cur为NULL，指向的假设的尾哨兵节点NULL，不存在，当实际的尾节点为prev
    //因此最后返回值为prev
}
```

解法二：递归法（从前往后递归）

> 实际就是双指针法，不过写成了递归形式

```cpp
ListNode* reverse (ListNode* cur, ListNode* prev) {
    if (cur==NULL) return prev;
    ListNode* tmp = cur->next;
    cur->next = prev;
    prev = cur;
    reverse(tmp, prev);
}


ListNode* reverseList(ListNode* head) {
	ListNode* prev = NULL;
    return reverse(head, prev)
}

```

解法三：递归法（从后往前法）

- 首先判断边界条件
  - 链表为空
  - 当前指针已到末尾
  - return 当前指针
- 将指针以递归的方式指向末节点，返回最终的last指针
- 递归反转节点方向

```cpp
ListNode* reverseList(ListNode* head) {
	if (head==NULL || head->next == NULL) retrun head;
    ListNode* last = reverseList(head->next);
    head->next->next = head;//反转节点方向
    head->next = NULL;
    return last;
}
```



## 24 两两交换链表中的节点

**题目：**

给你一个链表，两两交换其中相邻的节点，并返回交换后链表的头节点。==你必须在不修改节点内部的值的情况下完成本题（即，只能进行节点交换）。==

**提示：**

- 链表中节点的数目在范围 `[0, 100]` 内
- `0 <= Node.val <= 100`

**思路：**

- 迭代法，创建头节点哨兵，使用三次改变方向来完成交换 `-1->2->1->3`

- 递归法，不创建头节点，通过递归返回`2->1->`的后面节点

解法一：

```cpp
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
```

解法二：递归法

- 先判断递归终止条件
  - 即当前节点为空或当前节点的下一节点为空，返回当前节点
- 开始递归，每次递归返回的节点作为`head->next->next`的节点
  - 注意：此时的head为最终返回的head值，而不是原head值
  - 递归输入为head的第三个节点
  - 这是最重要的一步：`head->next = swapPairs(tmp->next);`

```cpp
ListNode* swapPairs(ListNode* head) {
		//递归的终止条件
		if(head == NULL || head->next == NULL) {
			return head;
		}
		//假设链表是 1->2->3->4
		//这句就先保存节点2
		ListNode* tmp = head->next;
    
		//继续递归，处理节点3->4
		//当递归结束返回后，就变成了4->3
		//于是head节点就指向了4，变成1->4->3
		head->next = swapPairs(tmp->next);//这是最重要的一步
    
		//将2节点指向1
		tmp->next = head;
		return tmp;
```

