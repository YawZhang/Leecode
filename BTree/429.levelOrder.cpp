#include<bits/stdc++.h>


using namespace std;

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        queue<Node*> q;

        if (root) q.push(root);

        Node* cur = root;

        while(!q.empty()) {
            int size = q.size();
            vector<int> lv;
            while(size--) {
                cur = q.front(); q.pop();
                lv.push_back(cur->val);
                if( cur->children.size() > 0) {
                    for (int i = 0; i < cur->children.size(); i++) {
                        q.push(cur->children[i]);
                    }
                }
            }
            res.push_back(lv);
        }
        return res;
    }
};



int main() {

    return 0;
}
