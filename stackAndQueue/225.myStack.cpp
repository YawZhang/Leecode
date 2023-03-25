#include<bits/stdc++.h>


using namespace std;



class MyStack {
public:
    queue<int> queIn;
    queue<int> queOut;//备份

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



int main() {
    MyStack myStack = MyStack();
    myStack.push(1);
    myStack.push(2);
    myStack.push(3);
    int mtop = myStack.top(); // 返回 2
    int mypop = myStack.pop(); // 返回 2
    bool myempty = myStack.empty(); // 返回 False

    


    return 0;
}
