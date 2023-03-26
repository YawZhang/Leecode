# 栈和队列

c++  STL 有对应的AVL

- stack
- queue
- deque

## 基本概念

栈：先进后出			队列：先进先出

**c++中的栈和队列：**

- 都是容器适配器
- 我们一般使用的stack是SGI STL 版本
- SGI STL 中stack底层实现默认是以deque实现， queue也是以deque为缺省情况下实现
  - deque、list、vector都可以实现
- stack不提供迭代器来及你想遍历空间



## 232 用栈实现队列

**题目：**

请你仅使用两个栈实现先入先出队列。队列应当支持一般队列支持的所有操作（`push`、`pop`、`peek`、`empty`）：

实现 `MyQueue` 类：

- `void push(int x)` 将元素 x 推到队列的末尾
- `int pop()` 从队列的开头移除并返回元素

- `int peek()` 返回队列开头的元素
- `boolean empty()` 如果队列为空，返回 `true` ；否则，返回 `false`

说明：

- 你 **只能** 使用标准的栈操作 —— 也就是只有 `push to top`, `peek/pop from top`, `size`, 和 `is empty` 操作是合法的。

- 你所使用的语言也许不支持栈。你可以使用 list 或者 deque（双端队列）来模拟一个栈，只要是标准的栈操作即可。



**思路：**

基本的用队列实现pop, push, top

- 两个栈实现先进先出
  - 一个输入栈，一个输出栈，将属于元素顺序翻转

> tips: 实现过程要考虑

```cpp
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;

    MyQueue() {
        
    }
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        if (stOut.empty()){
            while(!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int rPop = stOut.top();
        stOut.pop();
        return rPop;
    }
    int peek() {
        int rPop = this->pop();
        stOut.push(rPop);
        return rPop;
    }
    
    bool empty() {
        return stOut.empty() && stIn.empty();
    }
};
```



## 225 用队列实现栈

**题目：**

请你仅使用两个队列实现一个后入先出（LIFO）的栈，并支持普通栈的全部四种操作（`push`、`top`、`pop` 和 `empty`）。

实现 `MyStack` 类：

- `void push(int x)` 将元素 x 压入栈顶。
- `int pop()` 移除并返回栈顶元素。

- `int top()` 返回栈顶元素。

- `boolean empty()` 如果栈是空的，返回 `true` ；否则，返回 `false` 。

**注意：**

- 你只能使用队列的基本操作 —— 也就是 `push to back`、`peek/pop from front`、`size` 和 `is empty` 这些操作。

- 你所使用的语言也许不支持队列。 你可以使用 list （列表）或者 deque（双端队列）来模拟一个队列 , 只要是标准的队列操作即可

**思路：**
受限于队列先进先出，用一个队列就可以实现先进后出的规则

- 将头n-1个元素重新入队，就能实现先进后出

两个队列实现栈，一个是输入队列，一个是备份，两个队列是题目要求，实际上我感觉不需要

```cpp
class MyStack {
public:
    queue<int> queIn;
    queue<int> queOut;

    MyStack() {

    }
    
    void push(int x) {
        queIn.push(x);
    }
    
    int pop() {
        int inSize = queIn.size();
        for (int i = 0; i < inSize-1; i++) {
            queOut.push(queIn.front());
            queIn.pop();
        }
        int rPop = queIn.front();
        queIn.pop();
        for(int i = 0; i < inSize-1; i++) {
            queIn.push(queOut.front());
            queOut.pop();
        }
        return rPop;
    }
    
    int top() {
        int rPop = this->pop();
        queIn.push(rPop);
        return rPop;
    }
    
    bool empty() {
        return queIn.empty();
    }
};
```



## 20 有效的括号

**题目：**

定一个只包括 `'('`，`')'`，`'{'`，`'}'`，`'['`，`']'` 的字符串 `s` ，判断字符串是否有效。

有效字符串需满足：

1. 左括号必须用相同类型的右括号闭合。
2. 左括号必须以正确的顺序闭合。
3. 每个右括号都有一个对应的相同类型的左括号。

**提示：**

- `1 <= s.length <= 104`
- `s` 仅由括号 `'()[]{}'` 组成

**思路：**

- 栈保存**==右==括号**，碰到**相同右括号**就弹出栈顶
- 栈保存**==左==括号**，碰到**对应右括号**，弹出栈顶

解法基本一直，我就以保存右括号所示：

考虑三种不匹配情况：

