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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> res;
        queue<TreeNode*> q;

        if (root) q.push(root);

        TreeNode* cur = root;

        while(!q.empty()) {
            int size = q.size();
            int n = size;
            int sum = 0;
            while(size--) {
                cur = q.front(); q.pop();
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
                sum += cur->val;
            }
            res.push_back((double)sum/n);
        }
        return res;
    }
};



int main() {

    return 0;
}
