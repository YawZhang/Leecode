#include<bits/stdc++.h>


using namespace std;



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
        // 当输出栈为空，才将输入栈元素推入输出栈中
        // 此操作妙处在多次push，pop后，元素顺序不会打乱，且时间复杂度不变
        // 否则的话，需要增加一步将输出栈元素返回到输入栈，才能使元素顺序不变，复杂度*2
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

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */



int main() {

    MyQueue myQueue = MyQueue();
    myQueue.push(1); // queue is: [1]
    myQueue.push(2); // queue is: [1, 2] (leftmost is front of the queue)
    myQueue.peek(); // return 1
    myQueue.pop(); // return 1, queue is [2]
    myQueue.empty(); // return false


    // cout << ans ;


    return 0;
}