- 第一种情况，字符串里左方向的括号多余了 ，所以不匹配。
- 第二种情况，括号没有多余，但是 括号的类型没有匹配上。
- 第三种情况，字符串里右方向的括号多余了，所以不匹配。

```cpp
class Solution {
public:
//解法一：左括号入栈
    // bool isValid(string s) {
    //     stack<char> a;
    //     for ( int i = 0; i < s.size(); i++) {
    //         if (s[i] == '(' || s[i] == '[' || s[i] == '{') {
    //             a.push(s[i]);
    //         }
    //         else if (s[i] == ')') {
    //             if (a.empty() || a.top() != '(') {
    //                 return false;
    //             }
    //             a.pop();
    //         }
    //         else if (s[i] == ']') {
    //             if (a.empty() || a.top() != '[') {
    //                 return false;
    //             }
    //             a.pop();
    //         }
    //         else if (s[i] == '}') {
    //             if (a.empty() || a.top() != '{') {
    //                 return false;
    //             }
    //             a.pop();
    //         }
    //     }
    //     return a.empty()
    // }


    // 解法二：右括号入栈法
    bool isValid(string s) {
        // 边界条件控制
        if (s.size() % 2 != 0) return false;//奇数字符串大小肯定无法完成括号匹配
        stack<int> a ;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') a.push(')'); 
            else if (s[i] == '[') a.push(']'); 
            else if (s[i] == '{') a.push('}');
            else if (a.empty() || s[i] != a.top()) return false;
            else a.pop(); 
        }
        return a.empty();
    }
};
```



## 1047 删除字符串中的所有相邻的重复项

**题目：**

给出由小写字母组成的字符串` S`，**重复项删除**操作会选择两个相邻且相同的字母，并删除它们。

在 `S` 上反复执行重复项删除操作，直到无法继续删除。

在完成所有重复项删除操作后返回最终的字符串。答案保证唯一。

**提示:**

1. `1 <= S.length <= 20000`
2. `S` 仅由小写英文字母组成。

**思路：**

栈保存访问过的元素，栈顶和当前访问元素相同，栈顶弹出，否则，当前元素加入栈顶

- tips:可以用字符串当做栈进行匹配元素

```cpp
class Solution {
public:
    // 栈中存放匹配字符串，最后重置s
    // string removeDuplicates(string s) {
    //     if (s.size() == 1) return s;
        
    //     stack<char> k ;
    //     for(int i = 0; i< s.size(); i++) {
    //         if ( (k.empty()) || (s[i] != k.top())) {
    //             k.push(s[i]);
    //         }
    //         else k.pop();
    //     }
    //     if (!k.empty()) {
    //         int kSize = k.size();
    //         for (int i = kSize-1; i >= 0; i--) {
    //             s[i] = k.top();
    //             k.pop();
    //         }
    //         s.resize(kSize);
    //         return s;
    //     }
    //     else return "";
    // }

    // 用字符串作栈
    string removeDuplicates(string s) {
        string result;
        for (char c : s) {
            if ( result.empty() || c != result.back()) {
                result.push_back(c);
            }
            else result.pop_back();
        }
        return result;
    
    }
};
```

## 150 逆波兰表达式求值

**题目：**

