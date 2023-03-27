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
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        queue<TreeNode*> q;

        if (root) q.push(root);

        TreeNode* cur = root;

        while(!q.empty()) {
            int size = q.size();
            int max = q.front()->val;
            while(size--) {
                cur = q.front(); q.pop();
                max = (max > cur->val ? max : cur->val);
                if (cur->left) q.push(cur->left);
                if (cur->right) q.push(cur->right);
            }
            res.push_back(max);
        }
        return res;
    }
};



int main() {

    return 0;
}
