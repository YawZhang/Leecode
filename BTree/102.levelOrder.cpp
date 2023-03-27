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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        queue<TreeNode*> q;

        if (!root) return res;

        TreeNode* cur = root;
        q.push(cur);
        while(!q.empty()) {
            int size = q.size(); // 记录当前层节点数
            vector<int> lv;
            while (size--) {
                cur = q.front(); q.pop();
                lv.push_back(cur->val); // 将当前层节点依次保存值一维数组中
                if (cur->left) q.push(cur->left);   // 将左孩子入队
                if (cur->right) q.push(cur->right); // 将右孩子入队

            }
            res.push_back(lv);
        }
        return res;
    }
};



int main() {

    return 0;
}