给你一个字符串数组 `tokens` ，表示一个根据 [逆波兰表示法](https://baike.baidu.com/item/逆波兰式/128437) 表示的算术表达式。

请你计算该表达式。返回一个表示表达式值的整数。

注意：

1. 有效的算符为 '+'、'-'、'*' 和 '/' 。

2. 每个操作数（运算对象）都可以是一个整数或者另一个表达式。
3. 两个整数之间的除法总是 向零截断 。
4. 表达式中不含除零运算。
5. 输入是一个根据逆波兰表示法表示的算术表达式。
6. 答案及所有中间计算结果可以用 32 位 整数表示。

**提示：**

- `1 <= tokens.length <= 104`

- `tokens[i]` 是一个算符（`"+"`、`"-"`、`"*"` 或 `"/"`），或是在范围 `[-200, 200]` 内的一个整数

**思路：**

- 当前元素时数字，进栈
- 当前元素是算术符，弹出两次栈顶，进行算术计算

```cpp
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> nums;
        for (int i = 0; i < tokens.size(); i++){
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long nums2 = nums.top(); nums.pop();
                long long nums1 = nums.top(); nums.pop();
                
                if (tokens[i] == "+") nums.push(nums1+nums2);
                if (tokens[i] == "-") nums.push(nums1-nums2);
                if (tokens[i] == "*") nums.push(nums1*nums2);
                if (tokens[i] == "/") nums.push(nums1/nums2);
            }
            else {
                nums.push(stoll(tokens[i]));
            }
        }
        return (int)nums.top();
    }
};
```

## 239 滑动窗口最大值

**题目：**
给你一个整数数组 `nums`，有一个大小为 `k` 的滑动窗口从数组的最左侧移动到数组的最右侧。你只可以看到在滑动窗口内的 `k` 个数字。滑动窗口每次只向右移动一位。

返回 *滑动窗口中的最大值* 。

**提示：**

- `1 <= nums.length <= 105`
- `-104 <= nums[i] <= 104`
- `1 <= k <= nums.length`

**思路：**

- 首次使用到**单调队列**，使**队列中元素以单调递减形式**保存，单调栈以双向队列实现

- 单调队列需要自己写一个实现
  - pop 实现保证队列中最大值（队列头）不是滑动窗口的首元素，不然下次滑动就弹出，下一个元素就是最大值
  - push 保证当前入队元素，比前面元素都小，否则将前面元素都弹出
- 每次保存窗口最大值，即队首元素

```cpp
class MyQueue { 
public:
    deque<int> mQueue;
    int _size = 0;
    void pop(int x) {
        // 如果当前弹出的值是窗口的首元素，就将队列首值弹出
        if (!mQueue.empty() && mQueue.front() == x){
            mQueue.pop_front();
            _size--;
        }
    }
    void push(int x) {
        // 如果要插入的值比前面的值都大，就将前面的值全部pop,这样保证整个队列单调递减
        while ( !mQueue.empty() && mQueue.back() < x) {
            mQueue.pop_back();
            _size--;
        }
        mQueue.push_back(x);
        _size++;
    }
    int front () {
        return mQueue.front();
    }

};


class Solution {
public:

    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MyQueue que;
        int i = 0;
        while (i < k) {
            que.push(nums[i]);
            i++;
        }
        res.push_back(que.front());
        for (; i < nums.size(); i++) {
            que.pop(nums[i-k]);// 弹出窗口首元素
            que.push(nums[i]);// 将下一个元素插入队列中
            res.push_back(que.front()); // 保存窗口最大值
        }
        return res;
    }
};
```



## 347 前K个高频元素

**题目：**

给你一个整数数组 `nums` 和一个整数 `k` ，请你返回其中出现频率前 `k` 高的元素。你可以按 **任意顺序** 返回答案。

**提示：**

- `1 <= nums.length <= 105`

- `k` 的取值范围是 `[1, 数组中不相同的元素的个数]`

- 题目数据保证答案唯一，换句话说，数组中前 `k` 个高频元素的集合是唯一的、

**思路：**

- 开启优先级队列的学习`priority_queue`
  - 满足单向队列的所有操作
  - 里面以大顶堆或者小顶堆的比较顺序排列
  - `priority_queue<class T, contain _con, compair _com>`

- `compairison`是比较器，可以写自己写仿函数来实现比较规则

  - ```cpp
    class less {
    // 小顶堆
    	bool operator() (T& left, T& right) {
    		return left > right;
    	}
    }
    
    class greater {
    // 大顶堆
    	bool operator() (T& left, T& right) {
    		return left < right;
    	}
    }
    ```

    

```cpp
class Solution {
public:
    // 小顶堆
    class mycomparison {
    public:
        bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs ) {
            return lhs.second > rhs.second;
        }
    };// 这是为仿函数的写法


    vector<int> topKFrequent(vector<int>& nums, int k) {
        // 创建map哈希表统计所有元素出现频率
        unordered_map<int, int> m; 
        for (int i = 0; i < nums.size(); i++ ) {
            m[nums[i]]++;
        }

        // 对频率进行排序
        // 定义一个小顶堆，大小为k
        priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison> pri_que;

        // 用固定大小为k的小顶堆，扫描所有频率的数值
        for (unordered_map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
            pri_que.push(*it);//将每个元素放入堆
            if (pri_que.size() > k) {
                pri_que.pop();// 保持小顶堆大小为k
            }
        }

        vector<int> res(k);

        for ( int i = k-1; i >= 0; i--) {
            res[i] = pri_que.top().first;
            pri_que.pop();
        }


        return res;
    }
};
```

