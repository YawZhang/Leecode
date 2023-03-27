#include<bits/stdc++.h>


using namespace std;

class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(NULL), right(NULL) {};
    TreeNode(int x) : val(x), left(NULL), right(NULL) {};
};


class Solution {
public:
    // 解法一：递归版
    // void preorder(TreeNode* cur, vector<int>& vec) {
    //     if (cur) {
    //         // 前序遍历  中左右
    //         vec.push_back(cur->val);
    //         preorder(cur->left, vec);
    //         preorder(cur->right, vec);
            
    //     }
    // }
    // vector<int> preorderTraversal(TreeNode* root) {
    //     vector<int> res;
    //     preorder(root, res);
    //     return res;
    // }


    // 解法二：迭代法
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        stack<TreeNode*> st;

        if (root == NULL) return {};

        st.push(root);
        // 观察前序遍历可知，会沿着中左右的顺序一直遍历，即以左链方式一直遍历，因此可以使用栈来存左右子树，从而完成左链的遍历
        // 由于栈满足先进后出规则，因此需要先将中弹出，再将cur->right压入栈中，再将cur->left压入栈中
        while(!st.empty()) {
            TreeNode* cur = st.top();
            st.pop();
            res.push_back(cur->val);// 中

            if(cur->right) st.push(cur->right); // 右
            if(cur->left) st.push(cur->left);   // 左
        }
        return res;
    }
    
};



int main() {

    return 0;
}
