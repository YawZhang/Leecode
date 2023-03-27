#include<bits/stdc++.h>


using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node* connect(Node* root) {
        queue<Node*> q;

        if (root) q.push(root);

        Node* cur = root;

        while(!q.empty()) {
            int size = q.size();

            while(size--) {
                cur = q.front(); q.pop();
                // 不能直接用q.front判断，因为队列为空的时候，这样子访问是越界的
                if (size == 0) {
                    cur->next = NULL;
                }
                else {
                    cur->next = q.front();
                }
                if(cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
        }
        return root;
    }
};



int main() {


    return 0;
}

