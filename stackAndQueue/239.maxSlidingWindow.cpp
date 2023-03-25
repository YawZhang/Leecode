#include<bits/stdc++.h>


using namespace std;


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

void printVector(vector<int> a) {
    for (int i = 0; i<a.size(); i++) {
        cout << a[i] << " " ;
    }
    cout << endl << "================" << endl;
}

int main() {

    vector<int> a = {-7,-8,7,5,7,1,6,0};
    int k = 4;
    Solution S ;

    vector<int> ans = S.maxSlidingWindow(a, k);
    printVector(ans);


    return 0;
}
