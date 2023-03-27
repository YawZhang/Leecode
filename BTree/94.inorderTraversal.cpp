#include<bits/stdc++.h>


using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL)  {};
};


class Solution {
public:
    // // 解法一：递归实现
    // void traversal(TreeNode* cur, vector<int>& vec) {
    //     if (cur == NULL) return ;
        
    //     // 中序遍历 左中右
    //     traversal(cur->left, vec);
    //     vec.push_back(cur->val);
    //     traversal(cur->right, vec);
    // }

    // vector<int> inorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     traversal(root, res);
    //     return res;
    // }

    // 解法二：迭代实现
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        TreeNode* cur = root;
        while( cur!= NULL || !st.empty()) {
            if(cur!=nullptr){
                st.push(cur);
                cur = cur->left;
            }
            else{
                cur = st.top();
                st.pop();
                res.push_back(cur->val);
                cur = cur->right;
            }
        }
        return res;
    }
};



int main() {
    return 0;
}

